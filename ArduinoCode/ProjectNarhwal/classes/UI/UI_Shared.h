/* 
* UI_Shared.h
*
* Created: 7/10/2016 11:30:40 AM
* Author: Customer
*/


#ifndef __UI_SHARED_H__
#define __UI_SHARED_H__

//Includes
#include "../../Main.h"

class EZUI_Control_Label;

//Shared Text
extern __FlashStringHelper *pTXT_Empty;
extern __FlashStringHelper *pTXT_Back_NoColon;
extern __FlashStringHelper *pTXT_Diagnostics_NoColon;
extern __FlashStringHelper *pTXT_Monitor_NoColon;
extern __FlashStringHelper *pTXT_MonitorCL_NoColon;
extern __FlashStringHelper *pTXT_MonitorPWM_NoColon;
extern __FlashStringHelper *pTXT_MonitorManual_NoColon;
extern __FlashStringHelper *pTXT_Set_NoColon;
extern __FlashStringHelper *pTXT_Settings_NoColon;
extern __FlashStringHelper *pTXT_Alarms_NoColon;
extern __FlashStringHelper *pTXT_PilotLights_NoColon;
extern __FlashStringHelper *pTXT_Clock_NoColon;
extern __FlashStringHelper *pTXT_RtdProbes_NoColon;
extern __FlashStringHelper *pTXT_TCMonitor_NoColon;
extern __FlashStringHelper *pTXT_Pilots_NoColon;
extern __FlashStringHelper *pTXT_PumpMonitor_NoColon;
extern __FlashStringHelper *pTXT_BurnerModes_NoColon;
extern __FlashStringHelper *pTXT_HLTMode_NoColon;
extern __FlashStringHelper *pTXT_HLTSol1_NoColon;
extern __FlashStringHelper *pTXT_HLTSol2_NoColon;
extern __FlashStringHelper *pTXT_MLTMode_NoColon;
extern __FlashStringHelper *pTXT_MLTSol1_NoColon;
extern __FlashStringHelper *pTXT_MLTSol2_NoColon;
extern __FlashStringHelper *pTXT_BKMode_NoColon;
extern __FlashStringHelper *pTXT_BKSol1_NoColon;
extern __FlashStringHelper *pTXT_BKSol2_NoColon;


//Each Kettle Name
extern __FlashStringHelper *pTXT_Hlt;
extern __FlashStringHelper *pTXT_Mlt;
extern __FlashStringHelper *pTXT_Bk;

extern EZUI_Control_Label Shared_Lbl_HLT;
extern EZUI_Control_Label Shared_Lbl_MLT;
extern EZUI_Control_Label Shared_Lbl_BK;
	
//Pilot Lights
extern __FlashStringHelper *pTXT_Mode_NoColon;
extern __FlashStringHelper *pTXT_Pilot;
extern __FlashStringHelper *pTXT_Pilot1;
extern __FlashStringHelper *pTXT_Pilot2;
extern __FlashStringHelper *pTXT_Pilot3;


//Pumps
extern __FlashStringHelper *pTXT_Pump1;
extern __FlashStringHelper *pTXT_Pump2;

//Alarms
extern __FlashStringHelper *pTXT_Alarm1;
extern __FlashStringHelper *pTXT_Alarm2;

//Clock
extern __FlashStringHelper *pTXT_Day;
extern __FlashStringHelper *pTXT_Month;
extern __FlashStringHelper *pTXT_Year;
extern __FlashStringHelper *pTXT_Sec;
extern __FlashStringHelper *pTXT_Min;
extern __FlashStringHelper *pTXT_Hour;

//RTD + Solenoids

extern __FlashStringHelper *pTXT_Sol1;
extern __FlashStringHelper *pTXT_Sol2;
extern __FlashStringHelper *pTXT_BP;
extern __FlashStringHelper *pTXT_OP;

extern __FlashStringHelper *pTXT_HLTBP;
extern __FlashStringHelper *pTXT_HLTOP;
extern __FlashStringHelper *pTXT_MLTBP;
extern __FlashStringHelper *pTXT_MLTOP;
extern __FlashStringHelper *pTXT_BKBP;
extern __FlashStringHelper *pTXT_BKOP;

extern EZUI_Control_Label Shared_Lbl_Sol1;
extern EZUI_Control_Label Shared_Lbl_Sol2;
extern EZUI_Control_Label Shared_Lbl_BP;
extern EZUI_Control_Label Shared_Lbl_OP;
	
	
//Commmon Display Labels

extern __FlashStringHelper *pTXT_Sts;
extern __FlashStringHelper *pTXT_PL;
extern __FlashStringHelper *pTXT_V;
extern __FlashStringHelper *pTXT_Vo;
extern __FlashStringHelper *pTXT_Vs;
extern __FlashStringHelper *pTXT_R;
extern __FlashStringHelper *pTXT_Rcalc;
extern __FlashStringHelper *pTXT_dC;
extern __FlashStringHelper *pTXT_dF;
extern __FlashStringHelper *pTXT_degC;
extern __FlashStringHelper *pTXT_degF;
extern __FlashStringHelper *pTXT_CTRL;
extern __FlashStringHelper *pTXT_PRBE;
extern __FlashStringHelper *pTXT_PRB;
extern __FlashStringHelper *pTXT_DMD;
extern __FlashStringHelper *pTXT_FBK;

extern EZUI_Control_Label Shared_Lbl_Sts;
extern EZUI_Control_Label Shared_Lbl_PL;
extern EZUI_Control_Label Shared_Lbl_V;
extern EZUI_Control_Label Shared_Lbl_Vo;
extern EZUI_Control_Label Shared_Lbl_Vs;
extern EZUI_Control_Label Shared_Lbl_R;
extern EZUI_Control_Label Shared_Lbl_dC;
extern EZUI_Control_Label Shared_Lbl_dF;

extern EZUI_Control_Label Shared_Lbl_CTRL;
extern EZUI_Control_Label Shared_Lbl_PRBE;
extern EZUI_Control_Label Shared_Lbl_DMD;
extern EZUI_Control_Label Shared_Lbl_FBK;


//Main Monitor
extern __FlashStringHelper *pTXT_Log;
extern __FlashStringHelper *pTXT_T1;
extern __FlashStringHelper *pTXT_Timer1;
extern __FlashStringHelper *pTXT_T2;
extern __FlashStringHelper *pTXT_Timer2;
extern __FlashStringHelper *pTXT_Running_NoColon;
extern __FlashStringHelper *pTXT_Stopped_NoColon;
extern __FlashStringHelper *pTXT_On_NoColon;
extern __FlashStringHelper *pTXT_Off_NoColon;
extern __FlashStringHelper *pTXT_Total;
extern __FlashStringHelper *pTXT_Value;
extern __FlashStringHelper *pTXT_Start;
extern __FlashStringHelper *pTXT_Stop;
extern __FlashStringHelper *pTXT_Reset;

//Closed Loop Control

extern __FlashStringHelper *pTXT_FaultInhibit_NoColon;
extern __FlashStringHelper *pTXT_FltInhib;
extern __FlashStringHelper *pTXT_Demand;
extern __FlashStringHelper *pTXT_HighOffset;
extern __FlashStringHelper *pTXT_MedOffset;
extern __FlashStringHelper *pTXT_LowOffset;
extern __FlashStringHelper *pTXT_Hystersis;

//PWM Control

extern __FlashStringHelper *pTXT_PWMLevel_NoColon;
extern __FlashStringHelper *pTXT_PWMPeriod_NoColon;
extern __FlashStringHelper *pTXT_PWMDuty_NoColon;

//Logger
extern __FlashStringHelper *pTXT_File;
extern __FlashStringHelper *pTXT_Rate;
extern __FlashStringHelper *pTXT_Status;

#endif //__UI_SHARED_H__
