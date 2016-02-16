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

EZUI *MLT_UI = new EZUI("MLT");

void MLT_UI_init(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.print("Initializing UI - " + MLT_UI->Name + "...");
	#endif
	
	/***************************************
	  Setup + Initialization
	***************************************/
	MLT_UI->attatchEncoder(MLT_ENC);
	MLT_UI->attatchLCD(&MLT_LCD);
	
	EZUI_Menu * MainMenu = new EZUI_Menu("MLT-Main-Menu");
	
	EZUI_Page * TestPage = new EZUI_Page((String)("TestPage"));
	TestPage->addItem(0,3,new EZUI_Control_Link("Back",MainMenu));
	
	MainMenu->addItem(new EZUI_Control_Link("TestPage",TestPage));
	MainMenu->addItem(new EZUI_Control_Link("Test2",MainMenu));
	
	/***************************************
	  Monitor Page
	***************************************/
	/*EZUI_PageItem *LBL_PageName = new EZUI_PageItem(0,0,MLT_UI->Name);
	EZUI_PageItem *LBL_Colon = new EZUI_PageItem(0,3,new String(":"));
	EZUI_PageItem *LBL_Status = new EZUI_PageItem(0,3,new String("Status Message Goes Here"));
	EZUI_PageItem *Sol1Tgl = new EZUI_PageItem(1,0, new EZUI_Control_ToggleOption("Sol#1:", MLT_SOL1));
	EZUI_PageItem *Sol2Tgl = new EZUI_PageItem(1,11, new EZUI_Control_ToggleOption("Sol#1:", MLT_SOL2));
	EZUI_PageItem *LBL_BPStr = new EZUI_PageItem(2,0,new String("BP=XXX F"));
	EZUI_PageItem *LBL_OPStr = new EZUI_PageItem(2,12,new String("OP=XXX F"));
	EZUI_PageItem *Lnk_Back = new EZUI_PageItem(3,0,new EZUI_Control_Link("Back",MLTMainMenu));
	
	EZUI_Page *MonitorPage = new EZUI_Page("Monitor");
	MonitorPage->addItem(LBL_PageName);
	MonitorPage->addItem(LBL_Colon);
	MonitorPage->addItem(LBL_Status);
	MonitorPage->addItem(Sol1Tgl);
	MonitorPage->addItem(Sol2Tgl);
	MonitorPage->addItem(LBL_BPStr);
	MonitorPage->addItem(Lnk_Back);*/
	
	/***************************************
	  Settings Menu
	***************************************/
		
	/***************************************
	  Diagnostics Page
	***************************************/
	
	/***************************************
	  MLT Menu
	***************************************/
	//MLTMainMenu->addItem(new EZUI_Control_Link("Monitor",MonitorPage));
	
	MLT_UI->setDisplay(MainMenu);
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println("Done.");
	#endif
}
