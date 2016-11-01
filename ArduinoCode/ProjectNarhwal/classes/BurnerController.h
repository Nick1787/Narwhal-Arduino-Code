/*
 *        File: BuernerController.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Project Narwhal Burner Controller
 * ----------------------------------------------------------------
 *    Revision:
 *		09152015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#ifndef __BURNERCONTROLLER_H__
#define __BURNERCONTROLLER_H__

#include "Hardware.h"
#include "../ListsAndAdjustments.h"
#include "WheatstoneBridge.h"
#include "EZUI/EZUI.h"
#include "EnhancedTypes/DigitalIO.h"
#include "EnhancedTypes/AdjustableParam.h"
#include "EnhancedTypes/ListOption.h"

//Forward Declaration (Linker wasnt finding these, not sure why, adding a forward declaration)
extern WheatstoneBridge HLT_RTD_BP;
extern WheatstoneBridge HLT_RTD_OP;
extern WheatstoneBridge MLT_RTD_BP;
extern WheatstoneBridge MLT_RTD_OP;
extern WheatstoneBridge BK_RTD_BP;
extern WheatstoneBridge BK_RTD_OP;

class BurnerController
{
//variables
private:

public:	
	//Error Limits
	float ControlError = 0;

	//Adjustable Parameters for UI
	AdjustableParam * SetTemp;
	AdjustableParam * HighErrLim;
	AdjustableParam * OffErrLim;
	AdjustableParam * HighErrHys;
	AdjustableParam * OffErrHys;
	
	//Feedback
	WheatstoneBridge * TProbe1 = NULL;
	WheatstoneBridge * TProbe2 = NULL;
	
	//Output
	DigitalIO *GasValve1 = NULL;
	DigitalIO *GasValve2 = NULL;
	
	//Options
	boolean ControlEnabled = false;
	ListOption<EnumBurnerModes> Mode;
	ListOption<EnumBurnerStatus> Status;
	ListOption<EnumFeedbackProbes> FeedbackProbe;
	
protected:
private:
	bool *PilotLitRef = NULL;
	
//functions
public:
	BurnerController(bool *PolotLit, WheatstoneBridge *BP, WheatstoneBridge *OP, DigitalIO *Sol1, DigitalIO *Sol2, AdjustableParam * Set, AdjustableParam *HighErr, AdjustableParam *OffErr, AdjustableParam *HighHys, AdjustableParam *OffHys): 
		PilotLitRef(PolotLit), TProbe1(BP), TProbe2(OP), GasValve1(Sol1), GasValve2(Sol2),
		SetTemp(Set), HighErrLim(HighErr), OffErrLim(OffErr), HighErrHys(HighHys), OffErrHys(OffHys),
		Mode(A(BurnerModes)), Status(A(BurnerStatus)), FeedbackProbe(A(FeedbackProbes))
		{
			Mode.setValue(EnumBurnerModes::Off);
	} //BurnerController;
	~BurnerController(){};
	
	void Exec(){
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
						/* Transtion to Off Mode */
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
protected:
private:

}; //BurnerController

#endif //__BURNERCONTROLLER_H__
