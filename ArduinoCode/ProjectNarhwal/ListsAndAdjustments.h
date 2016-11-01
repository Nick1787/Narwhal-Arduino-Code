/*
 * lists.h
 *
 * Created: 8/13/2016 9:59:33 AM
 *  Author: Customer
 */ 

#include "classes/EnhancedTypes/ListOption.h"
#include "classes/EnhancedTypes/AdjustableParam.h"
#include "classes/Hardware.h"

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
	Profile1,
	Profile2,
	Profile3
};
extern ListOptionItem<EnumBurnerModes> BurnerModes[6];

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


/*Adjustment Values********************************/

extern AdjustableParam HLT_SetTemp;
extern AdjustableParam HLT_HighErrLim;
extern AdjustableParam HLT_OffErrLim;
extern AdjustableParam HLT_HighErrHys;
extern AdjustableParam HLT_OffErrHys;

extern AdjustableParam MLT_SetTemp;
extern AdjustableParam MLT_HighErrLim;
extern AdjustableParam MLT_OffErrLim;
extern AdjustableParam MLT_HighErrHys;
extern AdjustableParam MLT_OffErrHys;	

extern AdjustableParam BK_SetTemp;
extern AdjustableParam BK_HighErrLim;
extern AdjustableParam BK_OffErrLim;
extern AdjustableParam BK_HighErrHys;
extern AdjustableParam BK_OffErrHys;

#endif