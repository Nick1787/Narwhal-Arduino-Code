/*
 * BurnerController.cpp
 *
 * Created: 11/24/2016 6:57:18 PM
 *  Author: Nick1
 */ 

#include "BurnerController.h"

void BurnerController::Exec(){
	//Store the last controller error
	float LastErr = ControlError;
	isFaulted = false;
	Status.setValue(EnumBurnerStatus::PilotLit);
	
	//Check Feedback Error to Active Probe
	WheatstoneBridge *FB = NULL;
	switch(FeedbackProbe.currentValue()){
		case(EnumFeedbackProbes::HLTBP):
			FB = &HLT_RTD_BP;
			break;
		case(EnumFeedbackProbes::HLTOP):
			FB = &HLT_RTD_OP;
			break;
		case(EnumFeedbackProbes::MLTBP):
			FB = &MLT_RTD_BP;
			break;
		case(EnumFeedbackProbes::MLTOP):
			FB = &MLT_RTD_OP;
			break;
		case(EnumFeedbackProbes::BKBP):
			FB = &BK_RTD_BP;
			break;
		case(EnumFeedbackProbes::BKOP):
			FB = &BK_RTD_OP;
			break;
		
		default:
			//Shouldnt ever reach Here, Report Error and REturn
			#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
				Serial.println(F("ERROR! Invalid Feedback Probe for Burner Controller"));
			#endif
			return;
			break;
	}
	FeedbackTemp = FB->degF;
	
	if( FB->isFaulted == true){
		Status.setValue(EnumBurnerStatus::FeedbackFault);
		ControlError=-99;
		if( Mode.currentValue() == EnumBurnerModes::Auto){
			isFaulted = true;
		}
	}else{
		ControlError = SetTemp->getValue() - FB->degF;
	}

	
	//Check that the Pilot light is lit
	if(Mode.currentValue() == EnumBurnerModes::Off){
		if(*PilotLitRef == false){
			Status.setValue(EnumBurnerStatus::PilotOff);
		}else{
			Status.setValue(EnumBurnerStatus::PilotLit);
		}
		
		//Disable the output solenoids (High == Off)
		GasValve_Low->Write(1);
		GasValve_High->Write(1);
	}else{
		if(*PilotLitRef == false){
			Status.setValue(EnumBurnerStatus::PilotFault);
			if( (Mode.currentValue() == EnumBurnerModes::Auto) || (Mode.currentValue() == EnumBurnerModes::PWM)){
				if( !enableFaultInhibit){
					isFaulted = true;
				}
			}
		}
	}
	
	
	//Auto Control Mode
	if(Mode.currentValue() == EnumBurnerModes::Auto){
		runAuto();
		
		//Set PWMOnTime to -1 to reset the PWM Timer
		PWMOnTime = -1;
	}else if(Mode.currentValue() == EnumBurnerModes::PWM){
		//Keep Track if starting a new session
		if( PWMOnTime < 0){
			PWMOnTime = millis();
		}
		runPWM();
	}
}

void BurnerController::runPWM(){
	//See how far into a period we are
	float millisecondsIntoPeriod = ( PWMOnTime % (int)(1000*PWMPeriod->getValue()) );
	float pctIntoPeriod = 100*( (float)millisecondsIntoPeriod / PWMPeriod->getValue() );
	
	if(pctIntoPeriod <= PWMDutyCycle->getValue()){
		//The PWM is On, so just set the level now
		if(PWMLevel.currentValue() == EnumPWMLevels::Low){
			GasValve_Low->Write(0);
			GasValve_High->Write(1);
		}else if(PWMLevel.currentValue() == EnumPWMLevels::Medium){
			GasValve_Low->Write(1);
			GasValve_High->Write(0);
		}else if(PWMLevel.currentValue() == EnumPWMLevels::High){
			GasValve_Low->Write(0);
			GasValve_High->Write(0);
		}else{
			GasValve_Low->Write(1);
			GasValve_High->Write(1);
		}
	}
	
}

void BurnerController::runAuto(){
	if(isFaulted && !enableFaultInhibit){
		GasValve_Low->Write(1); //Off
		GasValve_High->Write(1); //Off
	}else{
		//It burner currently in high mode?
		if((GasValve_Low->Value() == 0) && (GasValve_High->Value() == 0)){
				// *** In High Mode ***/
			
				//Check if TRansition to Another Mode
				if( ControlError > HighOffset->getValue()){
					/*Do Nothing, Stay in High Mode */
					}else{
					/* TRansition to Medium Mode */
					GasValve_Low->Write(1);  //Off
					GasValve_High->Write(0); //On
				
					#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
					Serial.println(F("  Controller High-To-Medium  Transition"));
					#endif
				}
				}else if((GasValve_Low->Value() == 1) && (GasValve_High->Value() == 0)){
			
				// *** In Medium Mode ***/
			
				//Check if TRansition to Another Mode
				if( ControlError > (HighOffset->getValue() + Hysteresis->getValue())){
					/* TRansition to High Mode */
					GasValve_Low->Write(0);  //On
					GasValve_High->Write(0); //On
				
					#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
					Serial.println(F("  Controller Medium-To-High Transition"));
					#endif
					}else if(ControlError > MediumOffset->getValue()){
					/* Do Nothing Stay in Medium Mode */
					}else{
					/* Transition to Low Mode */
					GasValve_Low->Write(0);  //Off
					GasValve_High->Write(1); //On
				
					#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
					Serial.println(F("  Controller Medium-To-Low Transition"));
					#endif
				}
				}else if((GasValve_Low->Value() == 0) && (GasValve_High->Value() == 1)){
			
				// *** In Low Mode ***/
			
				//Check if TRansition to Another Mode
				if(ControlError > (MediumOffset->getValue() + Hysteresis->getValue())){
					/* Transition to Medium Mode */
					GasValve_Low->Write(1);  //Off
					GasValve_High->Write(0); //On
				
					#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
					Serial.println(F("  Controller Low-To-Medium Transition"));
					#endif
					}else if(ControlError > LowOffset->getValue()){
					/* Do Nothing Stay in Low Mode */
					}else{
					GasValve_Low->Write(1);  //Off
					GasValve_High->Write(1); //Off
				
					#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
					Serial.println(F("  Controller Low-To-Off Transition"));
					#endif
				}
				}else if((GasValve_Low->Value() == 1) && (GasValve_High->Value() == 1)){
			
				// *** In Off Mode ***/
			
				//Check if TRansition to Another Mode
				if( ControlError > (LowOffset->getValue() + Hysteresis->getValue())){
					/* TRansition to Low Mode */
					GasValve_Low->Write(0);  //On
					GasValve_High->Write(1); //Off
				
					#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
					Serial.println(F("  Controller Off-To-Low Transition"));
					#endif
					}else{
					/* Do Nothing Stay Off */
				}
			}
				}
}