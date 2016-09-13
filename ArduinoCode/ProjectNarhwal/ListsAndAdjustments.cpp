/*
 * lists.cpp
 *
 * Created: 8/22/2016 2:39:53 AM
 *  Author: Customer
 */ 
 
#include "ListsAndAdjustments.h"

/*Feedback Probes********************************/
ListOptionItem<EnumFeedbackProbes> FeedbackProbes[6]{
	{EnumFeedbackProbes::HLTBP,"HLTBP"},
	{EnumFeedbackProbes::HLTOP,"HLTOP"},
	{EnumFeedbackProbes::MLTBP,"MLTBP"},
	{EnumFeedbackProbes::MLTOP,"MLTOP"},
	{EnumFeedbackProbes::BKBP,"BKBP"},
	{EnumFeedbackProbes::BKOP,"BKOP"},
};

/*Burner Modes********************************/
ListOptionItem<EnumBurnerModes> BurnerModes[6]{
	{EnumBurnerModes::Off,"Off"},
	{EnumBurnerModes::Manual,"Manual"},
	{EnumBurnerModes::Auto,"Controller"},
	{EnumBurnerModes::Profile1,"Profile1"},
	{EnumBurnerModes::Profile2,"Profile2"},
	{EnumBurnerModes::Profile3,"Profile3"}
};

/*Burner Status********************************/
ListOptionItem<EnumBurnerStatus> BurnerStatus[7]{
	{EnumBurnerStatus::PilotOff,"Pilot Off"},
	{EnumBurnerStatus::PilotFault,"Pilot Off Fault"},
	{EnumBurnerStatus::PilotLit,"Pilot Lit"},
	{EnumBurnerStatus::BurnerOnLow,"Burner On Low"},
	{EnumBurnerStatus::BurnerOnHigh,"Burner On High"},
	{EnumBurnerStatus::FeedbackFault,"Feedback Fault"},
	{EnumBurnerStatus::ProfileFault,"Profile Fault"}
};
