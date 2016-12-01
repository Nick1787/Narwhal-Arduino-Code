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
	WheatstoneBridge * TProbe1;
	WheatstoneBridge * TProbe2;
	
	//Output
	DigitalIO *GasValve1;
	DigitalIO *GasValve2;
	
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
	//Constructor
	BurnerController(bool *PolotLit, WheatstoneBridge *BP, WheatstoneBridge *OP, DigitalIO *Sol1, DigitalIO *Sol2, AdjustableParam * SetT, AdjustableParam * HErrHys, AdjustableParam * HErrLim, AdjustableParam * OErrHys, AdjustableParam *OErrLim): 
		PilotLitRef(PolotLit), TProbe1(BP), TProbe2(OP), GasValve1(Sol1), GasValve2(Sol2),
		Mode(A(BurnerModes)), Status(A(BurnerStatus)), FeedbackProbe(A(FeedbackProbes)),
		SetTemp(SetT), HighErrHys(HighErrHys), HighErrLim(HErrLim), OffErrHys(OErrHys), OffErrLim(OErrLim)
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
