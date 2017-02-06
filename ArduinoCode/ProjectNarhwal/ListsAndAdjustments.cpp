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
ListOptionItem<EnumBurnerModes> BurnerModes[7]{
	{EnumBurnerModes::Off,"Off"},
	{EnumBurnerModes::Manual,"Manual"},
	{EnumBurnerModes::Auto,"Controller"},
	{EnumBurnerModes::PWM,"PWM"},
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

/*PWMModes********************************/
ListOptionItem<EnumPWMLevels> PWMLevels[3]{
	//{EnumPWMModes::Off,"Off"},
	{EnumPWMLevels::Low,"Low"},
	{EnumPWMLevels::Medium,"Medium"},
	{EnumPWMLevels::High,"High"},
};


/*Burner Set Point Adjustments********************************/

/* HLT */

//Closed Loop Control
AdjustableParam HLT_SetTemp( 200.0, 0.0, 212.0, 1.0);
AdjustableParam HLT_HighOffset( 15, 0, 50, 0.1);
AdjustableParam HLT_MedOffset( 7.5, 0, 25, 0.1);
AdjustableParam HLT_LowOffset(   0, 0, 10, 0.1);
AdjustableParam HLT_Hysteresis(      2, 0, 10, 0.1);

//PWM Control
AdjustableParam HLT_PWMPeriod( 10.0, 1.0, 300.0, 1.0);
AdjustableParam HLT_PWMDuty( 50.0, 1, 100.0, 1.0);

/* MLT */

//Closed Loop Control
AdjustableParam MLT_SetTemp( 200.0, 0.0, 212.0, 1.0);
AdjustableParam MLT_HighOffset( 15, 0, 50, 0.1);
AdjustableParam MLT_MedOffset( 7.5, 0, 25, 0.1);
AdjustableParam MLT_LowOffset(   0, 0, 10, 0.1); 
AdjustableParam MLT_Hysteresis(      2, 0, 10, 0.1);

//PWM Control
AdjustableParam MLT_PWMPeriod( 10.0, 1.0, 300.0, 1.0);
AdjustableParam MLT_PWMDuty( 50.0, 1, 100.0, 1.0);

/* BK */

AdjustableParam BK_SetTemp( 200.0, 0.0, 212.0, 1.0);
AdjustableParam BK_HighOffset( 15, 0, 50, 0.1);
AdjustableParam BK_MedOffset( 7.5, 0, 25, 0.1);
AdjustableParam BK_LowOffset(   0, 0, 10, 0.1);
AdjustableParam BK_Hysteresis(      2, 0, 10, 0.1);

//PWM Control
AdjustableParam BK_PWMPeriod( 10.0, 1.0, 300.0, 1.0);
AdjustableParam BK_PWMDuty( 50.0, 1, 100.0, 1.0);
//AdjustableParam<float> HLT_SetTemp( &HLT_Controller.SetTemp, 0.0, 212.0, 1.0);
