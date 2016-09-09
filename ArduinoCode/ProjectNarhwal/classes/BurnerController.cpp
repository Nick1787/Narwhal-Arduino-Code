/*
 *        File: BuernerController.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Project Narwhal Burner Controller
 * ----------------------------------------------------------------
 *    Revision:
 *		09152015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "BurnerController.h"

// default constructor
BurnerController::BurnerController(bool *PilotRef, WheatstoneBridge *BP, WheatstoneBridge *OP, DigitalIO *Sol1, DigitalIO *Sol2)
{
	PilotLitRef = PilotRef;
	TProbe1 = BP;
	TProbe2 = OP;
	GasValve1 = Sol1;
	GasValve2 = Sol2;
} //BurnerController

// default destructor
BurnerController::~BurnerController()
{
} //~BurnerController
