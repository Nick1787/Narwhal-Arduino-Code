/*
 *        File: BK_UI.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: BK display user interface
 * ----------------------------------------------------------------
 *    Revision:
 *		01012015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "UI_BK.h"

namespace UI_BK{
	
	
	EZUI *UI  = new EZUI();
	
	
		/***************************************
		 Main Menu
		***************************************/
		EZUI_Menu Menu_Main;
		EZUI_Control_Link Lnk_Menu_MainBack(pTXT_Back_NoColon,&Menu_Main);

		/***************************************
		 Page - Monitor - Manual Control
		***************************************/
		EZUI_Page Page_ManualMonitor;
		EZUI_Control_Link Lnk_Page_ManualMonitor(pTXT_MonitorManual_NoColon,&Page_ManualMonitor);
		EZUI_Control_Link Lnk_Page_ManualMonitorBack(pTXT_Back_NoColon,&Page_ManualMonitor);
		
		//Page Items
		EZUI_Control_Label Lbl_Status(pTXT_Bk,&BK_Controller().Status);
		EZUI_Control_ToggleOption Tgl_Sol1Val(pTXT_Sol1,BK_Controller().GasValve_Low);
		EZUI_Control_ToggleOption Tgl_Sol2Val(pTXT_Sol2,BK_Controller().GasValve_High);
		EZUI_Control_Label Lbl_BPVal(pTXT_BP,&BK_RTD_BP.degF);
		EZUI_Control_Label Lbl_OPVal(pTXT_OP,&BK_RTD_OP.degF);
		EZUI_PageItems Page_Monitor_Items[] = {
			{  0,  0, 20, &Lbl_Status},
			{  0,  1, 10,  &Tgl_Sol1Val},
			{ 10,  1, 10,  &Tgl_Sol2Val},
			{  1,  2, 8,  &Lbl_BPVal},
			{ 11,  2, 8,  &Lbl_OPVal},
			{  0,  3, 4,  &Lnk_Menu_MainBack}
		};

		/***************************************
		 Page - Monitor - Closed Loop Control
		***************************************/
	
		EZUI_Page Page_ClosedLoopMonitor;
		EZUI_Control_Link Lnk_Page_ClosedLoopMonitor(pTXT_MonitorCL_NoColon,&Page_ClosedLoopMonitor);
		EZUI_Control_Link Lnk_Page_ClosedLoopMonitorBack(pTXT_Back_NoColon,&Page_ClosedLoopMonitor);
	
		/***************************************
		 Menu - Monitor - Manual Control - Settings
		***************************************/
		EZUI_Menu Menu_ClosedLoopControllersettings;
		EZUI_Control_Link Lnk_Menu_ClosedLoopControllersettings(pTXT_Set_NoColon,&Menu_ClosedLoopControllersettings);
		EZUI_Control_Link Lnk_Menu_ClosedLoopControllersettingsBack(pTXT_Back_NoColon,&Menu_ClosedLoopControllersettings);
	
		/***************************************
		 Page - Monitor - PWM
		***************************************/
		EZUI_Page Page_PWMMonitor;
		EZUI_Control_Link Lnk_Page_PWMMonitor(pTXT_MonitorPWM_NoColon,&Page_PWMMonitor);
		EZUI_Control_Link Lnk_Page_PWMMonitorBack(pTXT_Back_NoColon,&Page_PWMMonitor);
		
		/***************************************
		 Menu - Monitor - Manual Control - Settings
		***************************************/
		EZUI_Menu Menu_PWMControllersettings;
		EZUI_Control_Link Lnk_Menu_PWMControllersettings(pTXT_Settings_NoColon,&Menu_PWMControllersettings);
		EZUI_Control_Link Lnk_Menu_PWMControllersettingsBack(pTXT_Back_NoColon,&Menu_PWMControllersettings);
		
		/***************************************
		 Page - Diagnostics
		***************************************/
	
		EZUI_Page Page_Diag;
		EZUI_Control_Link Lnk_Page_Diag(pTXT_Diagnostics_NoColon,&Page_Diag);
		EZUI_Control_Link Lnk_Page_BackDiag(pTXT_Back_NoColon,&Page_Diag);
	
		/***************************************
		 Page - RTD - BK - BP
		***************************************/
		EZUI_Page Page_RTDs_BP;
		EZUI_Control_Link Lnk_Page_RTDs_BP(pTXT_BP,&Page_RTDs_BP);
		EZUI_Control_Label Lbl_RTDs_BK_BP_Vo(pTXT_Vo,&BK_RTD_BP.Vo);
		EZUI_Control_Label Lbl_RTDs_BK_BP_Vs(pTXT_Vs,&BK_RTD_BP.Vs);
		EZUI_Control_Label Lbl_RTDs_BK_BP_Rcalc(pTXT_Rcalc,&BK_RTD_BP.Rcalc);
		EZUI_Control_Label Lbl_RTDs_BK_BP_degC(pTXT_degC,&BK_RTD_BP.degC);
		EZUI_Control_Label Lbl_RTDs_BK_BP_degF(pTXT_degF,&BK_RTD_BP.degF);

		EZUI_PageItems Page_RTDs_BP_Items[] = {
			{  0,  0, 11, &Lbl_RTDs_BK_BP_Rcalc},
			{  12,  0, 7, &Lbl_RTDs_BK_BP_Vo},
			{  1,  1, 11, &Lbl_RTDs_BK_BP_degC},
			{  12,  1, 7, &Lbl_RTDs_BK_BP_Vs},
			{  1,  2, 11, &Lbl_RTDs_BK_BP_degF},
			{  0,  3, 4, &Lnk_Page_BackDiag}
		};

		/***************************************
		 Page - RTD - BK - OP	
		***************************************/
		EZUI_Page Page_RTDs_OP;
		EZUI_Control_Link Lnk_Page_RTDs_OP(pTXT_OP,&Page_RTDs_OP);
		EZUI_Control_Label Lbl_RTDs_BK_OP_Vo(pTXT_Vo,&BK_RTD_OP.Vo);
		EZUI_Control_Label Lbl_RTDs_BK_OP_Vs(pTXT_Vs,&BK_RTD_OP.Vs);
		EZUI_Control_Label Lbl_RTDs_BK_OP_Rcalc(pTXT_Rcalc,&BK_RTD_OP.Rcalc);
		EZUI_Control_Label Lbl_RTDs_BK_OP_degC(pTXT_degC,&BK_RTD_OP.degC);
		EZUI_Control_Label Lbl_RTDs_BK_OP_degF(pTXT_degF,&BK_RTD_OP.degF);

		EZUI_PageItems Page_RTDs_OP_Items[] = {
			{  0,  0, 11, &Lbl_RTDs_BK_OP_Rcalc},
			{  12,  0, 7, &Lbl_RTDs_BK_OP_Vo},
			{  1,  1, 11, &Lbl_RTDs_BK_OP_degC},
			{  12,  1, 7, &Lbl_RTDs_BK_OP_Vs},
			{  1,  2, 11, &Lbl_RTDs_BK_OP_degF},
			{  0,  3, 4, &Lnk_Page_BackDiag}
		};
	
		
		/***************************************
		 Closed Loop Monitor Items
		***************************************/
		EZUI_Control_ListOption Lst_FBProbe(pTXT_PRB, &BK_Controller().FeedbackProbe);
		EZUI_Control_AdjustParam Lst_Dmd(pTXT_DMD, BK_Controller().SetTemp);
		EZUI_Control_Label Lbl_FBK(pTXT_FBK,&BK_Controller().FeedbackTemp);
		EZUI_Control_Label LBL_Sol1(pTXT_Sol1,BK_Controller().GasValve_Low);
		EZUI_Control_Label LBL_Sol2(pTXT_Sol2,BK_Controller().GasValve_High);
	
		EZUI_PageItems Page_ClosedLoopMonitor_Items[] = {
			{  0,  0, 20, &Lbl_Status},
			{  0,  1, 10,  &Lst_FBProbe},
			{  11,  1, 9, &LBL_Sol1},
			{  0,  2, 9, &Lst_Dmd},
			{  11,  2, 9, &LBL_Sol2},
			{  1,  3, 9, &Lbl_FBK},
			{  10, 3, 3, &Lnk_Menu_ClosedLoopControllersettings },
			{  15,  3, 4, &Lnk_Menu_MainBack}
		};
	
	
		/***************************************
		 Closed Loop Settings Menu
		***************************************/
		EZUI_Control_AdjustParam Adj_Demand(pTXT_Demand, BK_Controller().SetTemp);
		EZUI_Control_AdjustParam Adj_HighOffset(pTXT_HighOffset, BK_Controller().HighOffset);
		EZUI_Control_AdjustParam Adj_MedOffset(pTXT_MedOffset, BK_Controller().MediumOffset);
		EZUI_Control_AdjustParam Adj_LowOffset(pTXT_LowOffset, BK_Controller().LowOffset);
		EZUI_Control_AdjustParam Adj_Hysteresis(pTXT_Hystersis, BK_Controller().Hysteresis);
		
		EZUI_MenuItems Menu_ClosedLoopControllersettings_Items[] = {
			{  &Adj_Demand },
			{  &Adj_HighOffset },
			{  &Adj_MedOffset },
			{  &Adj_LowOffset },
			{  &Adj_Hysteresis },
			{  &Lnk_Page_ClosedLoopMonitorBack }
		};
	
		/***************************************
		 PWM Monitor Items
		***************************************/
		EZUI_Control_ListOption Lst_PwmMode(pTXT_PWMLevel_NoColon, &BK_Controller().PWMLevel);
		EZUI_Control_AdjustParam Adj_PWMPeriod(pTXT_PWMPeriod_NoColon, BK_Controller().PWMPeriod);
		EZUI_Control_AdjustParam Adj_PWMDuty(pTXT_PWMDuty_NoColon, BK_Controller().PWMDutyCycle);
		EZUI_PageItems Page_PWMMonitor_Items[] = {
			{  0,  0, 20, &Lbl_Status},
			{  0,  1, 10,  &Lst_FBProbe},
			{  11,  1, 8, &Lst_PwmMode},
			{  1,  2, 9, &Lbl_FBK},
			{  11,  2, 8, &Adj_PWMPeriod},
			{  11, 3, 8, &Adj_PWMDuty },
			{  0,  3, 4, &Lnk_Menu_MainBack}
		};
		
			
		/***************************************
		 Main Diagnostics
		***************************************/
		EZUI_Control_Label Lbl_PilotStatus(pTXT_Pilot,&BK_TC_ON,pTXT_On_NoColon,pTXT_Off_NoColon);
		EZUI_Control_Label Lbl_PilotVoltage(pTXT_V,&BK_TC_V);
		EZUI_Control_Label Lbl_BPTemp(&BK_RTD_BP.degF);
		EZUI_Control_Label Lbl_OPTemp(&BK_RTD_OP.degF);
		
		EZUI_PageItems Page_Diag_Items[] = {
			{  0,  0, 20, &Lbl_Status},
			{  2,  1, 10, &Lbl_PilotStatus},
			{ 12,  1,  8, &Lbl_PilotVoltage},
			{  1,  2,  3, &Lnk_Page_RTDs_BP},
			{  5,  2,  5, &Lbl_BPTemp},
			{  11, 2,  3, &Lnk_Page_RTDs_OP},
			{  15,  2, 5, &Lbl_OPTemp},
			{  1,  3,  4, &Lnk_Menu_MainBack}
		};
	
		/***************************************
		 Menu - Main Menu Items
		***************************************/
		EZUI_Control_ToggleOption Tgl_FltInhibit(pTXT_FaultInhibit_NoColon, &BK_Controller().enableFaultInhibit,pTXT_On_NoColon,pTXT_Off_NoColon);
		EZUI_Control_ListOption Lst_ControlMode("Mode",&BK_Controller().Mode);
		EZUI_MenuItems Menu_Main_Items[] = {
			{  &Lst_ControlMode },
			{  &Lnk_Page_ManualMonitor },
			{  &Lnk_Page_ClosedLoopMonitor },
			{  &Lnk_Page_PWMMonitor },
			{  &Lnk_Page_Diag },
			{  &Tgl_FltInhibit },
		};


	void UI_init(){
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
			Serial.print(F("Initializing BK UI..."));
		#endif

		/***************************************
		 Menu - Diagnostics Items
		***************************************/
	
		/***************************************
		  Init Items
		***************************************/
		Menu_Main.setItems(A(Menu_Main_Items));
		Page_ManualMonitor.setItems(A(Page_Monitor_Items));
		Page_ClosedLoopMonitor.setItems(A(Page_ClosedLoopMonitor_Items));
		Menu_ClosedLoopControllersettings.setItems(A(Menu_ClosedLoopControllersettings_Items));
		Page_PWMMonitor.setItems(A(Page_PWMMonitor_Items));
		Page_Diag.setItems(A(Page_Diag_Items));
		Page_RTDs_BP.setItems(A(Page_RTDs_BP_Items));
		Page_RTDs_OP.setItems(A(Page_RTDs_OP_Items));

		
		/***************************************
		  Setup + Initialization
		***************************************/
		UI->attatchEncoder(&BK_ENC);
		UI->attatchLCD(&BK_LCD);
		UI->setUI(&Menu_Main);
	
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
			Serial.println(F("Done."));
		#endif
	}
}