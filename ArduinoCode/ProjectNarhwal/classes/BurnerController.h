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

#include "WheatstoneBridge.h"
#include "EnhancedIO/DigitalIO.h"

class BurnerController
{
//variables
public:	
	//Error Limits
	float error = 0;
	float TargetTemp = 0;
	float HighErrLim = -5;
	float LowErrLim = -2;
	float OffErrLim = 0;
	
	//Feedback
	WheatstoneBridge * TProbe1 = NULL;
	WheatstoneBridge * TProbe2 = NULL;
	boolean useBP = true;				//True = BP, False = OP
	
	//Output
	DigitalIO *GasValve1 = NULL;
	DigitalIO *GasValve2 = NULL;
	
	enum Prob{
		BP = 0,
		OP = 1,	
	};
	
	enum Mode{
		Off = 0,
		Manual = 1,
		Auto = 2,	
	};
	
	//Status
	enum Status {
		PilotOff = 0,
		PilotLit = 1, 
		Sol1Fire = 2, 
		Sol2Fire = 3, 
		Sol1andSol2Fire = 4, 
		Fault = -1 
	};
	
	void setMode(Mode mde );
	//void exex();
	
protected:
private:
	bool *PilotLitRef = NULL;
	
//functions
public:
	BurnerController(bool *PolotLit, WheatstoneBridge *BP, WheatstoneBridge *OP, DigitalIO *Sol1, DigitalIO *Sol2);
	~BurnerController();
	
protected:
private:

}; //BurnerController

#endif //__BURNERCONTROLLER_H__
