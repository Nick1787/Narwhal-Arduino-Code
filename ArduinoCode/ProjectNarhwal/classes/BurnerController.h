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

#include "../Main.h"

class BurnerController
{
//variables
private:
	int PWMOnTime;
	
public:	
	//Error Limits
	boolean enableFaultInhibit = false;
	boolean isFaulted = false;
	
	float ControlError = 0;
	float FeedbackTemp = 0;
	
	//PWMController - Adjustable Parameters for UI
	ListOption<EnumPWMLevels> PWMLevel;
	AdjustableParam * PWMPeriod;
	AdjustableParam * PWMDutyCycle;
	
	//AutoController - Adjustable Parameters
	AdjustableParam * SetTemp;
	AdjustableParam * HighOffset;
	AdjustableParam * MediumOffset;
	AdjustableParam * LowOffset;
	AdjustableParam * Hysteresis;
	
	//Feedback
	WheatstoneBridge * TProbe1;
	WheatstoneBridge * TProbe2;
	
	//Output
	DigitalIO *GasValve_Low;
	DigitalIO *GasValve_High;
	
	//Options
	boolean ControlEnabled = false;
	ListOption<EnumBurnerModes> Mode;
	ListOption<EnumBurnerStatus> Status;
	ListOption<EnumFeedbackProbes> FeedbackProbe;
	
protected:
private:
	bool *PilotLitRef = NULL;
	void runAuto();
	void runPWM();
	
//functions
public:
	//Constructor
	BurnerController(bool *PilotLit, WheatstoneBridge *BP, WheatstoneBridge *OP, DigitalIO *Sol1, DigitalIO *Sol2, AdjustableParam * SetT, AdjustableParam * HOffset, AdjustableParam * MOffset, AdjustableParam * LOffset, AdjustableParam *Hys, AdjustableParam * PwmP, AdjustableParam *PwmD): 
		PilotLitRef(PilotLit), TProbe1(BP), TProbe2(OP), GasValve_Low(Sol1), GasValve_High(Sol2),
		Mode(A(BurnerModes)), Status(A(BurnerStatus)), FeedbackProbe(A(FeedbackProbes)), 
		SetTemp(SetT), HighOffset(HOffset), MediumOffset(MOffset), LowOffset(LOffset), Hysteresis(Hys) ,
		PWMPeriod(PwmP), PWMDutyCycle(PwmD), PWMLevel(A(PWMLevels))
	{
		Mode.setValue(EnumBurnerModes::Off);
	} 
	
	//Destructor
	~BurnerController(){};
	
	//Exec
	void Exec();
protected:
private:

}; //BurnerController

#endif //__BURNERCONTROLLER_H__
