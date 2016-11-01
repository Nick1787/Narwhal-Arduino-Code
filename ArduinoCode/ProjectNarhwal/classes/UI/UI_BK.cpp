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
#include "../EZUI/EZUI.h"
#include "../EZUI/EZUI_Display.h"
#include "../EZUI/Controls/EZUI_Control_AdjustParam.h"
#include "../EZUI/Controls/EZUI_Control_Button.h"
#include "../EZUI/Controls/EZUI_Control_Label.h"
#include "../EZUI/Controls/EZUI_Control_Link.h"
#include "../EZUI/Controls/EZUI_Control_ListOption.h"
#include "../EZUI/Controls/EZUI_Control_ToggleOption.h"

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
	EZUI_Control_Link Lnk_Page_ManualMonitor("Monitor - Manual Control",&Page_ManualMonitor);
	EZUI_Control_Link Lnk_Page_ManualMonitorBack("Back",&Page_ManualMonitor);

	/***************************************
	 Page - Monitor - Closed Loop Control
	***************************************/
	EZUI_Page Page_ClosedLoopMonitor;
	EZUI_Control_Link Lnk_Page_ClosedLoopMonitor("Monitor - Manual Control",&Page_ClosedLoopMonitor);
	EZUI_Control_Link Lnk_Page_ClosedLoopMonitorBack("Back",&Page_ClosedLoopMonitor);
	
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
		{  0,  3, 4, &Lnk_Page_ManualMonitorBack}
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
		{  0,  3, 4, &Lnk_Page_ManualMonitorBack}
	};
	
	
	/***************************************
	 Manual Monitor Items
	***************************************/
	EZUI_Control_ToggleOption Tgl_Sol1Val("Sol#1:",BK_SOL1);
	EZUI_Control_Label Lbl_Sol1Val(BK_SOL1);
	EZUI_Control_ToggleOption Tgl_Sol2Val("Sol#2:",BK_SOL2);
	EZUI_Control_Label Lbl_Sol2Val(BK_SOL2);
	EZUI_Control_Label Lbl_BPVal(&BK_RTD_BP.degF);
	EZUI_Control_Label Lbl_OPVal(&BK_RTD_OP.degF);
	PageItem Page_Monitor_Items[] = {
		{ 0,  0, 20, &Shared_Lbl_BK},
		{ 0,  1, 6, &Tgl_Sol1Val},
		{ 7,  1, 3, &Lbl_Sol1Val},
		{  0,  2, 3, &Lnk_Page_RTDs_BP},
		{  4,  2, 5, &Lbl_BPVal},
		{  0, 3, 4, &Lnk_Menu_MainBack},
		{ 10,  1, 6, &Tgl_Sol2Val},
		{ 17,  1, 3, &Lbl_Sol2Val},
		{ 10,  2, 3, &Lnk_Page_RTDs_OP},
		{ 14,  2, 5, &Lbl_OPVal}
	};
	
	/***************************************
	 Closed Loop Monitor Items
	***************************************/
	EZUI_Control_Label Lbl_BK_Status(&BK_Controller.Status);
	EZUI_Control_ListOption Lst_BK_FBProbe("PRBE:", &BK_Controller.FeedbackProbe);
	EZUI_Control_Label Lbl_BK_FBProbe(&BK_Controller.FeedbackProbe);
	EZUI_Control_AdjustParam Lst_BK_Dmd("DMD:", BK_Controller.SetTemp);
	EZUI_Control_Label Lbl_BK_Dmd(BK_Controller.SetTemp);
	EZUI_Control_Label Lst_BK_FBK(&BK_Controller.TProbe1->degF);
	
	PageItem Page_ClosedLoopMonitor_Items[] = {
		{  0,  0, 4,  &Shared_Lbl_BK},
		{  5,  0, 15, &Lbl_BK_Status},
		{  0,  2, 4,  &Lst_BK_FBProbe},
		{  13,  1, 4, &Lst_BK_Dmd},
		{  17,  1, 3, &Lbl_BK_Dmd},
		{  13,  2, 3, &Shared_Lbl_FBK},
		{  17,  2, 3, &Lst_BK_FBK},
		{  13,  3, 4, &Lnk_Menu_MainBack}
	};
	/***************************************
	 Main Diagnostics
	***************************************/
	EZUI_Menu Menu_Diag;
	EZUI_Control_Link Lnk_Menu_Diag("Diagnostics",&Menu_Diag);
	EZUI_Control_Link Lnk_Menu_DiagBack("Back",&Menu_Diag);

	/***************************************
	 Menu - Main Menu Items
	***************************************/
	MenuItem Menu_Main_Items[] = {
		{  &Lnk_Page_ManualMonitor },
		{  &Lnk_Page_ClosedLoopMonitor },
		{  &Lnk_Menu_Diag },
	};

	/***************************************
	 Menu - Diagnostics Items
	***************************************/
	MenuItem Menu_Diag_Items[] = {
		{ &Lnk_Menu_MainBack}
	};
	
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
		Menu_Diag.setItems(A(Menu_Diag_Items));
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