/*
 *        File: ProjectNarwhal.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Main function for project narwhal
 * ----------------------------------------------------------------
 *    Revision:
 *		09152015 - NRD - Initial Version
 *      08242019 - GAI - Added version date to boot screen
 * ----------------------------------------------------------------
 */


// include the library code:
#include "Main.h"

//typedef FastDelegate2<int, char *> EvtHandler;
unsigned long BootScreenTime = 0;
bool firstpass = true;

void setup() {
	
	//Setup Analog for External
	//analogReference(EXTERNAL);
	
	//Setup the Hardware
	Serial.begin(115200);      // open the serial port at 115200 bps:
	
	//Print out the version
	Serial.println(F("*************************************"));
	Serial.println(F("  Project Narwhal Estd. 2015         "));
	Serial.println(F("*************************************"));
	Serial.print(F("  Version: "));
	Serial.println(VERSION);
	Serial.println(F(""));
	Serial.flush();
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println(F("-INITIALIZING-"));
	#endif
	
	//Initialize Hardware
	Serial.print(F("Free Bytes: "));
	Serial.println(freeMemory());
	Serial.flush();
	
	hardware_init();
	
	//Report free memory after initialization

	UI_MAIN::UI_init();
	Serial.flush();
	UI_HLT::UI_init();
	UI_MLT::UI_init();
	UI_BK::UI_init();

	//Display the Boot screens	
	BootScreenTime = millis();
	
	MAIN_LCD.clear();
	MAIN_LCD.setCursor(3,1);
	MAIN_LCD.print("Narwhal v");
	MAIN_LCD.print(VERSION);
	MAIN_LCD.setCursor(5,2);	
	MAIN_LCD.print(VERSIONDATE);
	MAIN_LCD.setCursor(2,3);
	MAIN_LCD.print("Established 2015");	
	
	HLT_LCD.clear();
	HLT_LCD.setCursor(2,1);
	HLT_LCD.print("Hot Liquor Tank");
	MLT_LCD.clear();	
	MLT_LCD.setCursor(2,1);
	MLT_LCD.print("Mash/Lauter Tun");
		
	BK_LCD.clear();
	BK_LCD.setCursor(2,1);
	BK_LCD.print("Boil Kettle");
		
	//Report free memory after initialization
	Serial.print(F("Free Bytes: "));
	Serial.println(freeMemory());
}

void loop() {

	//On first pass print out a verbose message
	if(firstpass){
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
			Serial.println(F(""));
			Serial.println(F("-MAIN-PROGRAM-"));
		#endif
		
		//Make sure boot screens display for atleast 3 seconds (3000ms)
		while((millis()-BootScreenTime)<3000){
			//Wait
			delay(500);
		}
		
		//Clear the Displays
		UI_MAIN::UI->refresh();
		UI_HLT::UI->refresh();
		UI_MLT::UI->refresh();
		UI_BK::UI->refresh();
	}
	firstpass = false;
	
	//Run the Executive
	Exec.run();
	//Logger().log();
}


