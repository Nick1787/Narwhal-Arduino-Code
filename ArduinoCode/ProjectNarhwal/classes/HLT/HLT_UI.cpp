/*
 *        File: HLT_UI.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: HLT display user interface
 * ----------------------------------------------------------------
 *    Revision:
 *		01012015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "HLT_UI.h"

UserInterface *HLT_UI = new UserInterface("HLT");

void HLT_UI_init(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.print("Initializing UI - " + HLT_UI->Name + "...");
	#endif
	
	/***************************************
	  Setup + Initialization
	***************************************/
	HLT_UI->attatchEncoder(HLT_ENC);
	HLT_UI->attatchLCD(&HLT_LCD);
		
	/***************************************
	  Diagnostics Page
	***************************************/
	
	/***************************************
	  HLT Menu
	***************************************/
	LCDMenu * HLTMainMenu = new LCDMenu("MAIN-MENU");
	LCDMenuItem * TestItem1 = new LCDMenuItem("Testing1");
	HLTMainMenu->Items.add(*TestItem1);
	LCDMenuItem * TestItem2 = new LCDMenuItem("Testing2");
	HLTMainMenu->Items.add(*TestItem2);
	LCDMenuItem * TestItem3 = new LCDMenuItem("Testing3");
	HLTMainMenu->Items.add(*TestItem3);
	
	HLT_UI->setDisplay(HLTMainMenu);
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println("Done.");
	#endif
}
