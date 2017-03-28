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

namespace UI_MAIN{
	EZUI *UI = new EZUI();

	/***************************************
	 Main Menu
	***************************************/
	EZUI_Menu Menu_Main;
	EZUI_Control_Link Lnk_BackMainMenu("Back",&Menu_Main);
	EZUI_Control_Link Lnk_SettingsMainMenu("Settngs",&Menu_Main);

	
	/***************************************
	 Menu - Alarm Fire
	***************************************/
	EZUI_Menu Menu_AlarmMonitor;
	EZUI_Control_Link Lnk_MenuPumpMonitor("Alarms",&Menu_AlarmMonitor);
	EZUI_Control_ToggleOption Tgl_Alarm1Opt("Alarm#1",&RC2_OUT4);
	EZUI_Control_ToggleOption Tgl_Alarm2Opt("Alarm#2",&RC2_OUT5);
	EZUI_MenuItems Menu_AlarmText_Items[3] = {
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
	EZUI_MenuItems Menu_PilotMonitor_Items[4] = {
		{&Tgl_Pilot1Opt},
		{&Tgl_Pilot2Opt},
		{&Tgl_Pilot3Opt},
		{&Lnk_BackMainMenu}
	};
	
	
	/***************************************
	  Page - Real Time Clock
	***************************************/
	EZUI_Page Page_RealTimeClock;
	EZUI_Control_Link Lnk_RealTimeClock("Clock",&Page_RealTimeClock);
	EZUI_Control_AdjustParam   Adj_Day("Day:  ", RTC().Day);
	EZUI_Control_Label Lbl_Day(RTC().Day);
	EZUI_Control_AdjustParam Adj_Month("Month:", RTC().Month);
	EZUI_Control_Label Lbl_Month(RTC().Month);
	EZUI_Control_AdjustParam  Adj_Year("Year: ", RTC().Year);
	EZUI_Control_Label Lbl_Year(RTC().Year);
	EZUI_Control_AdjustParam  Adj_Secs("Sec: ", RTC().Second);
	EZUI_Control_Label Lbl_Second(RTC().Second);
	EZUI_Control_AdjustParam  Adj_Mins("Min: ", RTC().Minute);
	EZUI_Control_Label Lbl_Minute(RTC().Minute);
	EZUI_Control_AdjustParam  Adj_Hour("Hour:", RTC().Hour);
	EZUI_Control_Label Lbl_Hour(RTC().Hour);
	EZUI_PageItems Page_RealTimeClock_Items[] = {
		{ 0,  0, 9, &Adj_Year},
		{ 7,  0, 4, &Lbl_Year},
		{ 0,  1, 6, &Adj_Month},
		{ 7,  1, 2, &Lbl_Month},
		{ 0,  2, 6, &Adj_Day},
		{ 7,  2, 2, &Lbl_Day},
			
		{ 12,  0, 10, &Adj_Hour},
		{ 18,  0, 2, &Lbl_Hour},
		{ 12,  1, 7, &Adj_Mins},
		{ 18,  1, 2, &Lbl_Minute},
		{ 12,  2, 7, &Adj_Secs},
		{ 18,  2, 2, &Lbl_Second},
		{ 12,  3, 4, &Lnk_BackMainMenu},
	};
	
	
	/***************************************
	  Page - Data Logger
	***************************************/
	EZUI_Page Page_Logger;
	EZUI_Control_Label Lbl_File("File:");
	EZUI_Control_Label Lbl_FileName(&Logger().outFileName);
	EZUI_Control_AdjustParam   Adj_LogRate("LogRt: ", Logger().logRate);
	EZUI_Control_Label Lbl_LogRate(Logger().logRate);
	EZUI_Control_ToggleOption  Tgl_Status("Status:", &Logger().isRunning, "Run", "Stop");
	EZUI_Control_Label Lbl_Status(&Logger().isRunning, "Run", "Stop");
	EZUI_PageItems Page_Logger_Items[] = {
		{ 0,  0, 5, &Lbl_File},
		{ 6,  0, 15, &Lbl_FileName},
		{ 0,  1, 5, &Adj_LogRate},
		{ 8,  1, 15, &Lbl_LogRate},
		{ 0,  2, 6, &Tgl_Status},
		{ 8,  2, 13, &Lbl_Status},
		{ 0,  3, 4, &Lnk_BackMainMenu},
	};
	
	/***************************************
	  Page - ThermoCouples Monitor
	***************************************/
	/*EZUI_Page Page_TCMonitor;
	EZUI_Control_Link Lnk_PageTCMonitor("TC Monitor",&Page_TCMonitor);
	EZUI_Control_Label Lbl_TC_HLTVal(&HLT_TC_ON, "ON", "OFF");
	EZUI_Control_Label Lbl_TC_MLTVal(&MLT_TC_ON, "ON", "OFF");
	EZUI_Control_Label Lbl_TC_BKVal(&BK_TC_ON, "ON", "OFF");
	EZUI_Control_Label Lbl_Vlbl("V:");
	EZUI_Control_Label Lbl_TC_HLTVolt(&HLT_TC_V);
	EZUI_Control_Label Lbl_TC_MLTVolt(&MLT_TC_V);
	EZUI_Control_Label Lbl_TC_BKVolt(&BK_TC_V);
	EZUI_PageItems Page_TCMonitor_Items[] = {
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
	};*/

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
	EZUI_PageItems Page_PumpMonitor_Items[9] = {
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
	/*EZUI_Menu Menu_BurnerModes;
	EZUI_Control_Link Lnk_Menu_BurnerModes("Burner Modes",&Menu_BurnerModes);
	EZUI_Control_ListOption Lst_HLT_Mode("HLT Mode", &HLT_Controller().Mode);
	EZUI_Control_ToggleOption Tgl_HLT_Sol1("HLT SOL1", HLT_Controller().GasValve_Low);
	EZUI_Control_ToggleOption Tgl_HLT_Sol2("HLT SOL2", HLT_Controller().GasValve_High);
	EZUI_Control_ListOption Lst_MLT_Mode("MLT Mode", &MLT_Controller().Mode);
	EZUI_Control_ToggleOption Tgl_MLT_Sol1("MLT SOL1", MLT_Controller().GasValve_Low);
	EZUI_Control_ToggleOption Tgl_MLT_Sol2("MLT SOL2", MLT_Controller().GasValve_High);
	EZUI_Control_ListOption Lst_BK_Mode("BK Mode", &BK_Controller().Mode);
	EZUI_Control_ToggleOption Tgl_BK_Sol1("BK SOL1", BK_Controller().GasValve_Low);
	EZUI_Control_ToggleOption Tgl_BK_Sol2("BK SOL2", BK_Controller().GasValve_High);
	EZUI_MenuItems Menu_BurnerModes_Items[] = {
		{&Lst_HLT_Mode},
		{&Tgl_HLT_Sol1},
		{&Tgl_HLT_Sol2},
		{&Lst_MLT_Mode},
		{&Tgl_MLT_Sol1},
		{&Tgl_MLT_Sol2},
		{&Lst_BK_Mode},
		{&Tgl_BK_Sol1},
		{&Tgl_BK_Sol2},
		{&Lnk_BackMainMenu}
	};*/
	
	/***************************************
	 Page - Burner Modes
	***************************************/
	/*EZUI_Page Page_BurnerModes;
	EZUI_Control_Link Lnk_Page_BurnerModes("Burner Modes Page",&Page_BurnerModes);
	EZUI_Control_Label Lbl_HLT_Mode(&HLT_Controller().Mode);
	EZUI_Control_Label Lbl_MLT_Mode(&MLT_Controller().Mode);
	EZUI_Control_Label Lbl_BK_Mode(&BK_Controller().Mode);
	EZUI_PageItems Page_BurnerModes_Items[7] = {
		{0,0,8,&Lst_HLT_Mode},
		{10,0,10,&Lbl_HLT_Mode},
		{0,1,8,&Lst_MLT_Mode},
		{10,1,10,&Lbl_MLT_Mode},
		{0,2,8,&Lst_BK_Mode},
		{10,2,10,&Lbl_BK_Mode},
		{0,3,10,&Lnk_BackMainMenu}
	};*/
	
	/***************************************
	 Main Page
	***************************************/
	EZUI_Page Page_Main;
	EZUI_Control_Link Lnk_BackMainPage("Monitor",&Page_Main);
	EZUI_Control_Label Lbl_DateTime(&CurrentDateTime);
	EZUI_Control_Link Lnk_DataLogger("LOG: ", &Page_Logger);
	EZUI_Control_Label Lbl_LogStatus( &Logger().isRunning, "Running", "Stopped");
	EZUI_Control_Label Lnk_Timer1("T1: ");
	EZUI_Control_Label Lnk_Timer1_Left("00:00");
	EZUI_Control_Label Lnk_Timer2("T2: ");
	EZUI_Control_Label Lnk_Timer2_Left("00:00");
	EZUI_PageItems Page_Main_Items[] = {
			{ 2,  0, 16, &Lbl_DateTime},
			{ 0,  1, 4, &Lnk_DataLogger},
			{ 5,  1, 7, &Lbl_LogStatus},
			{ 1,  2, 4, &Lnk_Timer1},
			{ 5,  2, 5, &Lnk_Timer1_Left},
			{ 11, 2, 5, &Lnk_Timer2},
			{ 15, 2, 5, &Lnk_Timer2_Left},
			{ 0, 3, 7, &Lnk_SettingsMainMenu}
	};
	
	/***************************************
	 Main Menu Items
	***************************************/
	EZUI_MenuItems Menu_MainMenu_Items[] = {
		{  &Lnk_BackMainPage },
		{  &Lnk_MenuPumpMonitor},
		{  &Lnk_RealTimeClock},
		//{  &Lnk_Menu_BurnerModes},
		//{  &Lnk_Page_BurnerModes},
		//{  &Lnk_PageTCMonitor},
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
		Page_RealTimeClock.setItems(A(Page_RealTimeClock_Items));
		Menu_PilotMontior.setItems(A(Menu_PilotMonitor_Items));
		Page_Logger.setItems(A(Page_Logger_Items));
		//Page_TCMonitor.setItems(A(Page_TCMonitor_Items));
		Page_PumpMonitor.setItems(A(Page_PumpMonitor_Items));
		Page_Main.setItems(A(Page_Main_Items));
		//Menu_BurnerModes.setItems(A(Menu_BurnerModes_Items));
		//Page_BurnerModes.setItems(A(Page_BurnerModes_Items));
	
		/**************************************
		  Setup + Initialization
		  ***************************************/
		UI->attatchEncoder(&MAIN_ENC);
		UI->attatchLCD(&MAIN_LCD);
		UI->setDisplay(&Page_Main);
	
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
			Serial.println(F("Done."));
		#endif
	}
}