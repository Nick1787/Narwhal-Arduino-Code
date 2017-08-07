/*
 * lists.h
 *
 * Created: 8/13/2016 9:59:33 AM
 *  Author: Customer
 */ 

#include "classes/EZUI/ListOption.h"
#include "classes/EZUI/AdjustableParam.h"

#ifndef _LISTS_H
#define _LISTS_H

/*Feedback Probes********************************/
enum EnumFeedbackProbes{
	HLTBP,
	HLTOP,
	MLTBP,
	MLTOP,
	BKBP,
	BKOP
};
extern ListOptionItem<EnumFeedbackProbes> FeedbackProbes[6];

/*Burner Modes********************************/
enum EnumBurnerModes{
	Off,
	Manual,
	Auto,
	PWM,
	Profile1,
	Profile2,
	Profile3
};
extern ListOptionItem<EnumBurnerModes> BurnerModes[7];

/*Burner Status********************************/
enum EnumBurnerStatus{
	PilotOff,
	PilotFault,
	PilotLit,
	BurnerOnLow,
	BurnerOnHigh,
	FeedbackFault,
	ProfileFault
};
extern ListOptionItem<EnumBurnerStatus> BurnerStatus[7];

/*PWMModes********************************/
enum EnumPWMLevels{
	Low,
	Medium,
	High
};
extern ListOptionItem<EnumPWMLevels> PWMLevels[3];


/*Logger********************************/
extern AdjustableParam LOG_logRateMs;

/*Timer stuff********************************/
extern AdjustableParam Timer1_Minutes;
extern AdjustableParam Timer2_Minutes;

/*RTC********************************/
extern AdjustableParam RTC_Months;
extern AdjustableParam RTC_Days;
extern AdjustableParam RTC_Years;
extern AdjustableParam RTC_Hour;
extern AdjustableParam RTC_Minutes;
extern AdjustableParam RTC_Seconds;

/*Adjustment Values********************************/

extern AdjustableParam HLT_SetTemp;
extern AdjustableParam HLT_HighOffset;
extern AdjustableParam HLT_MedOffset;
extern AdjustableParam HLT_LowOffset;
extern AdjustableParam HLT_Hysteresis;

//PWM Control
extern AdjustableParam HLT_PWMPeriod;
extern AdjustableParam HLT_PWMDuty;

extern AdjustableParam MLT_SetTemp;
extern AdjustableParam MLT_HighOffset;
extern AdjustableParam MLT_MedOffset;
extern AdjustableParam MLT_LowOffset;
extern AdjustableParam MLT_Hysteresis;	

//PWM Control
extern AdjustableParam MLT_PWMPeriod;
extern AdjustableParam MLT_PWMDuty;

extern AdjustableParam BK_SetTemp;
extern AdjustableParam BK_HighOffset;
extern AdjustableParam BK_MedOffset;
extern AdjustableParam BK_LowOffset;
extern AdjustableParam BK_Hysteresis;

//PWM Control
extern AdjustableParam BK_PWMPeriod;
extern AdjustableParam BK_PWMDuty;

#endif