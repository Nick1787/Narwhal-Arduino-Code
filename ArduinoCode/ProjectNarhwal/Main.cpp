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
#include "include/FastDelegate/FastDelegate.h"
#include "include/FastDelegate/FastDelegateBind.h"
#include "iodef.h"
#include "config.h"
#include "classes/MAIN/MAIN_UI.h"
#include "classes/MLT/MLT_UI.h"
#include "classes/HLT/HLT_UI.h"

//typedef FastDelegate2<int, char *> EvtHandler;
unsigned long BootScreenTime = 0;
bool firstpass = true;

Executive *Exec = new Executive();

void setup() {
	//Setup the Hardware
	Serial.begin(9600);      // open the serial port at 9600 bps:
	
	//Print out the version
	Serial.println("*************************************");
	Serial.println("  Project Narwhal Estd. 2015         ");
	Serial.println("*************************************");
	Serial.print("  Version: ");
	Serial.println(VERSION);
	Serial.println("");
		
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println("-INITIALIZING-");
	#endif
	
	//Initialize Hardware
	hardware_init();

	//Display the Boot screens	
	BootScreenTime = millis();
	
	MAIN_LCD.setCursor(3,1);
	MAIN_LCD.print("Narwhal v");
	MAIN_LCD.print(VERSION);
	MAIN_LCD.setCursor(2,2);
	MAIN_LCD.print("Established 2015");
		
	HLT_LCD.setCursor(2,1);
	HLT_LCD.print("Hot Liquor Tank");
		
	MLT_LCD.setCursor(2,1);
	MLT_LCD.print("Mash/Lauter Tun");
		
	BK_LCD.setCursor(2,1);
	BK_LCD.print("Boil Kettle");

	//Initialize the rest of the programs
	MAIN_UI_init();
	HLT_UI_init();
	MLT_UI_init();
	delay(3000);
}

void loop() {
	
	//On first pass print out a verbose message
	if(firstpass){
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
			Serial.println("-MAIN-PROGRAM-");
		#endif
	}
	firstpass = false;
	
	//Make sure boot screens display for atleast 3 seconds (3000ms)
	while((millis()-BootScreenTime)<3000){
		//Wait
		delay(500);
	}
	
	//Run the Executive
	Exec->run();
}


