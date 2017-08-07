/*
 *        File: MLT_UI.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: BK display user interface
 * ----------------------------------------------------------------
 *    Revision:
 *		01012015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "UI_MLT.h"

namespace UI_MLT{
	
	
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
		EZUI_Control_Label Lbl_Status(pTXT_Mlt,&MLT_Controller().Status);
		EZUI_Control_ToggleOption Tgl_Sol1Val(pTXT_Sol1,MLT_Controller().GasValve_Low);
		EZUI_Control_ToggleOption Tgl_Sol2Val(pTXT_Sol2,MLT_Controller().GasValve_High);
		EZUI_Control_Label Lbl_BPVal(pTXT_BP,&MLT_RTD_BP.degF);
		EZUI_Control_Label Lbl_OPVal(pTXT_OP,&MLT_RTD_OP.degF);
		EZUI_PageItems Page_Monitor_Items[] = {
			{  0,  0, 16, &Lbl_Status},
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
		EZUI_Control_Label Lbl_RTDs_MLT_BP_Vo(pTXT_Vo,&MLT_RTD_BP.Vo);
		EZUI_Control_Label Lbl_RTDs_MLT_BP_Vs(pTXT_Vs,&MLT_RTD_BP.Vs);
		EZUI_Control_Label Lbl_RTDs_MLT_BP_Rcalc(pTXT_Rcalc,&MLT_RTD_BP.Rcalc);
		EZUI_Control_Label Lbl_RTDs_MLT_BP_degC(pTXT_degC,&MLT_RTD_BP.degC);
		EZUI_Control_Label Lbl_RTDs_MLT_BP_degF(pTXT_degF,&MLT_RTD_BP.degF);

		EZUI_PageItems Page_RTDs_BP_Items[] = {
			{  0,  0, 11, &Lbl_RTDs_MLT_BP_Rcalc},
			{  12,  0, 7, &Lbl_RTDs_MLT_BP_Vo},
			{  1,  1, 11, &Lbl_RTDs_MLT_BP_degC},
			{  12,  1, 7, &Lbl_RTDs_MLT_BP_Vs},
			{  1,  2, 11, &Lbl_RTDs_MLT_BP_degF},
			{  0,  3, 4, &Lnk_Page_BackDiag}
		};

		/***************************************
		 Page - RTD - BK - OP	
		***************************************/
		EZUI_Page Page_RTDs_OP;
		EZUI_Control_Link Lnk_Page_RTDs_OP(pTXT_OP,&Page_RTDs_OP);
		EZUI_Control_Label Lbl_RTDs_MLT_OP_Vo(pTXT_Vo,&MLT_RTD_OP.Vo);
		EZUI_Control_Label Lbl_RTDs_MLT_OP_Vs(pTXT_Vs,&MLT_RTD_OP.Vs);
		EZUI_Control_Label Lbl_RTDs_MLT_OP_Rcalc(pTXT_Rcalc,&MLT_RTD_OP.Rcalc);
		EZUI_Control_Label Lbl_RTDs_MLT_OP_degC(pTXT_degC,&MLT_RTD_OP.degC);
		EZUI_Control_Label Lbl_RTDs_MLT_OP_degF(pTXT_degF,&MLT_RTD_OP.degF);

		EZUI_PageItems Page_RTDs_OP_Items[] = {
			{  0,  0, 11, &Lbl_RTDs_MLT_OP_Rcalc},
			{  12,  0, 7, &Lbl_RTDs_MLT_OP_Vo},
			{  1,  1, 11, &Lbl_RTDs_MLT_OP_degC},
			{  12,  1, 7, &Lbl_RTDs_MLT_OP_Vs},
			{  1,  2, 11, &Lbl_RTDs_MLT_OP_degF},
			{  0,  3, 4, &Lnk_Page_BackDiag}
		};
	
		
		/***************************************
		 Closed Loop Monitor Items
		***************************************/
		EZUI_Control_ListOption Lst_FBProbe(pTXT_PRB, &MLT_Controller().FeedbackProbe);
		EZUI_Control_AdjustParam Lst_Dmd(pTXT_DMD, MLT_Controller().SetTemp);
		EZUI_Control_Label Lbl_FBK(pTXT_FBK,&MLT_Controller().FeedbackTemp);
		EZUI_Control_Label LBL_Sol1(pTXT_Sol1,MLT_Controller().GasValve_Low);
		EZUI_Control_Label LBL_Sol2(pTXT_Sol2,MLT_Controller().GasValve_High);
	
		EZUI_PageItems Page_ClosedLoopMonitor_Items[] = {
			{  0,  0, 15, &Lbl_Status},
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
		EZUI_Control_ToggleOption Tgl_FltInhibit(pTXT_FltInhib, &MLT_Controller().enableFaultInhibit,pTXT_On_NoColon,pTXT_Off_NoColon);
		EZUI_Control_AdjustParam Adj_Demand(pTXT_Demand, MLT_Controller().SetTemp);
		EZUI_Control_AdjustParam Adj_HighOffset(pTXT_HighOffset, MLT_Controller().HighOffset);
		EZUI_Control_AdjustParam Adj_MedOffset(pTXT_MedOffset, MLT_Controller().MediumOffset);
		EZUI_Control_AdjustParam Adj_LowOffset(pTXT_LowOffset, MLT_Controller().LowOffset);
		EZUI_Control_AdjustParam Adj_Hysteresis(pTXT_Hystersis, MLT_Controller().Hysteresis);
		
		EZUI_MenuItems Menu_ClosedLoopControllersettings_Items[] = {
			{  &Tgl_FltInhibit },
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
		EZUI_PageItems Page_PWMMonitor_Items[] = {
			{  0,  0, 15, &Lbl_Status},
			{  0,  1, 10,  &Lst_FBProbe},
			{  11,  1, 9, &LBL_Sol1},
			{  0,  2, 9, &Lbl_FBK},
			{  11,  2, 9, &LBL_Sol2},
			{  0, 3, 3, &Lnk_Menu_PWMControllersettings },
			{  11,  3, 4, &Lnk_Menu_MainBack}
		};
		
		
		/***************************************
		 PWM Settings Menu
		***************************************/
		EZUI_Control_ListOption Lst_PwmMode(pTXT_PWMLevel_NoColon, &MLT_Controller().PWMLevel);
		EZUI_Control_AdjustParam Adj_PWMPeriod(pTXT_PWMPeriod_NoColon, MLT_Controller().PWMPeriod);
		EZUI_Control_AdjustParam Adj_PWMDuty(pTXT_PWMDuty_NoColon, MLT_Controller().PWMDutyCycle);
		
		EZUI_MenuItems Menu_PWMControllersettings_Items[] = {
			{  &Lst_PwmMode },
			{  &Adj_PWMPeriod },
			{  &Adj_PWMDuty },
			{  &Lnk_Page_PWMMonitorBack }
		};
	
	
		/***************************************
		 Main Diagnostics
		***************************************/
		EZUI_Control_Label Lbl_PilotStatus(pTXT_Pilot,&MLT_TC_ON,pTXT_On_NoColon,pTXT_Off_NoColon);
		EZUI_Control_Label Lbl_PilotVoltage(pTXT_V,&MLT_TC_V);
		EZUI_Control_Label Lbl_BPTemp(&MLT_RTD_BP.degF);
		EZUI_Control_Label Lbl_OPTemp(&MLT_RTD_OP.degF);
		
		EZUI_PageItems Page_Diag_Items[] = {
			{  0,  0, 15, &Lbl_Status},
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
		EZUI_Control_ListOption Lst_ControlMode(pTXT_Mode_NoColon,&MLT_Controller().Mode);
		EZUI_MenuItems Menu_Main_Items[] = {
			{  &Lst_ControlMode },
			{  &Lnk_Page_ManualMonitor },
			{  &Lnk_Page_ClosedLoopMonitor },
			{  &Lnk_Page_PWMMonitor },
			{  &Lnk_Page_Diag },
		};


	void UI_init(){
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
			Serial.print(F("Initializing MLT UI..."));
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
		Menu_PWMControllersettings.setItems(A(Menu_PWMControllersettings_Items));
		Page_Diag.setItems(A(Page_Diag_Items));
		Page_RTDs_BP.setItems(A(Page_RTDs_BP_Items));
		Page_RTDs_OP.setItems(A(Page_RTDs_OP_Items));

		
		/***************************************
		  Setup + Initialization
		***************************************/
		UI->attatchEncoder(&MLT_ENC);
		UI->attatchLCD(&MLT_LCD);
		UI->setUI(&Menu_Main);
	
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
			Serial.println(F("Done."));
		#endif
	}
}