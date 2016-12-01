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
	//using namespace UI_SHARED;
	
	EZUI *UI  = new EZUI();

	/***************************************
	 Main Menu
	***************************************/
	EZUI_Menu Menu_Main;
	EZUI_Control_Link Lnk_Menu_MainBack("Back",&Menu_Main);

	/***************************************
	 Page - Monitor - Manual Control
	***************************************/
	EZUI_Page Page_ManualMonitor;
	EZUI_Control_Link Lnk_Page_ManualMonitor("Monitor - Manual",&Page_ManualMonitor);
	EZUI_Control_Link Lnk_Page_ManualMonitorBack("Back",&Page_ManualMonitor);

	/***************************************
	 Page - Monitor - Closed Loop Control
	***************************************/
	
	EZUI_Page Page_ClosedLoopMonitor;
	EZUI_Control_Link Lnk_Page_ClosedLoopMonitor("Monitor - CL",&Page_ClosedLoopMonitor);
	EZUI_Control_Link Lnk_Page_ClosedLoopMonitorBack("Back",&Page_ClosedLoopMonitor);
	
	/***************************************
	 Page - Diagnostics
	***************************************/
	
	EZUI_Page Page_Diag;
	EZUI_Control_Link Lnk_Page_Diag("Diagnostics",&Page_Diag);
	EZUI_Control_Link Lnk_Page_BackDiag("Back",&Page_Diag);
	
	/***************************************
	 Page - RTD - BK - BP
	***************************************/
	EZUI_Page Page_RTDs_BP;
	EZUI_Control_Link Lnk_Page_RTDs_BP("BP:",&Page_RTDs_BP);
	EZUI_Control_Label Lbl_RTDs_BK_BP_Vo(&BK_RTD_BP.Vo);
	EZUI_Control_Label Lbl_RTDs_BK_BP_Vs(&BK_RTD_BP.Vs);
	EZUI_Control_Label Lbl_RTDs_BK_BP_Rcalc(&BK_RTD_BP.Rcalc);
	EZUI_Control_Label Lbl_RTDs_BK_BP_degC(&BK_RTD_BP.degC);
	EZUI_Control_Label Lbl_RTDs_BK_BP_degF(&BK_RTD_BP.degF);

	PageItem Page_RTDs_BP_Items[] = {
		{  1,  0, 4, &Shared_Lbl_Vo},
		{  4,  0, 5, &Lbl_RTDs_BK_BP_Vo},
		{ 11,  0, 4, &Shared_Lbl_Vs},
		{ 14,  0, 5, &Lbl_RTDs_BK_BP_Vs},
		{  2,  1, 4, &Shared_Lbl_R},
		{  4,  1, 5, &Lbl_RTDs_BK_BP_Rcalc},
		{ 11,  1, 4, &Shared_Lbl_dC},
		{ 14,  1, 5, &Lbl_RTDs_BK_BP_degC},
		{  1,  2, 4, &Shared_Lbl_dF},
		{  4,  2, 5, &Lbl_RTDs_BK_BP_degF},
		{  0,  3, 4, &Lnk_Page_BackDiag}
	};

	/***************************************
	 Page - RTD - BK - OP	
	***************************************/
	EZUI_Page Page_RTDs_OP;
	EZUI_Control_Link Lnk_Page_RTDs_OP("OP:",&Page_RTDs_OP);
	EZUI_Control_Label Lbl_RTDs_BK_OP_Vo(&BK_RTD_OP.Vo);
	EZUI_Control_Label Lbl_RTDs_BK_OP_Vs(&BK_RTD_OP.Vs);
	EZUI_Control_Label Lbl_RTDs_BK_OP_Rcalc(&BK_RTD_OP.Rcalc);
	EZUI_Control_Label Lbl_RTDs_BK_OP_degC(&BK_RTD_OP.degC);
	EZUI_Control_Label Lbl_RTDs_BK_OP_degF(&BK_RTD_OP.degF);

	PageItem Page_RTDs_OP_Items[] = {
		{  1,  0, 4, &Shared_Lbl_Vo},
		{  4,  0, 5, &Lbl_RTDs_BK_OP_Vo},
		{ 11,  0, 4, &Shared_Lbl_Vs},
		{ 14,  0, 5, &Lbl_RTDs_BK_OP_Vs},
		{  2,  1, 4, &Shared_Lbl_R},
		{  4,  1, 5, &Lbl_RTDs_BK_OP_Rcalc},
		{ 11,  1, 4, &Shared_Lbl_dC},
		{ 14,  1, 5, &Lbl_RTDs_BK_OP_degC},
		{  1,  2, 4, &Shared_Lbl_dF},
		{  4,  2, 5, &Lbl_RTDs_BK_OP_degF},
		{  0,  3, 4, &Lnk_Page_BackDiag}
	};
	
	
	/***************************************
	 Manual Monitor Items
	***************************************/
	EZUI_Control_Label Lbl_Status(&BK_Controller().Status);
	EZUI_Control_ToggleOption Tgl_Sol1Val("Sol#1:",BK_Controller().GasValve1);
	EZUI_Control_Label Lbl_Sol1Val(BK_Controller().GasValve1);
	EZUI_Control_ToggleOption Tgl_Sol2Val("Sol#2:",BK_Controller().GasValve2);
	EZUI_Control_Label Lbl_Sol2Val(BK_Controller().GasValve2);
	EZUI_Control_Label Lbl_BPVal(&BK_RTD_BP.degF);
	EZUI_Control_Label Lbl_OPVal(&BK_RTD_OP.degF);
	PageItem Page_Monitor_Items[] = {
		{ 0,  0, 4, &Shared_Lbl_BK},
		{ 4,  0, 16, &Lbl_Status},
		{ 0,  1, 6, &Tgl_Sol1Val},
		{ 7,  1, 3, &Lbl_Sol1Val},
		{  1,  2, 3, &Shared_Lbl_BP},
		{  4,  2, 5, &Lbl_BPVal},
		{ 10,  1, 6, &Tgl_Sol2Val},
		{ 17,  1, 3, &Lbl_Sol2Val},
		{ 11,  2, 3, &Shared_Lbl_OP},
		{ 14,  2, 5, &Lbl_OPVal},
		{  0, 3, 4, &Lnk_Menu_MainBack}
	};
	
	/***************************************
	 Closed Loop Monitor Items
	***************************************/
	EZUI_Control_ListOption Lst_FBProbe("PRB:", &BK_Controller().FeedbackProbe);
	EZUI_Control_Label Lbl_FBProbe(&BK_Controller().FeedbackProbe);
	EZUI_Control_AdjustParam Lst_Dmd("DMD:", BK_Controller().SetTemp);
	EZUI_Control_Label Lbl_Dmd(&BK_Controller().SetTemp->value);
	EZUI_Control_Label Lbl_FBK(&BK_Controller().TProbe1->degF);
	
	PageItem Page_ClosedLoopMonitor_Items[] = {
		{  0,  0, 4,  &Shared_Lbl_BK},
		{  3,  0, 15, &Lbl_Status},
		{  0,  1, 4,  &Lst_FBProbe},
		{  5,  1, 5,  &Lbl_FBProbe},
		{  0,  2, 4, &Lst_Dmd},
		{  5,  2, 5, &Lbl_Dmd},
		{  1,  3, 4, &Shared_Lbl_FBK},
		{  5,  3, 5, &Lbl_FBK},
		{  11, 1, 6, &Shared_Lbl_Sol1},
		{  17, 1, 6, &Lbl_Sol1Val},
		{  11, 2, 6, &Shared_Lbl_Sol2},
		{  17, 2, 6, &Lbl_Sol2Val},
		{  13,  3, 4, &Lnk_Menu_MainBack}
	};
	
	/***************************************
	 Main Diagnostics
	***************************************/
	EZUI_Control_Label Lbl_PilotStatus(&BK_TC_ON,"On","Off");
	EZUI_Control_Label Lbl_PilotVoltage(&BK_TC_V);
		
	PageItem Page_Diag_Items[] = {
		{ 0,  0,   4, &Shared_Lbl_Sts},
		{ 4,  0,  16, &Lbl_Status},
		{ 2,  1,   3, &Shared_Lbl_PL},
		{ 5,  1,   3, &Lbl_PilotStatus},
		{ 13,  1,  2, &Shared_Lbl_V},
		{ 15,  1,  6, &Lbl_PilotVoltage},
		{  1,  2,  3, &Lnk_Page_RTDs_BP},
		{  5,  2,  5, &Lbl_BPVal},
		{  11, 2,  3, &Lnk_Page_RTDs_OP},
		{  15, 2,  5, &Lbl_OPVal},
		{  1,  3,  4, &Lnk_Menu_MainBack}
	};
	
	/***************************************
	 Menu - Main Menu Items
	***************************************/
	EZUI_Control_ListOption Lst_ControlMode("Mode",&BK_Controller().Mode);
	MenuItem Menu_Main_Items[] = {
		{  &Lst_ControlMode },
		{  &Lnk_Page_ManualMonitor },
		{  &Lnk_Page_ClosedLoopMonitor },
		{  &Lnk_Page_Diag },
	};

	/***************************************
	 Menu - Diagnostics Items
	***************************************/

	
	void UI_init(){
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
			Serial.print(F("Initializing BK UI..."));
		#endif
	
		/***************************************
		  Init Items
		***************************************/
		Menu_Main.setItems(A(Menu_Main_Items));
		Page_ManualMonitor.setItems(A(Page_Monitor_Items));
		Page_ClosedLoopMonitor.setItems(A(Page_ClosedLoopMonitor_Items));
		Page_Diag.setItems(A(Page_Diag_Items));
		Page_RTDs_BP.setItems(A(Page_RTDs_BP_Items));
		Page_RTDs_OP.setItems(A(Page_RTDs_OP_Items));
	
		/***************************************
		  Setup + Initialization
		***************************************/
		UI->attatchEncoder(&BK_ENC);
		UI->attatchLCD(&BK_LCD);
		UI->setDisplay(&Menu_Main);
	
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
			Serial.println(F("Done."));
		#endif
	}
}