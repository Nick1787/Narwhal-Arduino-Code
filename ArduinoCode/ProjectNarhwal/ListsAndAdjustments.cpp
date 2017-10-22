/*
 * lists.cpp
 *
 * Created: 8/22/2016 2:39:53 AM
 *  Author: Customer
 */ 
 
#include "ListsAndAdjustments.h"

/*Feedback Probes********************************/

const PROGMEM char LST_HLTBP[] = "HLTBP";
__FlashStringHelper *pLST_HLTBP = (__FlashStringHelper*)&LST_HLTBP;
const PROGMEM char LST_HLTOP[] = "HLTOP";
__FlashStringHelper *pLST_HLTOP = (__FlashStringHelper*)&LST_HLTOP;
const PROGMEM char LST_MLTBP[] = "MLTBP";
__FlashStringHelper *pLST_MLTBP = (__FlashStringHelper*)&LST_MLTBP;
const PROGMEM char LST_MLTOP[] = "MLTOP";
__FlashStringHelper *pLST_MLTOP = (__FlashStringHelper*)&LST_MLTOP;
const PROGMEM char LST_BKBP[] = "BKBP";
__FlashStringHelper *pLST_BKBP = (__FlashStringHelper*)&LST_BKBP;
const PROGMEM char LST_BKOP[] = "BKOP";
__FlashStringHelper *pLST_BKOP = (__FlashStringHelper*)&LST_BKOP;


ListOptionItem<EnumFeedbackProbes> FeedbackProbes[6]{
	{EnumFeedbackProbes::HLTBP,pLST_HLTBP},
	{EnumFeedbackProbes::HLTOP,pLST_HLTOP},
	{EnumFeedbackProbes::MLTBP,pLST_MLTBP},
	{EnumFeedbackProbes::MLTOP,pLST_MLTOP},
	{EnumFeedbackProbes::BKBP,pLST_BKBP},
	{EnumFeedbackProbes::BKOP,pLST_BKOP},
};

/*Burner Modes********************************/
const PROGMEM char TXT_Off[] = "Off";
__FlashStringHelper *pTXT_Off = (__FlashStringHelper*)&TXT_Off;
const PROGMEM char TXT_Manual[] = "Manual";
__FlashStringHelper *pTXT_Manual = (__FlashStringHelper*)&TXT_Manual;
const PROGMEM char TXT_Controller[] = "Controller";
__FlashStringHelper *pTXT_Controller = (__FlashStringHelper*)&TXT_Controller;
const PROGMEM char TXT_PWM[] = "PWM";
__FlashStringHelper *pTXT_PWM = (__FlashStringHelper*)&TXT_PWM;

ListOptionItem<EnumBurnerModes> BurnerModes[4]{
	{EnumBurnerModes::Off,pTXT_Off},
	{EnumBurnerModes::Manual,pTXT_Manual},
	{EnumBurnerModes::ClosedLoop,pTXT_Controller},
	{EnumBurnerModes::PWM,pTXT_PWM}
};

/*Burner Status********************************/

const PROGMEM char TXT_PilotOff[] = "Pilot Off";
__FlashStringHelper *pTXT_PilotOff = (__FlashStringHelper*)&TXT_PilotOff;
const PROGMEM char TXT_PilotOffFault[] = "Pilot Off Fault";
__FlashStringHelper *pTXT_PilotOffFault = (__FlashStringHelper*)&TXT_PilotOffFault;
const PROGMEM char TXT_PilotLit[] = "Pilot Lit";
__FlashStringHelper *pTXT_PilotLit = (__FlashStringHelper*)&TXT_PilotLit;
const PROGMEM char TXT_BurnerOnLow[] = "Burner On Low";
__FlashStringHelper *pTXT_BurnerOnLow = (__FlashStringHelper*)&TXT_BurnerOnLow;
const PROGMEM char TXT_BurnerOnHigh[] = "Burner On High";
__FlashStringHelper *pTXT_BurnerOnHigh = (__FlashStringHelper*)&TXT_BurnerOnHigh;
const PROGMEM char TXT_FeedbackFault[] = "Feedback Fault";
__FlashStringHelper *pTXT_FeedbackFault = (__FlashStringHelper*)&TXT_FeedbackFault;
const PROGMEM char TXT_ProfileFault[] = "Profile Fault";
__FlashStringHelper *pTXT_ProfileFault = (__FlashStringHelper*)&TXT_ProfileFault;

ListOptionItem<EnumBurnerStatus> BurnerStatus[7]{
	{EnumBurnerStatus::PilotOff,pTXT_PilotOff},
	{EnumBurnerStatus::PilotFault,pTXT_PilotOffFault},
	{EnumBurnerStatus::PilotLit,pTXT_PilotLit},
	{EnumBurnerStatus::BurnerOnLow,pTXT_BurnerOnLow},
	{EnumBurnerStatus::BurnerOnHigh,pTXT_BurnerOnHigh},
	{EnumBurnerStatus::FeedbackFault,pTXT_FeedbackFault},
	{EnumBurnerStatus::ProfileFault,pTXT_ProfileFault}
};

/*PWMModes********************************/

const PROGMEM char TXT_Low[] = "Low";
__FlashStringHelper *pTXT_Low = (__FlashStringHelper*)&TXT_Low;
const PROGMEM char TXT_Medium[] = "Med";
__FlashStringHelper *pTXT_Medium = (__FlashStringHelper*)&TXT_Medium;
const PROGMEM char TXT_High[] = "High";
__FlashStringHelper *pTXT_High = (__FlashStringHelper*)&TXT_High;

ListOptionItem<EnumPWMLevels> PWMLevels[4]{
	{EnumPWMLevels::PwmOff,pTXT_Off},
	{EnumPWMLevels::Low,pTXT_Low},
	{EnumPWMLevels::Medium,pTXT_Medium},
	{EnumPWMLevels::High,pTXT_High},
};


/*LOG********************************/
AdjustableParam LOG_logRateMs( 1.0, 0.1, 60.0, 0.1);

/*Timer********************************/
AdjustableParam Timer1_Minutes( 10.0, 1.0, 240.0, 1.0);
AdjustableParam Timer2_Minutes( 10.0, 1.0, 240.0, 1.0);

/*RTC********************************/
AdjustableParam RTC_Months( 0.0, 0.0, 12.0, 1.0);
AdjustableParam RTC_Days( 0.0, 0.0, 31.0, 1.0);
AdjustableParam RTC_Years( 0.0, 1990.0, 2999.0, 1.0);
AdjustableParam RTC_Hour( 0.0, 0.0, 24.0, 1.0);
AdjustableParam RTC_Minutes( 0.0, 0.0, 59.0, 1.0);
AdjustableParam RTC_Seconds( 0.0, 0.0, 59.0, 1.0);

/*Burner Set Point Adjustments********************************/

/* HLT */

//Closed Loop Control
AdjustableParam HLT_SetTemp( 60.0, 0.0, 212.0, 1.0);
AdjustableParam HLT_HighOffset( 3, 0, 50, 0.1);
AdjustableParam HLT_MedOffset( 1.5, 0, 25, 0.1);
AdjustableParam HLT_LowOffset(   0, 0, 10, 0.1);
AdjustableParam HLT_Hysteresis(      0.5, 0, 10, 0.1);

//PWM Control
AdjustableParam HLT_PWMPeriod( 10.0, 1.0, 300.0, 1.0);
AdjustableParam HLT_PWMDuty( 50.0, 1, 100.0, 1.0);

/* MLT */

//Closed Loop Control
AdjustableParam MLT_SetTemp( 60.0, 0.0, 212.0, 1.0);
AdjustableParam MLT_HighOffset( 3, 0, 50, 0.1);
AdjustableParam MLT_MedOffset( 1.5, 0, 25, 0.1);
AdjustableParam MLT_LowOffset(   0, 0, 10, 0.1); 
AdjustableParam MLT_Hysteresis(      0.5, 0, 10, 0.1);

//PWM Control
AdjustableParam MLT_PWMPeriod( 10.0, 1.0, 300.0, 1.0);
AdjustableParam MLT_PWMDuty( 50.0, 1, 100.0, 1.0);

/* BK */

AdjustableParam BK_SetTemp( 60.0, 0.0, 212.0, 1.0);
AdjustableParam BK_HighOffset( 3, 0, 50, 0.1);
AdjustableParam BK_MedOffset(  1.5, 0, 25, 0.1);
AdjustableParam BK_LowOffset(   0, 0, 10, 0.1);
AdjustableParam BK_Hysteresis(      0.5, 0, 10, 0.1);

//PWM Control
AdjustableParam BK_PWMPeriod( 10.0, 1.0, 300.0, 1.0);
AdjustableParam BK_PWMDuty( 50.0, 1, 100.0, 1.0);
//AdjustableParam<float> HLT_SetTemp( &HLT_Controller.SetTemp, 0.0, 212.0, 1.0);
