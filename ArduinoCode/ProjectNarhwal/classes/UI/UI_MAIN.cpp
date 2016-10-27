/*
 *        File: MAIN_UI.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Main display user interface
 * ----------------------------------------------------------------
 *    Revision:
 *		01012015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "UI_MAIN.h"
#include "../EZUI/Controls/EZUI_Control.h"
#include "../EZUI/Controls/EZUI_Control_ListOption.h"



namespace UI_MAIN{
	EZUI *UI = new EZUI();

	/***************************************
	 Main Menu
	***************************************/
	EZUI_Menu Menu_Main;
	EZUI_Control_Link Lnk_BackMainMenu("Back",&Menu_Main);

	/***************************************
	 Menu - Alarm Fire
	***************************************/
	EZUI_Menu Menu_AlarmMonitor;
	EZUI_Control_Link Lnk_MenuPumpMonitor("Alarms",&Menu_AlarmMonitor);
	EZUI_Control_ToggleOption Tgl_Alarm1Opt("Alarm#1",&RC2_OUT4);
	EZUI_Control_ToggleOption Tgl_Alarm2Opt("Alarm#2",&RC2_OUT5);
	MenuItem Menu_AlarmText_Items[3] = {
		{&Tgl_Alarm1Opt},
		{&Tgl_Alarm2Opt},
		{&Lnk_BackMainMenu}
	};
	
	/***************************************
	 Menu - Pilot Lit Indications
	***************************************/
	EZUI_Menu Menu_PilotMontior;
	EZUI_Control_Link Lnk_MenuPilotMonitor("Pilot Lights",&Menu_PilotMontior);
	EZUI_Control_ToggleOption Tgl_Pilot1Opt("Pilot #1",&RC2_OUT1);
	EZUI_Control_ToggleOption Tgl_Pilot2Opt("Pilot #2",&RC2_OUT2);
	EZUI_Control_ToggleOption Tgl_Pilot3Opt("Pilot #3",&RC2_OUT3);
	MenuItem Menu_PilotMonitor_Items[4] = {
		{&Tgl_Pilot1Opt},
		{&Tgl_Pilot2Opt},
		{&Tgl_Pilot3Opt},
		{&Lnk_BackMainMenu}
	};
	
	/***************************************
	  Page - ThermoCouples Monitor
	***************************************/
	EZUI_Page Page_TCMonitor;
	EZUI_Control_Link Lnk_PageTCMonitor("TC Monitor",&Page_TCMonitor);
	EZUI_Control_Label Lbl_TC_HLTVal(&HLT_TC_ON, "ON", "OFF");
	EZUI_Control_Label Lbl_TC_MLTVal(&MLT_TC_ON, "ON", "OFF");
	EZUI_Control_Label Lbl_TC_BKVal(&BK_TC_ON, "ON", "OFF");
	EZUI_Control_Label Lbl_Vlbl("V:");
	EZUI_Control_Label Lbl_TC_HLTVolt(&HLT_TC_V);
	EZUI_Control_Label Lbl_TC_MLTVolt(&MLT_TC_V);
	EZUI_Control_Label Lbl_TC_BKVolt(&BK_TC_V);
	PageItem Page_TCMonitor_Items[] = {
		{ 0,  0, 4, &Shared_Lbl_HLT},
		{ 5,  0, 3, &Lbl_TC_HLTVal},
		{ 10, 0, 2, &Lbl_Vlbl},
		{ 12, 0, 8, &Lbl_TC_HLTVolt},
		{ 0,  1, 4, &Shared_Lbl_MLT},
		{ 5,  1, 3, &Lbl_TC_MLTVal},
		{ 10, 1, 2, &Lbl_Vlbl},
		{ 12, 1, 8, &Lbl_TC_MLTVolt},
		{ 0,  2, 4, &Shared_Lbl_BK},
		{ 5,  2, 3, &Lbl_TC_BKVal},
		{ 10, 2, 2, &Lbl_Vlbl},
		{ 12, 2, 8, &Lbl_TC_BKVolt},
		{  0, 3, 4, &Lnk_BackMainMenu}
	};

	/***************************************
	 Page - Pump Monitor
	***************************************/
	EZUI_Page Page_PumpMonitor;
	EZUI_Control_Link Lnk_PagePumpMonitor("Pump Monitor",&Page_PumpMonitor);
	EZUI_Control_Label Lbl_Pump1lbl("Pump#1");
	EZUI_Control_Label Lbl_Pump1Val(&Pump1_On, "ON", "OFF");
	EZUI_Control_Label Lbl_Pump2lbl("Pump#2");
	EZUI_Control_Label Lbl_Pump2Val(&Pump2_On, "ON", "OFF");
	EZUI_Control_Label Lbl_Pump1Volt(&Pump1_V);
	EZUI_Control_Label Lbl_Pump2Volt(&Pump2_V);
	PageItem Page_PumpMonitor_Items[9] = {
		{ 0,  0, 6, &Lbl_Pump1lbl},
		{ 8,  0, 3, &Lbl_Pump1Val},
		{ 0,  1, 6, &Lbl_Pump2lbl},
		{ 8,  1, 3, &Lbl_Pump2Val},
		{ 14, 0, 2, &Shared_Lbl_V},
		{ 16, 0, 4, &Lbl_Pump1Volt},
		{ 14, 1, 2, &Shared_Lbl_V},
		{ 16, 1, 4, &Lbl_Pump2Volt},
		{  0, 3, 4, &Lnk_BackMainMenu}
	};
	
	
	/***************************************
	 Menu - Burner Modes
	***************************************/
	EZUI_Menu Menu_BurnerModes;
	EZUI_Control_Link Lnk_Menu_BurnerModes("Burner Modes",&Menu_BurnerModes);
	EZUI_Control_ListOption Lst_HLT_Mode("HLT Mode", &HLT_Controller.Mode);
	EZUI_Control_ListOption Lst_MLT_Mode("MLT Mode", &MLT_Controller.Mode);
	EZUI_Control_ListOption Lst_BK_Mode("BK Mode", &BK_Controller.Mode);
	MenuItem Menu_BurnerModes_Items[4] = {
		{&Lst_HLT_Mode},
		{&Lst_MLT_Mode},
		{&Lst_BK_Mode},
		{&Lnk_BackMainMenu}
	};
	
	
	/***************************************
	 Main Menu Items
	***************************************/
	MenuItem Menu_MainMenu_Items[] = {
		{  &Lnk_MenuPumpMonitor},
		{  &Lnk_Menu_BurnerModes},
		{  &Lnk_PageTCMonitor},
		{  &Lnk_MenuPilotMonitor},
		{  &Lnk_PagePumpMonitor}
	};

	void UI_init(){
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
			Serial.print(F("Initializing MAIN UI..."));
			Serial.flush();
		#endif
	
		/***************************************
		 Set Items
		***************************************/
		Menu_Main.setItems(A(Menu_MainMenu_Items));
		Menu_AlarmMonitor.setItems(A(Menu_AlarmText_Items));
		Menu_PilotMontior.setItems(A(Menu_PilotMonitor_Items));
		Page_TCMonitor.setItems(A(Page_TCMonitor_Items));
		Page_PumpMonitor.setItems(A(Page_PumpMonitor_Items));
		//Menu_BurnerModes.setItems(A(Menu_BurnerModes_Items));
	
		/**************************************
		  Setup + Initialization
		  ***************************************/
		UI->attatchEncoder(&MAIN_ENC);
		UI->attatchLCD(&MAIN_LCD);
		UI->setDisplay(&Menu_Main);
	
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
			Serial.println(F("Done."));
		#endif
	}
}