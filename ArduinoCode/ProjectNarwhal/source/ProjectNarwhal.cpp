/*
 *        File: ProjectNarwhal.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Main function for project narwhal
 * ----------------------------------------------------------------
 *    Revision:
 *		09152015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */
 
#include "mariamole_auto_generated.h"

// include the library code:
#include <Arduino.h>
#include <Wire.h>
#include "Hardware.h"
#include "Executive.h"

//Main Executive (Hardware is defined in hardware.h)
Executive *Exec;
Hardware *_HW;

void setup() {
	//Setup the Hardware
	_HW = new Hardware();
	_HW->init();
	
	Exec = new Executive();
}

void loop() {
	Exec->run();
}


