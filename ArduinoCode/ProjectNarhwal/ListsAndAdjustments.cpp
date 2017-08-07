/*
 * lists.cpp
 *
 * Created: 8/22/2016 2:39:53 AM
 *  Author: Customer
 */ 
 
#include "ListsAndAdjustments.h"

/*Feedback Probes********************************/

const PROGMEM char TXT_HLTBP[] = "HLTBP";
__FlashStringHelper *pTXT_HLTBP = (__FlashStringHelper*)&TXT_HLTBP;
const PROGMEM char TXT_HLTOP[] = "HLTOP";
__FlashStringHelper *pTXT_HLTOP = (__FlashStringHelper*)&TXT_HLTOP;
const PROGMEM char TXT_MLTBP[] = "MLTBP";
__FlashStringHelper *pTXT_MLTBP = (__FlashStringHelper*)&TXT_MLTBP;
const PROGMEM char TXT_MLTOP[] = "MLTOP";
__FlashStringHelper *pTXT_MLTOP = (__FlashStringHelper*)&TXT_MLTOP;
const PROGMEM char TXT_BKBP[] = "BKBP";
__FlashStringHelper *pTXT_BKBP = (__FlashStringHelper*)&TXT_BKBP;
const PROGMEM char TXT_BKOP[] = "BKOP";
__FlashStringHelper *pTXT_BKOP = (__FlashStringHelper*)&TXT_BKOP;


ListOptionItem<EnumFeedbackProbes> FeedbackProbes[6]{
	{EnumFeedbackProbes::HLTBP,pTXT_HLTBP},
	{EnumFeedbackProbes::HLTOP,pTXT_HLTOP},
	{EnumFeedbackProbes::MLTBP,pTXT_MLTBP},
	{EnumFeedbackProbes::MLTOP,pTXT_MLTOP},
	{EnumFeedbackProbes::BKBP,pTXT_BKBP},
	{EnumFeedbackProbes::BKOP,pTXT_BKOP},
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
const PROGMEM char TXT_Profile1[] = "Profile1";
__FlashStringHelper *pTXT_Profile1= (__FlashStringHelper*)&TXT_Profile1;
const PROGMEM char TXT_Profile2[] = "Profile2";
__FlashStringHelper *pTXT_Profile2 = (__FlashStringHelper*)&TXT_Profile2;
const PROGMEM char TXT_Profile3[] = "Profile3";
__FlashStringHelper *pTXT_Profile3 = (__FlashStringHelper*)&TXT_Profile3;

ListOptionItem<EnumBurnerModes> BurnerModes[7]{
	{EnumBurnerModes::Off,pTXT_Off},
	{EnumBurnerModes::Manual,pTXT_Manual},
	{EnumBurnerModes::Auto,pTXT_Controller},
	{EnumBurnerModes::PWM,pTXT_PWM},
	{EnumBurnerModes::Profile1,pTXT_Profile1},
	{EnumBurnerModes::Profile2,pTXT_Profile2},
	{EnumBurnerModes::Profile3,pTXT_Profile3}
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
const PROGMEM char TXT_Medium[] = "Medium";
__FlashStringHelper *pTXT_Medium = (__FlashStringHelper*)&TXT_Medium;
const PROGMEM char TXT_High[] = "High";
__FlashStringHelper *pTXT_High = (__FlashStringHelper*)&TXT_High;

ListOptionItem<EnumPWMLevels> PWMLevels[3]{
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
AdjustableParam HLT_HighOffset( 4, 0, 50, 0.1);
AdjustableParam HLT_MedOffset( 2, 0, 25, 0.1);
AdjustableParam HLT_LowOffset(   0, 0, 10, 0.1);
AdjustableParam HLT_Hysteresis(      0.5, 0, 10, 0.1);

//PWM Control
AdjustableParam HLT_PWMPeriod( 10.0, 1.0, 300.0, 1.0);
AdjustableParam HLT_PWMDuty( 50.0, 1, 100.0, 1.0);

/* MLT */

//Closed Loop Control
AdjustableParam MLT_SetTemp( 60.0, 0.0, 212.0, 1.0);
AdjustableParam MLT_HighOffset( 4, 0, 50, 0.1);
AdjustableParam MLT_MedOffset( 2, 0, 25, 0.1);
AdjustableParam MLT_LowOffset(   0, 0, 10, 0.1); 
AdjustableParam MLT_Hysteresis(      0.5, 0, 10, 0.1);

//PWM Control
AdjustableParam MLT_PWMPeriod( 10.0, 1.0, 300.0, 1.0);
AdjustableParam MLT_PWMDuty( 50.0, 1, 100.0, 1.0);

/* BK */

AdjustableParam BK_SetTemp( 60.0, 0.0, 212.0, 1.0);
AdjustableParam BK_HighOffset( 4, 0, 50, 0.1);
AdjustableParam BK_MedOffset(  2, 0, 25, 0.1);
AdjustableParam BK_LowOffset(   0, 0, 10, 0.1);
AdjustableParam BK_Hysteresis(      0.5, 0, 10, 0.1);

//PWM Control
AdjustableParam BK_PWMPeriod( 10.0, 1.0, 300.0, 1.0);
AdjustableParam BK_PWMDuty( 50.0, 1, 100.0, 1.0);
//AdjustableParam<float> HLT_SetTemp( &HLT_Controller.SetTemp, 0.0, 212.0, 1.0);
