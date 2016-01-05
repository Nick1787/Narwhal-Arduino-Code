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

UserInterface *MAIN_UI = new UserInterface("MAIN");

void MAIN_UI_init(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.print("Initializing UI - " + MAIN_UI->Name + "...");
	#endif
	
	/***************************************
	  Setup + Initialization
	***************************************/
	MAIN_UI->attatchEncoder(MAIN_ENC);
	MAIN_UI->attatchLCD(&MAIN_LCD);
	
	//Main Menu
	LCDMenu * MainMenu = new LCDMenu("Main");
	
	/***************************************
	  Alarm Test Menu
	***************************************/
	LCDMenu * MenuAlarmTest = new LCDMenu("Alarm Test",MainMenu);
	
	LCDToggleOption *TimerAlarmTgl = new LCDToggleOption("Timer Alarm",TimerAlarmDIO);
	LCDMenuItem * MenuItem_TimerAlarm = new LCDMenuItem("Timer Alarm",TimerAlarmTgl);
	
	LCDToggleOption *TempAlarmTgl = new LCDToggleOption("Temp Alarm",TempAlarmDIO);
	LCDMenuItem * MenuItem_TempAlarm = new LCDMenuItem("Temp Alarm",TempAlarmTgl);
	
	LCDMenuItem * MenuItem_Back = new LCDMenuItem("Back",MainMenu);
	
	MenuAlarmTest->Items.add(*MenuItem_TimerAlarm);
	MenuAlarmTest->Items.add(*MenuItem_TempAlarm);
	MenuAlarmTest->Items.add(*MenuItem_Back);
	
	/***************************************
	  Pump Monitor Page
	***************************************/
	LCDPage * PagePumpMonitor = new LCDPage("PumpMonitor");
	LCDPageItem * PageItem_Pump1Label = new LCDPageItem(0,0,new String("Pump#1"));
	LCDPageItem * PageItem_Pump1Status = new LCDPageItem(0,7,new String("OFF"));
	LCDPageItem * PageItem_Pump2Label = new LCDPageItem(1,0,new String("Pump#2"));
	LCDPageItem * PageItem_Pump2Status = new LCDPageItem(1,7,new String("OFF"));
	LCDPageItem * PageItem_ExecTimeLabel = new LCDPageItem(3,0,new String("Time:"));
	LCDPageItem * PageItem_ExecStatus = new LCDPageItem(3,6,(float)1.234);
	
	PagePumpMonitor->Items.add(*PageItem_Pump1Label);
	PagePumpMonitor->Items.add(*PageItem_Pump1Status);
	PagePumpMonitor->Items.add(*PageItem_Pump2Label);
	PagePumpMonitor->Items.add(*PageItem_Pump2Status);
	
	LCDMenuItem * MenuItemAlarmTest = new LCDMenuItem("Alarm Test",MenuAlarmTest);
	MainMenu->Items.add(*MenuItemAlarmTest);
	LCDMenuItem * MenuItemPumpMonitor = new LCDMenuItem("Pump Monitor",PagePumpMonitor);
	MainMenu->Items.add(*MenuItemPumpMonitor);

	MAIN_UI->setDisplay(MainMenu);
	
	///////////////////////////////////
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println("Done.");
	#endif
}
