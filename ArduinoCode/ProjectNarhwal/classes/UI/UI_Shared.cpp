/* 
* UI_Shared.cpp
*
* Created: 7/10/2016 11:30:40 AM
* Author: Customer
*/


#include "UI_Shared.h"
#include "../EZUI/Controls/EZUI_Control.h"
#include "../EZUI/Controls/EZUI_Control_Label.h"

EZUI_Control_Label Shared_Lbl_HLT("HLT:");
EZUI_Control_Label Shared_Lbl_MLT("MLT:");
EZUI_Control_Label Shared_Lbl_BK("BK:");

//RTD + Solenoids
EZUI_Control_Label Shared_Lbl_Sol1("Sol#1:");
EZUI_Control_Label Shared_Lbl_Sol2("Sol#2:");
EZUI_Control_Label Shared_Lbl_BP("BP:");
EZUI_Control_Label Shared_Lbl_OP("OP:");


//Commmon Display Labels
EZUI_Control_Label Shared_Lbl_V("V:");
EZUI_Control_Label Shared_Lbl_Vo("Vo:");
EZUI_Control_Label Shared_Lbl_Vs("Vs:");
EZUI_Control_Label Shared_Lbl_R("R:");
EZUI_Control_Label Shared_Lbl_dC("dC:");
EZUI_Control_Label Shared_Lbl_dF("dF:");