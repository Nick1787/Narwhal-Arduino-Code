/*
 *        File: ProjectNarwhal.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Main function for project narwhal
 * ----------------------------------------------------------------
 *    Revision:
 *		09152015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

// include the library code:
#include <Arduino.h>
#include "classes/Executive.h"
#include "classes/Hardware.h"

//Main Executive (Hardware is defined in hardware.h)
Executive *Exec;

void setup() {
	//Setup the Hardware
	//init_hardware();
	Serial.begin(9600);      // open the serial port at 9600 bps:

	//Create a new Executive
	Exec = new Executive();
	
	HLT_LCD.begin(20,4);
	HLT_LCD.setBacklight(HIGH);
	
	HLT_LCD.setCursor(0, 0);
	HLT_LCD.print("Project Narwhal.");
	delay(3000);
	HLT_LCD.print("HLT.");
	//HLT_UI->display();
}

void loop() {
	
	//Run the Executive
	//Exec->run();
	//float num = 5.0;
	//HLT_UI->display();
	
	//Serial.println("Running...");
}


