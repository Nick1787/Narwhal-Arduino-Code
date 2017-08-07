/* 
* UI_Shared.cpp
*
* Created: 7/10/2016 11:30:40 AM
* Author: Customer
*/


#include "UI_Shared.h"


// SHARED TEXT in PROGMEM - Common Menu Link Labels
const PROGMEM char TXT_Empty[] = "";
__FlashStringHelper *pTXT_Empty = (__FlashStringHelper*)&TXT_Empty;


const PROGMEM char TXT_Back_NoColon[] = "Back";
__FlashStringHelper *pTXT_Back_NoColon = (__FlashStringHelper*)&TXT_Back_NoColon;

const PROGMEM char TXT_Diagnostics_NoColon[] = "Diagnostics";
__FlashStringHelper *pTXT_Diagnostics_NoColon = (__FlashStringHelper*)&TXT_Diagnostics_NoColon;

const PROGMEM char TXT_Monitor_NoColon[] = "Monitor";
__FlashStringHelper *pTXT_Monitor_NoColon = (__FlashStringHelper*)&TXT_Monitor_NoColon;

const PROGMEM char TXT_MonitorCL_NoColon[] = "Monitor-CL";
__FlashStringHelper *pTXT_MonitorCL_NoColon = (__FlashStringHelper*)&TXT_MonitorCL_NoColon;

const PROGMEM char TXT_MonitorManual_NoColon[] = "Monitor-Manual";
__FlashStringHelper *pTXT_MonitorManual_NoColon = (__FlashStringHelper*)&TXT_MonitorManual_NoColon;

const PROGMEM char TXT_MonitorPWM_NoColon[] = "Monitor-PWM";
__FlashStringHelper *pTXT_MonitorPWM_NoColon = (__FlashStringHelper*)&TXT_MonitorPWM_NoColon;

const PROGMEM char TXT_Set_NoColon[] = "Set";
__FlashStringHelper *pTXT_Set_NoColon= (__FlashStringHelper*)&TXT_Set_NoColon;

const PROGMEM char TXT_Settings_NoColon[] = "Settings";
__FlashStringHelper *pTXT_Settings_NoColon= (__FlashStringHelper*)&TXT_Settings_NoColon;

const PROGMEM char TXT_Alarms_NoColon[] = "Alarms";
__FlashStringHelper *pTXT_Alarms_NoColon= (__FlashStringHelper*)&TXT_Alarms_NoColon;

const PROGMEM char TXT_PilotLights_NoColon[] = "Pilot Lights";
__FlashStringHelper *pTXT_PilotLights_NoColon= (__FlashStringHelper*)&TXT_PilotLights_NoColon;

const PROGMEM char TXT_Clock_NoColon[] = "Clock";
__FlashStringHelper *pTXT_Clock_NoColon= (__FlashStringHelper*)&TXT_Clock_NoColon;

const PROGMEM char TXT_TCMonitor_NoColon[] = "TC Monitor";
__FlashStringHelper *pTXT_TCMonitor_NoColon= (__FlashStringHelper*)&TXT_TCMonitor_NoColon;

const PROGMEM char TXT_PumpMonitor_NoColon[] = "Pump Monitor";
__FlashStringHelper *pTXT_PumpMonitor_NoColon= (__FlashStringHelper*)&TXT_PumpMonitor_NoColon;

const PROGMEM char TXT_BurnerModes_NoColon[] = "Burner Modes";
__FlashStringHelper *pTXT_BurnerModes_NoColon= (__FlashStringHelper*)&TXT_BurnerModes_NoColon;

const PROGMEM char TXT_HLTMode_NoColon[] = "HLT Mode";
__FlashStringHelper *pTXT_HLTMode_NoColon= (__FlashStringHelper*)&TXT_HLTMode_NoColon;

const PROGMEM char TXT_HLTSol1_NoColon[] = "HLT Sol1";
__FlashStringHelper *pTXT_HLTSol1_NoColon= (__FlashStringHelper*)&TXT_HLTSol1_NoColon;

const PROGMEM char TXT_HLTSol2_NoColon[] = "HLT Sol2";
__FlashStringHelper *pTXT_HLTSol2_NoColon= (__FlashStringHelper*)&TXT_HLTSol2_NoColon;

const PROGMEM char TXT_MLTMode_NoColon[] = "MLT Mode";
__FlashStringHelper *pTXT_MLTMode_NoColon= (__FlashStringHelper*)&TXT_MLTMode_NoColon;

const PROGMEM char TXT_MLTSol1_NoColon[] = "HLT Sol1";
__FlashStringHelper *pTXT_MLTSol1_NoColon= (__FlashStringHelper*)&TXT_MLTSol1_NoColon;

const PROGMEM char TXT_MLTSol2_NoColon[] = "HLT Sol2";
__FlashStringHelper *pTXT_MLTSol2_NoColon= (__FlashStringHelper*)&TXT_MLTSol2_NoColon;

const PROGMEM char TXT_BKMode_NoColon[] = "BK Mode";
__FlashStringHelper *pTXT_BKMode_NoColon= (__FlashStringHelper*)&TXT_BKMode_NoColon;

const PROGMEM char TXT_BKSol1_NoColon[] = "HLT Sol1";
__FlashStringHelper *pTXT_BKSol1_NoColon= (__FlashStringHelper*)&TXT_BKSol1_NoColon;

const PROGMEM char TXT_BKSol2_NoColon[] = "HLT Sol2";
__FlashStringHelper *pTXT_BKSol2_NoColon= (__FlashStringHelper*)&TXT_BKSol2_NoColon;

//Main Monitor
const PROGMEM char TXT_Log[] = "Log:";
__FlashStringHelper *pTXT_Log= (__FlashStringHelper*)&TXT_Log;
const PROGMEM char TXT_T1[] = "T1:";
__FlashStringHelper *pTXT_T1= (__FlashStringHelper*)&TXT_T1;
const PROGMEM char TXT_Timer1[] = "Timer1:";
__FlashStringHelper *pTXT_Timer1= (__FlashStringHelper*)&TXT_Timer1;
const PROGMEM char TXT_T2[] = "T2:";
__FlashStringHelper *pTXT_T2= (__FlashStringHelper*)&TXT_T2;
const PROGMEM char TXT_Timer2[] = "Timer2:";
__FlashStringHelper *pTXT_Timer2= (__FlashStringHelper*)&TXT_Timer2;
const PROGMEM char TXT_Total[] = "Total:";
__FlashStringHelper *pTXT_Total= (__FlashStringHelper*)&TXT_Total;
const PROGMEM char TXT_Value[] = "Value:";
__FlashStringHelper *pTXT_Value= (__FlashStringHelper*)&TXT_Value;
const PROGMEM char TXT_Running_NoColon[] = "Running";
__FlashStringHelper *pTXT_Running_NoColon =(__FlashStringHelper*)&TXT_Running_NoColon;
const PROGMEM char TXT_Stopped_NoColon[] = "Stopped";
__FlashStringHelper *pTXT_Stopped_NoColon =(__FlashStringHelper*)&TXT_Stopped_NoColon;
const PROGMEM char TXT_On_NoColon[] = "On";
__FlashStringHelper *pTXT_On_NoColon =(__FlashStringHelper*)&TXT_On_NoColon;
const PROGMEM char TXT_Off_NoColon[] = "Off";
__FlashStringHelper *pTXT_Off_NoColon =(__FlashStringHelper*)&TXT_Off_NoColon;
const PROGMEM char TXT_Start[] = "Start";
__FlashStringHelper *pTXT_Start =(__FlashStringHelper*)&TXT_Start;
const PROGMEM char TXT_Stop[] = "Stop";
__FlashStringHelper *pTXT_Stop =(__FlashStringHelper*)&TXT_Stop;
const PROGMEM char TXT_Reset[] = "Reset";
__FlashStringHelper *pTXT_Reset =(__FlashStringHelper*)&TXT_Reset;



// Shared Labels
const PROGMEM char TXT_Sts[] = "Sts:";
__FlashStringHelper *pTXT_Sts = (__FlashStringHelper*)&TXT_Sts;

const PROGMEM char TXT_Hlt[] = "HLT:";
__FlashStringHelper *pTXT_Hlt = (__FlashStringHelper*)&TXT_Hlt;

const PROGMEM char TXT_Mlt[] = "MLT:";
__FlashStringHelper *pTXT_Mlt = (__FlashStringHelper*)&TXT_Mlt;

const PROGMEM char TXT_Bk[] = "BK:";
__FlashStringHelper *pTXT_Bk = (__FlashStringHelper*)&TXT_Bk;

EZUI_Control_Label Shared_Lbl_Sts(pTXT_Sts);
EZUI_Control_Label Shared_Lbl_HLT(pTXT_Hlt);
EZUI_Control_Label Shared_Lbl_MLT(pTXT_Mlt);
EZUI_Control_Label Shared_Lbl_BK(pTXT_Bk);

//Pilot Lights

const PROGMEM char TXT_Pilot[] = "Pilot:";
__FlashStringHelper *pTXT_Pilot = (__FlashStringHelper*)&TXT_Pilot;

const PROGMEM char TXT_Pilot1[] = "Pilot#1:";
__FlashStringHelper *pTXT_Pilot1 = (__FlashStringHelper*)&TXT_Pilot1;

const PROGMEM char TXT_Pilot2[] = "Pilot#2:";
__FlashStringHelper *pTXT_Pilot2 = (__FlashStringHelper*)&TXT_Pilot2;

const PROGMEM char TXT_Pilot3[] = "Pilot#3:";
__FlashStringHelper *pTXT_Pilot3 = (__FlashStringHelper*)&TXT_Pilot3;



//Pumps

const PROGMEM char TXT_Pump1[] = "Pump#1:";
__FlashStringHelper *pTXT_Pump1 = (__FlashStringHelper*)&TXT_Pump1;

const PROGMEM char TXT_Pump2[] = "Pump#1:";
__FlashStringHelper *pTXT_Pump2 = (__FlashStringHelper*)&TXT_Pump2;


//Alarms

const PROGMEM char TXT_Alarm1[] = "Alarm#1:";
__FlashStringHelper *pTXT_Alarm1 = (__FlashStringHelper*)&TXT_Alarm1;


const PROGMEM char TXT_Alarm2[] = "Alarm#2:";
__FlashStringHelper *pTXT_Alarm2 = (__FlashStringHelper*)&TXT_Alarm2;


//Clock


const PROGMEM char TXT_Day[] = "Day:";
__FlashStringHelper *pTXT_Day = (__FlashStringHelper*)&TXT_Day;

const PROGMEM char TXT_Month[] = "Month:";
__FlashStringHelper *pTXT_Month = (__FlashStringHelper*)&TXT_Month;

const PROGMEM char TXT_Year[] = "Year:";
__FlashStringHelper *pTXT_Year = (__FlashStringHelper*)&TXT_Year;

const PROGMEM char TXT_Sec[] = "Sec:";
__FlashStringHelper *pTXT_Sec = (__FlashStringHelper*)&TXT_Sec;

const PROGMEM char TXT_Min[] = "Min:";
__FlashStringHelper *pTXT_Min = (__FlashStringHelper*)&TXT_Min;

const PROGMEM char TXT_Hour[] = "Hour:";
__FlashStringHelper *pTXT_Hour = (__FlashStringHelper*)&TXT_Hour;



//RTD + Solenoids

const PROGMEM char TXT_Sol1[] = "Sol#1:";
__FlashStringHelper *pTXT_Sol1 = (__FlashStringHelper*)&TXT_Sol1;

const PROGMEM char TXT_Sol2[] = "Sol#2:";
__FlashStringHelper *pTXT_Sol2 = (__FlashStringHelper*)&TXT_Sol2;

EZUI_Control_Label Shared_Lbl_Sol1(pTXT_Sol1);
EZUI_Control_Label Shared_Lbl_Sol2(pTXT_Sol2);


//Commmon Display Labels

const PROGMEM char TXT_BP[] = "BP:";
__FlashStringHelper *pTXT_BP = (__FlashStringHelper*)&TXT_BP;

const PROGMEM char TXT_OP[] = "OP:";
__FlashStringHelper *pTXT_OP = (__FlashStringHelper*)&TXT_OP;

const PROGMEM char TXT_PL[] = "PL:";
__FlashStringHelper *pTXT_PL = (__FlashStringHelper*)&TXT_PL;

const PROGMEM char TXT_V[] = "V:";
__FlashStringHelper *pTXT_V = (__FlashStringHelper*)&TXT_V;

const PROGMEM char TXT_Vo[] = "Vo:";
__FlashStringHelper *pTXT_Vo= (__FlashStringHelper*)&TXT_Vo;

const PROGMEM char TXT_Vs[] = "Vs:";
__FlashStringHelper *pTXT_Vs = (__FlashStringHelper*)&TXT_Vs;

const PROGMEM char TXT_R[] = "R:";
__FlashStringHelper *pTXT_R = (__FlashStringHelper*)&TXT_R;

const PROGMEM char TXT_Rcalc[] = "Rcalc:";
__FlashStringHelper *pTXT_Rcalc = (__FlashStringHelper*)&TXT_Rcalc;

const PROGMEM char TXT_dC[] = "dC:";
__FlashStringHelper *pTXT_dC = (__FlashStringHelper*)&TXT_dC;

const PROGMEM char TXT_dF[] = "dF:";
__FlashStringHelper *pTXT_dF = (__FlashStringHelper*)&TXT_dF;

const PROGMEM char TXT_degC[] = "degC:";
__FlashStringHelper *pTXT_degC = (__FlashStringHelper*)&TXT_degC;

const PROGMEM char TXT_degF[] = "degF:";
__FlashStringHelper *pTXT_degF = (__FlashStringHelper*)&TXT_degF;

EZUI_Control_Label Shared_Lbl_BP(pTXT_BP);
EZUI_Control_Label Shared_Lbl_OP(pTXT_OP);
EZUI_Control_Label Shared_Lbl_PL(pTXT_PL);
EZUI_Control_Label Shared_Lbl_V(pTXT_V);
EZUI_Control_Label Shared_Lbl_Vo(pTXT_Vo);
EZUI_Control_Label Shared_Lbl_Vs(pTXT_Vs);
EZUI_Control_Label Shared_Lbl_R(pTXT_R);
EZUI_Control_Label Shared_Lbl_dC(pTXT_dC);
EZUI_Control_Label Shared_Lbl_d(pTXT_dF);


//Commmon Display Labels

const PROGMEM char TXT_Mode_NoColon[] = "Mode";
__FlashStringHelper *pTXT_Mode_NoColon = (__FlashStringHelper*)&TXT_Mode_NoColon;

const PROGMEM char TXT_CTRL[] = "CTRL:";
__FlashStringHelper *pTXT_CTRL = (__FlashStringHelper*)&TXT_CTRL;

const PROGMEM char TXT_PRBE[] = "PRBE:";
__FlashStringHelper *pTXT_PRBE = (__FlashStringHelper*)&TXT_PRBE;

const PROGMEM char TXT_PRB[] = "PRB:";
__FlashStringHelper *pTXT_PRB = (__FlashStringHelper*)&TXT_PRB;

const PROGMEM char TXT_DMD[] = "DMD:";
__FlashStringHelper *pTXT_DMD = (__FlashStringHelper*)&TXT_DMD;

const PROGMEM char TXT_FBK[] = "FBK:";
__FlashStringHelper *pTXT_FBK = (__FlashStringHelper*)&TXT_FBK;

EZUI_Control_Label Shared_Lbl_CTRL(pTXT_CTRL);
EZUI_Control_Label Shared_Lbl_PRBE(pTXT_PRBE);
EZUI_Control_Label Shared_Lbl_DMD(pTXT_DMD);
EZUI_Control_Label Shared_Lbl_FBK(pTXT_FBK);

//Closed Loop Control

const PROGMEM char TXT_FltInhib[] = "FltInhib:";
__FlashStringHelper *pTXT_FltInhib = (__FlashStringHelper*)&TXT_FltInhib;
const PROGMEM char TXT_Demand[] = "Demand:";
__FlashStringHelper *pTXT_Demand = (__FlashStringHelper*)&TXT_Demand;
const PROGMEM char TXT_HighOffset[] = "HighOffset:";
__FlashStringHelper *pTXT_HighOffset = (__FlashStringHelper*)&TXT_HighOffset;
const PROGMEM char TXT_MedOffset[] = "MedOffset:";
__FlashStringHelper *pTXT_MedOffset = (__FlashStringHelper*)&TXT_MedOffset;
const PROGMEM char TXT_LowOffset[] = "LowOffset:";
__FlashStringHelper *pTXT_LowOffset = (__FlashStringHelper*)&TXT_LowOffset;
const PROGMEM char TXT_Hystersis[] = "Hystersis:";
__FlashStringHelper *pTXT_Hystersis = (__FlashStringHelper*)&TXT_Hystersis;


//PWM Control

const PROGMEM char TXT_PWMLevel_NoColon[] = "PWM Level";
__FlashStringHelper *pTXT_PWMLevel_NoColon = (__FlashStringHelper*)&TXT_PWMLevel_NoColon;

const PROGMEM char TXT_PWMPeriod_NoColon[] = "PWM Period";
__FlashStringHelper *pTXT_PWMPeriod_NoColon = (__FlashStringHelper*)&TXT_PWMPeriod_NoColon;

const PROGMEM char TXT_PWMDuty_NoColon[] = "PWM Duty";
__FlashStringHelper *pTXT_PWMDuty_NoColon = (__FlashStringHelper*)&TXT_PWMDuty_NoColon;



//Logger

const PROGMEM char TXT_File[] = "File:";
__FlashStringHelper *pTXT_File = (__FlashStringHelper*)&TXT_File;

const PROGMEM char TXT_Rate[] = "Rate:";
__FlashStringHelper *pTXT_Rate = (__FlashStringHelper*)&TXT_Rate;

const PROGMEM char TXT_Status[] = "Status:";
__FlashStringHelper *pTXT_Status = (__FlashStringHelper*)&TXT_Status;