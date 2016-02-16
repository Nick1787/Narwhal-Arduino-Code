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

EZUI *HLT_UI = new EZUI("HLT");

void HLT_UI_init(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.print("Initializing UI - " + HLT_UI->Name + "...");
	#endif
	
	/***************************************
	  Setup + Initialization
	***************************************/
	HLT_UI->attatchEncoder(HLT_ENC);
	HLT_UI->attatchLCD(&HLT_LCD);
	
	EZUI_Menu * MainMenu = new EZUI_Menu("HLT-Main-Menu");
	
	EZUI_Page * TestPage = new EZUI_Page((String)("TestPage"));
	//TestPage->addItem(0,3,new EZUI_Control_Link("Back",MainMenu));
	
	MainMenu->addItem(new EZUI_Control_Link("TestPage",TestPage));
	MainMenu->addItem(new EZUI_Control_Link("Test2",MainMenu));
	
	/***************************************
	  Monitor Page
	**************************************
	EZUI_Page *MonitorPage = new EZUI_Page("Monitor");
	MonitorPage->addItem(new EZUI_PageItem(0,0,&HLT_UI->Name));
	MonitorPage->addItem(new EZUI_PageItem(3,0,(String)":"));
	MonitorPage->addItem(new EZUI_PageItem(4,0,(String)"Dummy Status"));
	MonitorPage->addItem(new EZUI_PageItem(1,0, new EZUI_Control_ToggleOption("Sol#1:", HLT_SOL1)));
	MonitorPage->addItem(new EZUI_PageItem(1,11, new EZUI_Control_ToggleOption("Sol#1:", HLT_SOL2)));
	MonitorPage->addItem(new EZUI_PageItem(2,0,new String("BP=XXX F")));
	MonitorPage->addItem(new EZUI_PageItem(2,12,new String("OP=XXX F")));
	MonitorPage->addItem(new EZUI_PageItem(3,0,new EZUI_Control_Link("Back",MainMenu)));
	
	/***************************************
	  Settings Page
	***************************************/
	/*EZUI_Page *SettingsPage = new EZUI_Page("Settings");
	SettingsPage->addItem(new EZUI_PageItem(3,0,new EZUI_Control_Link("Back",MainMenu)));*/
		
	/***************************************
	  Diagnostics Page
	***************************************/
	/*EZUI_Page *DiagPage = new EZUI_Page("Settings");
	DiagPage->addItem(new EZUI_PageItem(3,0,new EZUI_Control_Link("Back",MainMenu)));*/
	
	/***************************************
	  Setup Main Menu
	***************************************/
	//MainMenu->addItem(new EZUI_Control_Link("Monitor",MonitorPage));
	//MainMenu->addItem(new EZUI_Control_Link("Monitor",SettingsPage));
	//MainMenu->addItem(new EZUI_Control_Link("Diagnostics",DiagPage));

	HLT_UI->setDisplay(MainMenu);
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println("Done.");
	#endif
}
