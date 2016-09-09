/* 
* UI_Shared.h
*
* Created: 7/10/2016 11:30:40 AM
* Author: Customer
*/


#ifndef __UI_SHARED_H__
#define __UI_SHARED_H__

#include "../EZUI/EZUI.h"
#include "../EZUI/EZUI_Menu.h"
#include "../EZUI/EZUI_Page.h"
#include "../EZUI/Controls/EZUI_Control.h"

class EZUI_Control_Label;

//Each Kettle Name
extern EZUI_Control_Label Shared_Lbl_HLT;
extern EZUI_Control_Label Shared_Lbl_MLT;
extern EZUI_Control_Label Shared_Lbl_BK;
	
//RTD + Solenoids
extern EZUI_Control_Label Shared_Lbl_Sol1;
extern EZUI_Control_Label Shared_Lbl_Sol2;
extern EZUI_Control_Label Shared_Lbl_BP;
extern EZUI_Control_Label Shared_Lbl_OP;
	
	
//Commmon Display Labels
extern EZUI_Control_Label Shared_Lbl_V;
extern EZUI_Control_Label Shared_Lbl_Vo;
extern EZUI_Control_Label Shared_Lbl_Vs;
extern EZUI_Control_Label Shared_Lbl_R;
extern EZUI_Control_Label Shared_Lbl_dC;
extern EZUI_Control_Label Shared_Lbl_dF;


#endif //__UI_SHARED_H__
