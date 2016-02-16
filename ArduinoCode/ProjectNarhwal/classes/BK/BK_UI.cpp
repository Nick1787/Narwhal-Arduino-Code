/*
 *        File: BK_UI.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: HLT display user interface
 * ----------------------------------------------------------------
 *    Revision:
 *		01012015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "BK_UI.h"

EZUI *BK_UI = new EZUI("BK");

void BK_UI_init(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.print("Initializing UI - " + BK_UI->Name + "...");
	#endif
	
	/***************************************
	  Setup + Initialization
	***************************************/
	BK_UI->attatchEncoder(BK_ENC);
	BK_UI->attatchLCD(&BK_LCD);
	
	EZUI_Menu * MainMenu = new EZUI_Menu("BK-Main-Menu");
	
	EZUI_Page * TestPage = new EZUI_Page((String)("TestPage"));
	//TestPage->addItem(new EZUI_PageItem(0,3,new EZUI_Control_Link("Back",MainMenu)));
	
	MainMenu->addItem(new EZUI_Control_Link("TestPage",TestPage));
	MainMenu->addItem(new EZUI_Control_Link("Test2",MainMenu));
	/***************************************
	  Diagnostics Page
	***************************************/
	
	/***************************************
	  BK Menu
	***************************************/
	BK_UI->setDisplay(MainMenu);
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println("Done.");
	#endif
}
