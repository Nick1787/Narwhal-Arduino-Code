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


//ListOptionItem<EnumPWMLevels> PWMTest(A(PWMLevels));
//ListOptionItem<EnumBurnerModes> ModeTest(A(BurnerModes));
namespace UI_MAIN{
	EZUI *UI = new EZUI();

	/***************************************
	 Main Menu
	***************************************/
	EZUI_Menu Menu_Main;
	EZUI_Control_Link Lnk_BackMainMenu(pTXT_Back_NoColon,&Menu_Main);
	EZUI_Control_Link Lnk_SettingsMainMenu(pTXT_Settings_NoColon,&Menu_Main);

	/***************************************
	 Main Page
	***************************************/
	EZUI_Page Page_Main;
	EZUI_Control_Link Lnk_BackMainPage(pTXT_Back_NoColon,&Page_Main);
	EZUI_Control_Link Lnk_MainPage(pTXT_Monitor_NoColon,&Page_Main);
	
	/***************************************
	  Page - Data Logger
	***************************************/
	EZUI_Page Page_Logger;
	EZUI_Control_Link Lnk_DataLogger(pTXT_Log, &Page_Logger);
	
	/***************************************
	  Pager Timer1
	***************************************/
	EZUI_Page Page_Timer1;
	EZUI_Control_Link Lnk_Timer1(pTXT_Timer1, &Page_Logger);
	
	/***************************************
	  Pager Timer2
	***************************************/
	EZUI_Page Page_Timer2;
	EZUI_Control_Link Lnk_Timer2(pTXT_Timer2, &Page_Logger);
	
	/***************************************
	 Menu - Alarm Fire
	***************************************/
	EZUI_Menu Menu_AlarmMonitor;
	EZUI_Control_Link Lnk_MenuAlarmMonitor(pTXT_Alarms_NoColon,&Menu_AlarmMonitor);
	EZUI_Control_ToggleOption Tgl_Alarm1Opt(pTXT_Alarm1,&RC2_OUT4);
	EZUI_Control_ToggleOption Tgl_Alarm2Opt(pTXT_Alarm2,&RC2_OUT5);
	EZUI_MenuItems Menu_AlarmText_Items[3] = {
		{&Tgl_Alarm1Opt},
		{&Tgl_Alarm2Opt},
		{&Lnk_BackMainMenu}
	};
	
		
	/***************************************
	  Page - Real Time Clock
	***************************************/
	EZUI_Page Page_RealTimeClock;
	EZUI_Control_Link Lnk_RealTimeClock(pTXT_Clock_NoColon,&Page_RealTimeClock);
	EZUI_Control_AdjustParam   Adj_Day(pTXT_Day, RTC().Day);
	EZUI_Control_AdjustParam Adj_Month(pTXT_Month, RTC().Month);
	EZUI_Control_AdjustParam  Adj_Year(pTXT_Year, RTC().Year);
	EZUI_Control_AdjustParam  Adj_Secs(pTXT_Sec, RTC().Second);
	EZUI_Control_AdjustParam  Adj_Mins(pTXT_Min, RTC().Minute);
	EZUI_Control_AdjustParam  Adj_Hour(pTXT_Hour, RTC().Hour);
	EZUI_PageItems Page_RealTimeClock_Items[] = {
		{ 0,  0, 9, &Adj_Year},
		{ 0,  1, 8, &Adj_Month},
		{ 0,  2, 6, &Adj_Day},
			
		{ 11,  0, 7, &Adj_Hour},
		{ 11,  1, 6, &Adj_Mins},
		{ 11,  2, 6, &Adj_Secs},
		{ 11,  3, 4, &Lnk_BackMainMenu},
	};
	
	/***************************************
	  Page - ThermoCouples Monitor
	***************************************/
	EZUI_Page Page_TCMonitor;
	EZUI_Control_Link Lnk_PageTCMonitor(pTXT_TCMonitor_NoColon,&Page_TCMonitor);
	EZUI_Control_Label Lbl_TC_HLTVal(&HLT_TC_ON, "ON", "OFF");
	EZUI_Control_Label Lbl_TC_MLTVal(&MLT_TC_ON, "ON", "OFF");
	EZUI_Control_Label Lbl_TC_BKVal(&BK_TC_ON, "ON", "OFF");
	EZUI_Control_Label Lbl_Vlbl(pTXT_V);
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
	};

		
	/***************************************
	 Main Page
	***************************************/
	//Define the Text we want to use
	EZUI_Control_Label Lbl_DateTime(&CurrentDateTime);
	EZUI_Control_Label Lbl_LogStatus( &Logger().isRunning, pTXT_Running_NoColon, pTXT_Stopped_NoColon);
	EZUI_Control_Link Lnk_T1(pTXT_T1,&Page_Timer1);
	EZUI_Control_Label Lbl_T1(&NarwhalTimer1().remainingMMSS);
	EZUI_Control_Link Lnk_T2(pTXT_T2,&Page_Timer2);
	EZUI_Control_Label Lbl_T2(&NarwhalTimer2().remainingMMSS);
	EZUI_PageItems Page_Main_Items[] = {
			{ 2,  0, 16, &Lbl_DateTime},
			{ 0,  1, 5, &Lnk_DataLogger},
			{ 5,  1, 7, &Lbl_LogStatus},
			{ 0,  2, 10, &Lnk_T1},
			{ 4,  2, 10, &Lbl_T1},
			{ 10, 2, 10, &Lnk_T2},
			{ 14,  2, 10, &Lbl_T2},
			{ 0, 3, 7, &Lnk_SettingsMainMenu}
	};
	
	/***************************************
	  Page - Timer1
	***************************************/
	EZUI_Control_Label LBL_Timer1_Status(pTXT_Timer1,&NarwhalTimer1().isPaused,pTXT_Stopped_NoColon,pTXT_Running_NoColon);
	EZUI_Control_AdjustParam Adj_Timer1_Value(pTXT_Total, NarwhalTimer1().TotalTime);
	EZUI_Control_Label LBL_Value(pTXT_Value);
	EZUI_Control_ToggleOption Tgl_Timer1_STOP( &NarwhalTimer1().isPaused,pTXT_Start,pTXT_Stop);
	EZUI_Control_ToggleOption Tgl_Timer1_Reset(pTXT_Reset, &NarwhalTimer1().reset,pTXT_Reset,pTXT_Reset);
	EZUI_PageItems Page_Timer1_Items[] = {
		{ 0,  0, 16, &LBL_Timer1_Status},
		{ 0,  1, 13, &Adj_Timer1_Value},
		{ 1,  2, 5, &LBL_Value},
		{ 7,  2, 6,  &Lbl_T1}, 
		{ 14,  1, 5, &Tgl_Timer1_STOP},
		{ 14,  2, 5, &Tgl_Timer1_Reset},
		{ 0, 3, 7, &Lnk_BackMainPage}
	};
	
	/***************************************
	  Page - Timer2
	***************************************/
	EZUI_Control_Label LBL_Timer2_Status(pTXT_Timer2,&NarwhalTimer2().isPaused,pTXT_Stopped_NoColon,pTXT_Running_NoColon);
	EZUI_Control_AdjustParam Adj_Timer2_Value(pTXT_Total, NarwhalTimer2().TotalTime);
	EZUI_Control_ToggleOption Tgl_Timer2_STOP( &NarwhalTimer2().isPaused,pTXT_Start,pTXT_Stop);
	EZUI_Control_ToggleOption Tgl_Timer2_Reset(pTXT_Reset, &NarwhalTimer2().reset,pTXT_Reset,pTXT_Reset);
	EZUI_PageItems Page_Timer2_Items[] = {
		{ 0,  0, 16, &LBL_Timer2_Status},
		{ 0,  1, 13, &Adj_Timer2_Value},
		{ 1,  2, 5, &LBL_Value},
		{ 7,  2, 6,  &Lbl_T2},
		{ 14,  1, 5, &Tgl_Timer2_STOP},
		{ 14,  2, 5, &Tgl_Timer2_Reset},
		{ 0, 3, 7, &Lnk_BackMainPage}
	};
	
	/***************************************
	  Page - Data Logger
	***************************************/
	EZUI_Control_Label Lbl_File(pTXT_File,&(Logger().outFileName));
	EZUI_Control_AdjustParam   Adj_LogRate(pTXT_Rate, Logger().logRate);
	EZUI_Control_ToggleOption  Tgl_Status(pTXT_Status, &Logger().isRunning, pTXT_Running_NoColon, pTXT_Stopped_NoColon);
	EZUI_PageItems Page_Logger_Items[] = {
		{ 0,  0, 5, &Lbl_File},
		{ 0,  1, 5, &Adj_LogRate},
		{ 0,  2, 6, &Tgl_Status},
		{ 0,  3, 4, &Lnk_BackMainPage},
	};
	
	/***************************************
	 Main Menu Items
	***************************************/
	
	EZUI_MenuItems Menu_MainMenu_Items[] = {
		{  &Lnk_MainPage },
		{  &Lnk_MenuAlarmMonitor},
		{  &Lnk_RealTimeClock},
		{  &Lnk_PageTCMonitor},
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
		Page_Logger.setItems(A(Page_Logger_Items));
		Page_TCMonitor.setItems(A(Page_TCMonitor_Items));
		Page_Main.setItems(A(Page_Main_Items));
		Page_Timer1.setItems(A(Page_Timer1_Items));
		Page_Timer2.setItems(A(Page_Timer2_Items));
	
		/**************************************
		  Setup + Initialization
		  ***************************************/
		UI->attatchEncoder(&MAIN_ENC);
		UI->attatchLCD(&MAIN_LCD);
		UI->setUI(&Page_Main);
	
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
			Serial.println(F("Done."));
		#endif
	}
}