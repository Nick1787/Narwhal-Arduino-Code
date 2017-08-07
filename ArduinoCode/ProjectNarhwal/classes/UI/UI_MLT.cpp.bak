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
	
	
	EZUI_Menu Menu_Main;
	EZUI_Control_Link Lnk_BackMainMenu("Back",&Menu_Main);
			
	void UI_init(){
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
			Serial.print(F("Initializing MLT UI..."));
		#endif

		/***************************************
		 Main Menu
		***************************************/

//EZUI_Menu * Menu_Main = new EZUI_Menu();
//EZUI_Control_Link Lnk_Menu_MainBack("Back",&Menu_Main);

		/***************************************
		 Page - Monitor - Manual Control
		***************************************
		EZUI_Page * Page_ManualMonitor = new EZUI_Page();
		EZUI_Control_Link * Lnk_Page_ManualMonitor = new EZUI_Control_Link("Monitor - Manual",Page_ManualMonitor);
		EZUI_Control_Link * Lnk_Page_ManualMonitorBack = new EZUI_Control_Link("Back",Page_ManualMonitor);

		/***************************************
		 Page - Monitor - Manual Control
		***************************************
		EZUI_Menu * Menu_ClosedLoopControllersettings = new EZUI_Menu;
		EZUI_Control_Link * Lnk_Menu_ClosedLoopControllersettings = new EZUI_Control_Link("Set",Menu_ClosedLoopControllersettings);
		EZUI_Control_Link * Lnk_Menu_ClosedLoopControllersettingsBack = new EZUI_Control_Link("Back",Menu_ClosedLoopControllersettings);
	
		/***************************************
		 Page - Monitor - Closed Loop Control
		***************************************
	
		EZUI_Page * Page_ClosedLoopMonitor = new EZUI_Page();
		EZUI_Control_Link * Lnk_Page_ClosedLoopMonitor = new EZUI_Control_Link("Monitor - CL",Page_ClosedLoopMonitor);
		EZUI_Control_Link * Lnk_Page_ClosedLoopMonitorBack = new EZUI_Control_Link("Back",Page_ClosedLoopMonitor);
	
		/***************************************
		 Page - Diagnostics
		***************************************
	
		EZUI_Page * Page_Diag = new EZUI_Page();
		EZUI_Control_Link * Lnk_Page_Diag = new EZUI_Control_Link(pTXT_Diagnostics_NoColon,Page_Diag);
		EZUI_Control_Link * Lnk_Page_BackDiag = new EZUI_Control_Link("Back",Page_Diag);
	
		/***************************************
		 Page - RTD - BK - BP
		***************************************
		EZUI_Page * Page_RTDs_BP = new EZUI_Page;
		EZUI_Control_Link * Lnk_Page_RTDs_BP = new EZUI_Control_Link("BP:",Page_RTDs_BP);
		EZUI_Control_Label * Lbl_RTDs_MLT_BP_Vo = new EZUI_Control_Label("Vo:",&MLT_RTD_BP.Vo);
		EZUI_Control_Label * Lbl_RTDs_MLT_BP_Vs = new EZUI_Control_Label("Vs:",&MLT_RTD_BP.Vs);
		EZUI_Control_Label * Lbl_RTDs_MLT_BP_Rcalc = new EZUI_Control_Label("Rcalc:",&MLT_RTD_BP.Rcalc);
		EZUI_Control_Label * Lbl_RTDs_MLT_BP_degC = new EZUI_Control_Label("degC:",&MLT_RTD_BP.degC);
		EZUI_Control_Label * Lbl_RTDs_MLT_BP_degF = new EZUI_Control_Label("degF:",&MLT_RTD_BP.degF);

		EZUI_PageItems Page_RTDs_BP_Items[] = {
			{  4,  0, 5, Lbl_RTDs_MLT_BP_Vo},
			{ 14,  0, 5, Lbl_RTDs_MLT_BP_Vs},
			{  4,  1, 5, Lbl_RTDs_MLT_BP_Rcalc},
			{ 14,  1, 5, Lbl_RTDs_MLT_BP_degC},
			{  4,  2, 5, Lbl_RTDs_MLT_BP_degF},
			{  0,  3, 4, Lnk_Page_BackDiag}
		};

		/***************************************
		 Page - RTD - BK - OP	
		***************************************
		EZUI_Page * Page_RTDs_OP = new EZUI_Page();
		EZUI_Control_Link * Lnk_Page_RTDs_OP = new EZUI_Control_Link("OP:",Page_RTDs_OP);
		EZUI_Control_Label * Lbl_RTDs_MLT_OP_Vo = new EZUI_Control_Label("Vo:",&MLT_RTD_OP.Vo);
		EZUI_Control_Label * Lbl_RTDs_MLT_OP_Vs = new EZUI_Control_Label("Vs:",&MLT_RTD_OP.Vs);
		EZUI_Control_Label * Lbl_RTDs_MLT_OP_Rcalc = new EZUI_Control_Label("Rcalc:",&MLT_RTD_OP.Rcalc);
		EZUI_Control_Label * Lbl_RTDs_MLT_OP_degC = new EZUI_Control_Label("degC:",&MLT_RTD_OP.degC);
		EZUI_Control_Label * Lbl_RTDs_MLT_OP_degF = new EZUI_Control_Label("degF:",&MLT_RTD_OP.degF);

		EZUI_PageItems Page_RTDs_OP_Items[] = {
			{  4,  0, 5, Lbl_RTDs_MLT_OP_Vo},
			{ 14,  0, 5, Lbl_RTDs_MLT_OP_Vs},
			{  4,  1, 5, Lbl_RTDs_MLT_OP_Rcalc},
			{ 14,  1, 5, Lbl_RTDs_MLT_OP_degC},
			{  4,  2, 5, Lbl_RTDs_MLT_OP_degF},
			{  0,  3, 4, Lnk_Page_BackDiag}
		};
	
	
		/***************************************
		 Manual Monitor Items
		***************************************
		EZUI_Control_Label * Lbl_Status = new EZUI_Control_Label("MLT:",&MLT_Controller().Status);
		EZUI_Control_ToggleOption * Tgl_Sol1Val = new EZUI_Control_ToggleOption("Sol#1:",MLT_Controller().GasValve_Low);
		EZUI_Control_ToggleOption * Tgl_Sol2Val = new EZUI_Control_ToggleOption("Sol#2:",MLT_Controller().GasValve_High);
		EZUI_Control_Label * Lbl_BPVal = new EZUI_Control_Label("degF:",&MLT_RTD_BP.degF);
		EZUI_Control_Label * Lbl_OPVal = new EZUI_Control_Label("degF:",&MLT_RTD_OP.degF);
		EZUI_PageItems Page_Monitor_Items[] = {
			{  4,  0, 16, Lbl_Status},
			{  0,  1, 6,  Tgl_Sol1Val},
			{  4,  2, 5,  Lbl_BPVal},
			{ 10,  1, 6,  Tgl_Sol2Val},
			{ 14,  2, 5,  Lbl_OPVal},
			{  0,  3, 4,  Lnk_Menu_MainBack}
		};
	
		/***************************************
		 Closed Loop Monitor Items
		***************************************
		EZUI_Control_ListOption * Lst_FBProbe = new EZUI_Control_ListOption("PRB:", &MLT_Controller().FeedbackProbe);
		EZUI_Control_Label * Lbl_FBProbe = new EZUI_Control_Label(&MLT_Controller().FeedbackProbe);
		EZUI_Control_AdjustParam * Lst_Dmd = new EZUI_Control_AdjustParam("DMD:", MLT_Controller().SetTemp);
		EZUI_Control_Label * Lbl_Dmd = new EZUI_Control_Label(&MLT_Controller().SetTemp->value);
		EZUI_Control_Label * Lbl_FBK = new EZUI_Control_Label(&MLT_Controller().FeedbackTemp);
	
		EZUI_PageItems Page_ClosedLoopMonitor_Items[] = {
			//{  0,  0, 4,  Shared_Lbl_BK},
			{  3,  0, 15, Lbl_Status},
			{  0,  1, 4,  Lst_FBProbe},
			{  5,  1, 5,  Lbl_FBProbe},
			{  0,  2, 4, Lst_Dmd},
			{  5,  2, 5, Lbl_Dmd},
			{  5,  3, 5, Lbl_FBK},
			//{  17, 1, 6, &Lbl_Sol1Val},
			//{  17, 2, 6, &Lbl_Sol2Val},
			{  10, 3, 3, Lnk_Menu_ClosedLoopControllersettings },
			{  15,  3, 4, Lnk_Menu_MainBack}
		};
	
	
		/***************************************
		 Closed Loop Settings Menu
		***************************************
		EZUI_Control_ToggleOption * Tgl_FltInhibit = new EZUI_Control_ToggleOption("FltInhib:", &MLT_Controller().enableFaultInhibit,"Off","On");
		EZUI_Control_AdjustParam * Adj_Demand = new EZUI_Control_AdjustParam("Demand:", MLT_Controller().SetTemp);
		EZUI_Control_AdjustParam * Adj_HighOffset = new EZUI_Control_AdjustParam("HighOffset:", MLT_Controller().HighOffset);
		EZUI_Control_AdjustParam * Adj_MedOffset = new EZUI_Control_AdjustParam("MedOffset:", MLT_Controller().MediumOffset);
		EZUI_Control_AdjustParam * Adj_LowOffset = new EZUI_Control_AdjustParam("LowOffset:", MLT_Controller().LowOffset);
		EZUI_Control_AdjustParam * Adj_Hysteresis = new EZUI_Control_AdjustParam("Hystersis:", MLT_Controller().Hysteresis);
	
	
		EZUI_MenuItems Menu_ClosedLoopControllersettings_Items[] = {
			{  Tgl_FltInhibit },
			{  Adj_Demand },
			{  Adj_HighOffset },
			{  Adj_MedOffset },
			{  Adj_LowOffset },
			{  Adj_Hysteresis },
			{  Lnk_Page_ClosedLoopMonitorBack }
		};
	
		/***************************************
		 Main Diagnostics
		***************************************
		EZUI_Control_Label * Lbl_PilotStatus = new EZUI_Control_Label(&MLT_TC_ON,"On","Off");
		EZUI_Control_Label * Lbl_PilotVoltage = new EZUI_Control_Label(&MLT_TC_V);
		
		EZUI_PageItems Page_Diag_Items[] = {
			{ 4,  0,  16, Lbl_Status},
			{ 5,  1,   3, Lbl_PilotStatus},
			{ 15,  1,  6, Lbl_PilotVoltage},
			{  1,  2,  3, Lnk_Page_RTDs_BP},
			{  5,  2,  5, Lbl_BPVal},
			{  11, 2,  3, Lnk_Page_RTDs_OP},
			{  15, 2,  5, Lbl_OPVal},
			{  1,  3,  4, Lnk_Menu_MainBack}
		};
	
		/***************************************
		 Menu - Main Menu Items
		***************************************
		EZUI_Control_ListOption * Lst_ControlMode = new EZUI_Control_ListOption("Mode",&MLT_Controller().Mode);
		EZUI_MenuItems Menu_Main_Items[] = {
			{  Lst_ControlMode },
			{  Lnk_Page_ManualMonitor },
			{  Lnk_Page_ClosedLoopMonitor },
			{  Lnk_Page_Diag },
		};

		/***************************************
		 Menu - Diagnostics Items
		***************************************
	
		/***************************************
		  Init Items
		***************************************
		Menu_Main->setItems(A(Menu_Main_Items));
		Page_ManualMonitor->setItems(A(Page_Monitor_Items));
		Page_ClosedLoopMonitor->setItems(A(Page_ClosedLoopMonitor_Items));
		Menu_ClosedLoopControllersettings->setItems(A(Menu_ClosedLoopControllersettings_Items));
		Page_Diag->setItems(A(Page_Diag_Items));
		Page_RTDs_BP->setItems(A(Page_RTDs_BP_Items));
		Page_RTDs_OP->setItems(A(Page_RTDs_OP_Items));

		
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