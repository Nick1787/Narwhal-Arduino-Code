/*
 *        File: HLT_UI.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: HLT display user interface
 * ----------------------------------------------------------------
 *    Revision:
 *		01012015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "UI_HLT.h"

namespace UI_HLT{
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
	 Page - RTD - HLT - BP
	***************************************/
	EZUI_Page Page_RTDs_BP;
	EZUI_Control_Link Lnk_Page_RTDs_BP("BP:",&Page_RTDs_BP);
	EZUI_Control_Label Lbl_RTDs_HLT_BP_Vo(&HLT_RTD_BP.Vo);
	EZUI_Control_Label Lbl_RTDs_HLT_BP_Vs(&HLT_RTD_BP.Vs);
	EZUI_Control_Label Lbl_RTDs_HLT_BP_Rcalc(&HLT_RTD_BP.Rcalc);
	EZUI_Control_Label Lbl_RTDs_HLT_BP_degC(&HLT_RTD_BP.degC);
	EZUI_Control_Label Lbl_RTDs_HLT_BP_degF(&HLT_RTD_BP.degF);

	PageItem Page_RTDs_BP_Items[] = {
		{  1,  0, 4, &Shared_Lbl_Vo},
		{  4,  0, 5, &Lbl_RTDs_HLT_BP_Vo},
		{ 11,  0, 4, &Shared_Lbl_Vs},
		{ 14,  0, 5, &Lbl_RTDs_HLT_BP_Vs},
		{  2,  1, 4, &Shared_Lbl_R},
		{  4,  1, 5, &Lbl_RTDs_HLT_BP_Rcalc},
		{ 11,  1, 4, &Shared_Lbl_dC},
		{ 14,  1, 5, &Lbl_RTDs_HLT_BP_degC},
		{  1,  2, 4, &Shared_Lbl_dF},
		{  4,  2, 5, &Lbl_RTDs_HLT_BP_degF},
		{  0,  3, 4, &Lnk_Page_BackDiag}
	};

	/***************************************
	 Page - RTD - HLT - OP	
	***************************************/
	EZUI_Page Page_RTDs_OP;
	EZUI_Control_Link Lnk_Page_RTDs_OP("OP:",&Page_RTDs_OP);
	EZUI_Control_Label Lbl_RTDs_HLT_OP_Vo(&HLT_RTD_OP.Vo);
	EZUI_Control_Label Lbl_RTDs_HLT_OP_Vs(&HLT_RTD_OP.Vs);
	EZUI_Control_Label Lbl_RTDs_HLT_OP_Rcalc(&HLT_RTD_OP.Rcalc);
	EZUI_Control_Label Lbl_RTDs_HLT_OP_degC(&HLT_RTD_OP.degC);
	EZUI_Control_Label Lbl_RTDs_HLT_OP_degF(&HLT_RTD_OP.degF);

	PageItem Page_RTDs_OP_Items[] = {
		{  1,  0, 4, &Shared_Lbl_Vo},
		{  4,  0, 5, &Lbl_RTDs_HLT_OP_Vo},
		{ 11,  0, 4, &Shared_Lbl_Vs},
		{ 14,  0, 5, &Lbl_RTDs_HLT_OP_Vs},
		{  2,  1, 4, &Shared_Lbl_R},
		{  4,  1, 5, &Lbl_RTDs_HLT_OP_Rcalc},
		{ 11,  1, 4, &Shared_Lbl_dC},
		{ 14,  1, 5, &Lbl_RTDs_HLT_OP_degC},
		{  1,  2, 4, &Shared_Lbl_dF},
		{  4,  2, 5, &Lbl_RTDs_HLT_OP_degF},
		{  0,  3, 4, &Lnk_Page_BackDiag}
	};
	
	
	/***************************************
	 Manual Monitor Items
	***************************************/
	EZUI_Control_Label Lbl_Status(&HLT_Controller().Status);
	EZUI_Control_ToggleOption Tgl_Sol1Val("Sol#1:",HLT_Controller().GasValve1);
	EZUI_Control_Label Lbl_Sol1Val(HLT_Controller().GasValve1);
	EZUI_Control_ToggleOption Tgl_Sol2Val("Sol#2:",HLT_Controller().GasValve2);
	EZUI_Control_Label Lbl_Sol2Val(HLT_Controller().GasValve2);
	EZUI_Control_Label Lbl_BPVal(&HLT_RTD_BP.degF);
	EZUI_Control_Label Lbl_OPVal(&HLT_RTD_OP.degF);
	PageItem Page_Monitor_Items[] = {
		{ 0,  0, 4, &Shared_Lbl_HLT},
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
	EZUI_Control_ListOption Lst_FBProbe("PRB:", &HLT_Controller().FeedbackProbe);
	EZUI_Control_Label Lbl_FBProbe(&HLT_Controller().FeedbackProbe);
	EZUI_Control_AdjustParam Lst_Dmd("DMD:", HLT_Controller().SetTemp);
	EZUI_Control_Label Lbl_Dmd(&HLT_Controller().SetTemp->value);
	EZUI_Control_Label Lbl_FBK(&HLT_Controller().TProbe1->degF);
	
	PageItem Page_ClosedLoopMonitor_Items[] = {
		{  0,  0, 4,  &Shared_Lbl_HLT},
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
	EZUI_Control_Label Lbl_PilotStatus(&HLT_TC_ON,"On","Off");
	EZUI_Control_Label Lbl_PilotVoltage(&HLT_TC_V);
		
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
	EZUI_Control_ListOption Lst_ControlMode("Mode",&HLT_Controller().Mode);
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
			Serial.print(F("Initializing HLT UI..."));
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
		UI->attatchEncoder(&HLT_ENC);
		UI->attatchLCD(&HLT_LCD);
		UI->setDisplay(&Menu_Main);
	
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
			Serial.println(F("Done."));
		#endif
	}
}