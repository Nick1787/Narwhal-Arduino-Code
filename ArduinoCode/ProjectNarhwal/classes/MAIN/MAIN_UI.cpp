/*
 *        File: MAIN_UI.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Main display user interface
 * ----------------------------------------------------------------
 *    Revision:
 *		01012015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "MAIN_UI.h"

EZUI *MAIN_UI = new EZUI("MAIN");

void MAIN_UI_init(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.print("Initializing UI - " + MAIN_UI->Name + "...");
	#endif
	
	EZUI_Menu * MainMenu = new EZUI_Menu("Main");
	
	/***************************************
	  Setup + Initialization
	***************************************/
	MAIN_UI->attatchEncoder(MAIN_ENC);
	MAIN_UI->attatchLCD(&MAIN_LCD);
	MAIN_UI->setDisplay(MainMenu);
	
	///////////////////////////////////
	
	
	
	/***************************************
	  Alarm Test Menu
	***************************************/
	
	EZUI_Menu * MenuAlarmTest = new EZUI_Menu(F("Alarm Test"));	
	//MenuAlarmTest->addItem(new EZUI_Control_ToggleOption("Timer Alarm",TimerAlarmDIO));
	//MenuAlarmTest->addItem(new EZUI_Control_ToggleOption("Temp Alarm",TempAlarmDIO));
	MenuAlarmTest->addItem(new EZUI_Control_Link(F("Back"),MainMenu));
	
	/***************************************
	  Analogs
	***************************************/
	
	EZUI_Page * Analogs_0_to_5 = new EZUI_Page((String)("Analogs 0-5"));
	Analogs_0_to_5->addItem(new EZUI_PageItem(0,0,(String)(" A0:")));
	Analogs_0_to_5->addItem(new EZUI_PageItem(4,0,&analog0));
	Analogs_0_to_5->addItem(new EZUI_PageItem(0,1,(String)(" A1:")));
	Analogs_0_to_5->addItem(new EZUI_PageItem(4,1,&analog1));
	Analogs_0_to_5->addItem(new EZUI_PageItem(0,2,(String)(" A2:")));
	Analogs_0_to_5->addItem(new EZUI_PageItem(4,2,&analog2));/*
	Analogs_0_to_5->addItem(new EZUI_PageItem(10,0,(String)(" A3:")));
	Analogs_0_to_5->addItem(new EZUI_PageItem(14,0,&analog3));
	Analogs_0_to_5->addItem(new EZUI_PageItem(10,1,(String)(" A4:")));
	Analogs_0_to_5->addItem(new EZUI_PageItem(14,1,&analog4));
	Analogs_0_to_5->addItem(new EZUI_PageItem(10,2,(String)(" A5:")));
	Analogs_0_to_5->addItem(new EZUI_PageItem(14,2,&analog5));*/
	
	/*EZUI_Page * Analogs_6_to_11 = new EZUI_Page(F("Analogs 6-11"));
	Analogs_6_to_11->addItem(new EZUI_PageItem(0,0,F(" A6:")));
	Analogs_6_to_11->addItem(new EZUI_PageItem(4,0,&analog6));
	Analogs_6_to_11->addItem(new EZUI_PageItem(0,1,F(" A7:")));
	Analogs_6_to_11->addItem(new EZUI_PageItem(4,1,&analog7));
	Analogs_6_to_11->addItem(new EZUI_PageItem(0,2,F(" A8:")));
	Analogs_6_to_11->addItem(new EZUI_PageItem(4,2,&analog8));
	Analogs_6_to_11->addItem(new EZUI_PageItem(10,0,F(" A9:")));
	Analogs_6_to_11->addItem(new EZUI_PageItem(14,0,&analog9));
	Analogs_6_to_11->addItem(new EZUI_PageItem(10,1,F(" A10:")));
	Analogs_6_to_11->addItem(new EZUI_PageItem(14,1,&analog10));
	Analogs_6_to_11->addItem(new EZUI_PageItem(10,2,F(" A11:")));
	Analogs_6_to_11->addItem(new EZUI_PageItem(14,2,&analog11));*/
	
	/*
	EZUI_Page * Analogs_12_to_15 = new EZUI_Page(F("Analogs 12-15"));
	Analogs_12_to_15->addItem(new EZUI_PageItem(0,0,F(" A12:")));
	Analogs_12_to_15->addItem(new EZUI_PageItem(4,0,&analog12));
	Analogs_12_to_15->addItem(new EZUI_PageItem(0,1,F(" A13:")));
	Analogs_12_to_15->addItem(new EZUI_PageItem(4,1,&analog13));
	Analogs_12_to_15->addItem(new EZUI_PageItem(10,0,F(" A14:")));
	Analogs_12_to_15->addItem(new EZUI_PageItem(14,0,&analog14));
	Analogs_12_to_15->addItem(new EZUI_PageItem(10,1,F(" A15:")));
	Analogs_12_to_15->addItem(new EZUI_PageItem(14,1, &analog15)); */
	
	/***************************************
	  Relay Diagnostics Menu
	***************************************/	
	EZUI_Menu *MenuRCDiag = new EZUI_Menu("Rc");
	/*MenuRCDiag->addItem(new EZUI_Control_ToggleOption("RC1_Out1",RC1_OUT1));
	MenuRCDiag->addItem(new EZUI_Control_ToggleOption("RC1_Out2",RC1_OUT2));
	MenuRCDiag->addItem(new EZUI_Control_ToggleOption("RC1_Out3",RC1_OUT3));*/
	MenuRCDiag->addItem(new EZUI_Control_ToggleOption("RC1_Out4",&RC1_OUT4));
	MenuRCDiag->addItem(new EZUI_Control_ToggleOption("RC1_Out5",&RC1_OUT5));
	MenuRCDiag->addItem(new EZUI_Control_ToggleOption("RC1_Out6",&RC1_OUT6));
	//MenuRCDiag->addItem(new EZUI_Control_ToggleOption("RC1_Out7",RC1_OUT7));
	//MenuRCDiag->addItem(new EZUI_Control_ToggleOption("RC1_Out8",RC1_OUT8));
	
	/***************************************
	  Analogs Diagnostics Menu
	***************************************/
	
	EZUI_Menu * MenuAnalogsMonitor = new EZUI_Menu("Analog Diagnostics");
	Analogs_0_to_5->addItem(new EZUI_PageItem(0,3,new EZUI_Control_Link("Back",MainMenu)));
	//Analogs_6_to_11->addItem(new EZUI_PageItem(0,3,new EZUI_Control_Link("Back",MainMenu)));
	//Analogs_12_to_15->addItem(new EZUI_PageItem(0,3,new EZUI_Control_Link("Back",MainMenu)));
	MenuAnalogsMonitor->addItem(new EZUI_Control_Link("Analogs 0 to 5",Analogs_0_to_5));
	//MenuAnalogsMonitor->addItem(new EZUI_Control_Link("Analogs 6 to 11",Analogs_6_to_11));
	//MenuAnalogsMonitor->addItem(new EZUI_Control_Link("Analogs 12 to 15",Analogs_12_to_15));
	MenuAnalogsMonitor->addItem(new EZUI_Control_Link("Back",MainMenu));
	
	/***************************************
	  HLT_BP - RTD Diagnostics Menu
	***************************************/
	EZUI_Page * Page_HLT_BP = new EZUI_Page("HLT BP");/*
	Page_HLT_BP->addItem(new EZUI_PageItem(0,0,(String)"-HLT-BP-"));
	Page_HLT_BP->addItem(new EZUI_PageItem(10,0,(String)"TF:"));
	Page_HLT_BP->addItem(new EZUI_PageItem(14,0,HLT_RTD_BP->degF));
	Page_HLT_BP->addItem(new EZUI_PageItem(0,1,(String)" Vs:"));
	Page_HLT_BP->addItem(new EZUI_PageItem(4,1,HLT_RTD_BP->Vs));
	Page_HLT_BP->addItem(new EZUI_PageItem(10,1,(String)" Vo:"));
	Page_HLT_BP->addItem(new EZUI_PageItem(14,1,HLT_RTD_BP->Vo));
	Page_HLT_BP->addItem(new EZUI_PageItem(0,2,(String)" R:"));
	Page_HLT_BP->addItem(new EZUI_PageItem(4,2,HLT_RTD_BP->Rcalc));
	Page_HLT_BP->addItem(new EZUI_PageItem(10,2,(String)" Tc:"));
	Page_HLT_BP->addItem(new EZUI_PageItem(14,2,HLT_RTD_BP->degC));*/
	
	/*
	EZUI_Page * Page_HLT_OP = new EZUI_Page("HLT OP");
	Page_HLT_OP->addItem(new EZUI_PageItem(0,0,(String)"-HLT-OP-"));
	Page_HLT_OP->addItem(new EZUI_PageItem(10,0,(String)"TF:"));
	Page_HLT_OP->addItem(new EZUI_PageItem(14,0,HLT_RTD_OP->degF));
	Page_HLT_OP->addItem(new EZUI_PageItem(0,1,(String)" Vs:"));
	Page_HLT_OP->addItem(new EZUI_PageItem(4,1,HLT_RTD_OP->Vs));
	Page_HLT_OP->addItem(new EZUI_PageItem(10,1,(String)" Vo:"));
	Page_HLT_OP->addItem(new EZUI_PageItem(14,1,HLT_RTD_OP->Vo));
	Page_HLT_OP->addItem(new EZUI_PageItem(0,2,(String)" R:"));
	Page_HLT_OP->addItem(new EZUI_PageItem(4,2,HLT_RTD_OP->Rcalc));
	Page_HLT_OP->addItem(new EZUI_PageItem(10,2,(String)" Tc:"));
	Page_HLT_OP->addItem(new EZUI_PageItem(14,2,HLT_RTD_OP->degC));
	
	EZUI_Page * Page_MLT_BP = new EZUI_Page("MLT BP");
	Page_MLT_BP->addItem(new EZUI_PageItem(0,0,(String)"-MLT-OP-"));
	Page_MLT_BP->addItem(new EZUI_PageItem(10,0,(String)"TF:"));
	Page_MLT_BP->addItem(new EZUI_PageItem(14,0,MLT_RTD_BP->degF));
	Page_MLT_BP->addItem(new EZUI_PageItem(0,1,(String)" Vs:"));
	Page_MLT_BP->addItem(new EZUI_PageItem(4,1,MLT_RTD_BP->Vs));
	Page_MLT_BP->addItem(new EZUI_PageItem(10,1,(String)" Vo:"));
	Page_MLT_BP->addItem(new EZUI_PageItem(14,1,MLT_RTD_BP->Vo));
	Page_MLT_BP->addItem(new EZUI_PageItem(0,2,(String)" R:"));
	Page_MLT_BP->addItem(new EZUI_PageItem(4,2,MLT_RTD_BP->Rcalc));
	Page_MLT_BP->addItem(new EZUI_PageItem(10,2,(String)" Tc:"));
	Page_MLT_BP->addItem(new EZUI_PageItem(14,2,MLT_RTD_BP->degC));
	
	EZUI_Page * Page_MLT_OP = new EZUI_Page("MLT OP");
	Page_MLT_OP->addItem(new EZUI_PageItem(0,0,(String)"-MLT-OP-"));
	Page_MLT_OP->addItem(new EZUI_PageItem(10,0,(String)"TF:"));
	Page_MLT_OP->addItem(new EZUI_PageItem(14,0,MLT_RTD_OP->degF));
	Page_MLT_OP->addItem(new EZUI_PageItem(0,1,(String)" Vs:"));
	Page_MLT_OP->addItem(new EZUI_PageItem(4,1,MLT_RTD_OP->Vs));
	Page_MLT_OP->addItem(new EZUI_PageItem(10,1,(String)" Vo:"));
	Page_MLT_OP->addItem(new EZUI_PageItem(14,1,MLT_RTD_OP->Vo));
	Page_MLT_OP->addItem(new EZUI_PageItem(0,2,(String)" R:"));
	Page_MLT_OP->addItem(new EZUI_PageItem(4,2,MLT_RTD_OP->Rcalc));
	Page_MLT_OP->addItem(new EZUI_PageItem(10,2,(String)" Tc:"));
	Page_MLT_OP->addItem(new EZUI_PageItem(14,2,MLT_RTD_OP->degC));
	
	
	EZUI_Page * Page_BK_BP = new EZUI_Page("BK BP");
	Page_BK_BP->addItem(new EZUI_PageItem(0,0,(String)"-BK-BP-"));
	Page_BK_BP->addItem(new EZUI_PageItem(10,0,(String)"TF:"));
	Page_BK_BP->addItem(new EZUI_PageItem(14,0,BK_RTD_BP->degF));
	Page_BK_BP->addItem(new EZUI_PageItem(0,1,(String)" Vs:"));
	Page_BK_BP->addItem(new EZUI_PageItem(4,1,BK_RTD_BP->Vs));
	Page_BK_BP->addItem(new EZUI_PageItem(10,1,(String)" Vo:"));
	Page_BK_BP->addItem(new EZUI_PageItem(14,1,BK_RTD_BP->Vo));
	Page_BK_BP->addItem(new EZUI_PageItem(0,2,(String)" R:"));
	Page_BK_BP->addItem(new EZUI_PageItem(4,2,BK_RTD_BP->Rcalc));
	Page_BK_BP->addItem(new EZUI_PageItem(10,2,(String)" Tc:"));
	Page_BK_BP->addItem(new EZUI_PageItem(14,2,BK_RTD_BP->degC));
	
	EZUI_Page * Page_BK_OP = new EZUI_Page("BK OP");
	Page_BK_OP->addItem(new EZUI_PageItem(0,0,(String)"-BK-OP-"));
	Page_BK_OP->addItem(new EZUI_PageItem(10,0,(String)"TF:"));
	Page_BK_OP->addItem(new EZUI_PageItem(14,0,BK_RTD_OP->degF));
	Page_BK_OP->addItem(new EZUI_PageItem(0,1,(String)" Vs:"));
	Page_BK_OP->addItem(new EZUI_PageItem(4,1,BK_RTD_OP->Vs));
	Page_BK_OP->addItem(new EZUI_PageItem(10,1,(String)" Vo:"));
	Page_BK_OP->addItem(new EZUI_PageItem(14,1,BK_RTD_OP->Vo));
	Page_BK_OP->addItem(new EZUI_PageItem(0,2,(String)" R:"));
	Page_BK_OP->addItem(new EZUI_PageItem(4,2,BK_RTD_OP->Rcalc));
	Page_BK_OP->addItem(new EZUI_PageItem(10,2,(String)" Tc:"));
	Page_BK_OP->addItem(new EZUI_PageItem(14,2,BK_RTD_OP->degC));
	*/
	/***************************************
	  RTD Diagnostics Menu
	***************************************/
	EZUI_Menu * MenuRTDMonitor = new EZUI_Menu("RTD Diagnostics");
	Page_HLT_BP->addItem(new EZUI_PageItem(0,3,new EZUI_Control_Link("Back",MenuRTDMonitor)));
	//Page_HLT_OP->addItem(new EZUI_PageItem(0,3,new EZUI_Control_Link("Back",MenuRTDMonitor)));
	//Page_MLT_BP->addItem(new EZUI_PageItem(0,3,new EZUI_Control_Link("Back",MenuRTDMonitor)));
	//Page_MLT_OP->addItem(new EZUI_PageItem(0,3,new EZUI_Control_Link("Back",MenuRTDMonitor)));
	//Page_BK_BP->addItem(new EZUI_PageItem(0,3,new EZUI_Control_Link("Back",MenuRTDMonitor)));
	//Page_BK_OP->addItem(new EZUI_PageItem(0,3,new EZUI_Control_Link("Back",MenuRTDMonitor)));
	MenuRTDMonitor->addItem(new EZUI_Control_Link("HLT BP",Page_HLT_BP));
	//MenuRTDMonitor->addItem(new EZUI_Control_Link("HLT OP",Page_HLT_OP));
	//MenuRTDMonitor->addItem(new EZUI_Control_Link("MLT BP",Page_MLT_BP));
	//MenuRTDMonitor->addItem(new EZUI_Control_Link("MLT OP",Page_MLT_OP));
	//MenuRTDMonitor->addItem(new EZUI_Control_Link("BK BP",Page_BK_BP));
	//MenuRTDMonitor->addItem(new EZUI_Control_Link("BK OP",Page_BK_OP));
	MenuRTDMonitor->addItem(new EZUI_Control_Link("Back",MainMenu));
	
	/***************************************
	  Pump Monitor Page
	***************************************/
	/*EZUI_Page *PagePumpMonitor = new EZUI_Page("PumpMonitor");
	PagePumpMonitor->addItem(new EZUI_PageItem(0,0,(String)"Pump#1"));
	PagePumpMonitor->addItem(new EZUI_PageItem(0,1,(String)"Pump#2"));
	PagePumpMonitor->addItem(new EZUI_PageItem(0,3,new EZUI_Control_Link("Back",MainMenu)));*/
	
	/***************************************
	  Build the Main Menu and Set the Display
	***************************************/
	//MainMenu->addItem(new EZUI_Control_Link("Alarm Test",MenuAlarmTest));
	//MainMenu->addItem(new EZUI_Control_Link("Pump Monitor",PagePumpMonitor));
	MainMenu->addItem(new EZUI_Control_Link("Analogs Monitor",MenuAnalogsMonitor));
	MainMenu->addItem(new EZUI_Control_Link("RTD Diagnostics",MenuRTDMonitor));
	MainMenu->addItem(new EZUI_Control_Link("RC Diagnostics",MenuRCDiag));

	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println("Done.");
	#endif
}
