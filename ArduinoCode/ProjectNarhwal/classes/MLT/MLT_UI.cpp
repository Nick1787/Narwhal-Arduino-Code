/*
 *        File: MLT_UI.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: MLT display user interface
 * ----------------------------------------------------------------
 *    Revision:
 *		01012015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "MLT_UI.h"

UserInterface *MLT_UI = new UserInterface("MLT");

void MLT_UI_init(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.print("Initializing UI - " + MLT_UI->Name + "...");
	#endif
	
	/***************************************
	  Setup + Initialization
	***************************************/
	MLT_UI->attatchEncoder(MLT_ENC);
	MLT_UI->attatchLCD(&MLT_LCD);
		
	/***************************************
	  Diagnostics Page
	***************************************/
	
	/***************************************
	  MLT Menu
	***************************************/
	LCDMenu * MLTMainMenu = new LCDMenu("MAIN-MENU");
	LCDMenuItem * TestItem1 = new LCDMenuItem("Testing1");
	MLTMainMenu->Items.add(*TestItem1);
	LCDMenuItem * TestItem2 = new LCDMenuItem("Testing2");
	MLTMainMenu->Items.add(*TestItem2);
	LCDMenuItem * TestItem3 = new LCDMenuItem("Testing3");
	MLTMainMenu->Items.add(*TestItem3);
		
	MLT_UI->setDisplay(MLTMainMenu);
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println("Done.");
	#endif
}
