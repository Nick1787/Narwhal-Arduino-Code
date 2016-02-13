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
#include "DigitalIO.h"

class BurnerController
{
//variables
public:
	String Name = "";
	String Status = "";
	
	//Error Limits
	float TargetTemp = 0;
	float HighErrLim = -5;
	float LowErrLim = -2;
	float OffErrLim = 0;
	
	//Feedback
	WheatstoneBridge * TProbe1 = NULL;
	WheatstoneBridge * TProbe2 = NULL;
	
	//Output
	DigitalIO *GasValve1 = NULL;
	DigitalIO *GasValve2 = NULL;
	
	//Status
	enum Status {PilotOff, PilotLit, Sol1Fire, Sol2Fire, Sol1andSol2Fire, Fault};
		
protected:
private:
	
//functions
public:
	
	BurnerController();
	~BurnerController();
	
protected:
private:

}; //BurnerController

#endif //__BURNERCONTROLLER_H__
