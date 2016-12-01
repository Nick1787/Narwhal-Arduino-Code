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
	boolean Faulted = false;
	
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
	
	if( FB->Faulted == true){
		Status.setValue(EnumBurnerStatus::FeedbackFault);
		ControlError=-99;
		Faulted = true;
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
		GasValve1->Write(1);
		GasValve2->Write(1);
		}else{
		if(*PilotLitRef == false){
			Status.setValue(EnumBurnerStatus::PilotFault);
			Faulted = true;
		}
	}
	
	
	//Auto Control Mode
	if(Mode.currentValue() == EnumBurnerModes::Auto){
		if(Faulted){
			GasValve1->Write(1); //Off
			GasValve2->Write(1); //Off
			}else{
			//It burner currently in high mode?
			if((GasValve1->Value() == 0) && (GasValve2->Value() == 0)){
				
				// *** In High Mode ***/
				
				//Check if TRansition to Another Mode
				if( ControlError > HighErrHys->getValue()){
					/*Do Nothing, Stay in High Mode */
					}else if(ControlError > OffErrHys->getValue()){
					/* TRansition to Low Mode */
					GasValve1->Write(0);	//On
					GasValve2->Write(1); //Off
					}else{
					/* Transition to Off Mode */
					GasValve1->Write(1);	//Off
					GasValve2->Write(1); //Off
				}
				}else if((GasValve1->Value() == 0) || (GasValve2->Value() == 1)){
				
				// *** In Low Mode ***/
				
				//Check if TRansition to Another Mode
				if( ControlError > (HighErrLim->getValue() + HighErrHys->getValue())){
					/* TRansition to High Mode */
					GasValve1->Write(0); //On
					GasValve2->Write(0); //On
					}else if(ControlError > OffErrLim->getValue()){
					/* Do Nothing Stay in Low Mode */
					}else{
					/* Transtion to Off Mode */
					GasValve1->Write(1);	//Off
					GasValve2->Write(1); //Off
				}
				}else if((GasValve1->Value() == 1) || (GasValve2->Value() == 1)){
				
				// *** In Off Mode ***/
				
				//Check if TRansition to Another Mode
				if( ControlError > (HighErrLim->getValue() + HighErrHys->getValue())){
					/* TRansition to High Mode */
					GasValve1->Write(0);	//On
					GasValve2->Write(0); //On
					}else if(ControlError > (OffErrLim->getValue() + OffErrHys->getValue())){
					/* Transition to Low Mode */
					GasValve1->Write(0);	//On
					GasValve2->Write(1); //Off
					}else{
					/* Do Nothing Stay Off */
				}
			}
		}
	}
}