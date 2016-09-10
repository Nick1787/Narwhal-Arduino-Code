/*
 * lists.h
 *
 * Created: 8/13/2016 9:59:33 AM
 *  Author: Customer
 */ 

#include "classes/EnhancedTypes/ListOption.h"
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

#endif