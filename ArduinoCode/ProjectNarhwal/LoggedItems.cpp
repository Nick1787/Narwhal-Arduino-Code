/*
 * LoggedItems.cpp
 *
 * Created: 8/19/2017 11:39:35 AM
 *  Author: Nick1
 */ 

#include "LoggedItems.h"

const PROGMEM char TXT_DateTime[] = "DateTime";
const PROGMEM char TXT_freememory[] = "freeMemory (bytes)";
const PROGMEM char TXT_execHz[] = "execHz";

const PROGMEM char TXT_Pump1[] = "Pump1(1=on 0=off)";
const PROGMEM char TXT_Pump2[] = "Pump2(1=on 0=off)";

const PROGMEM char TXT_Timer1[] = "Timer1";
const PROGMEM char TXT_Timer2[] = "Timer2";

const PROGMEM char TXT_HLT_TC_V[] = "HLT TC(volts)";
const PROGMEM char TXT_MLT_TC_V[] = "MLT TC(volts)";
const PROGMEM char TXT_BK_TC_V[] = "BK TC(volts)";

const PROGMEM char TXT_HLT_TC[] = "HLT TC(1=on 0=off)";
const PROGMEM char TXT_MLT_TC[] = "MLT TC(1=on 0=off)";
const PROGMEM char TXT_BK_TC[] = "BK TC(1=on 0=off)";

const PROGMEM char TXT_HLTBP[] = "HLTBP(dF)";
const PROGMEM char TXT_HLTOP[] = "HLTOP(dF)";
const PROGMEM char TXT_MLTBP[] = "MLTBP(dF)";
const PROGMEM char TXT_MLTOP[] = "MLTOP(dF)";
const PROGMEM char TXT_BKBP[] = "BKBP(dF)";
const PROGMEM char TXT_BKOP[] = "BKOP(dF)";

const PROGMEM char TXT_HLTEnable[] = "HLT.ControlMode (0=Off 1=Manual 2=CL 3=PWM)";
const PROGMEM char TXT_HLTSetTemp[] = "HLT.SetTemp(dF)";
const PROGMEM char TXT_HLTFeedbackTemp[] = "HLT.FeedbackTemp(dF)";
const PROGMEM char TXT_HLTGasValveLow[] = "HLT.GasValveLow(1=on 0=off)";
const PROGMEM char TXT_HLTGasValveHigh[] = "HLT.GasValveHigh(1=on 0=off)";

const PROGMEM char TXT_MLTEnable[] = "MLT.ControlMode (0=Off 1=Manual 2=CL 3=PWM)";
const PROGMEM char TXT_MLTSetTemp[] = "MLT.SetTemp(dF)";
const PROGMEM char TXT_MLTFeedbackTemp[] = "MLT.FeedbackTemp(dF)";
const PROGMEM char TXT_MLTGasValveLow[] = "MLT.GasValveLow(1=on 0=off)";
const PROGMEM char TXT_MLTGasValveHigh[] = "MLT.GasValveHigh(1=on 0=off)";

const PROGMEM char TXT_BKEnable[] = "BK.ControlMode (0=Off 1=Manual 2=CL 3=PWM)";
const PROGMEM char TXT_BKSetTemp[] = "BK.SetTemp(dF)";
const PROGMEM char TXT_BKFeedbackTemp[] = "BK.FeedbackTemp(dF)";
const PROGMEM char TXT_BKGasValveLow[] = "BK.GasValveLow(1=on 0=off)";
const PROGMEM char TXT_BKGasValveHigh[] = "BK.GasValveHigh(1=on 0=off)";

LogItem ItemsToLog[]{
	{ LogItemType::string_ptr, TXT_DateTime , &CurrentDateTime },
	{ LogItemType::int_ptr, TXT_freememory , &freeSramBytes },
	{ LogItemType::float_ptr, TXT_execHz , &Exec.execHz },
	
	//Pumps
	{ LogItemType::bool_ptr , TXT_Pump1 , &Pump1_On },
	{ LogItemType::bool_ptr , TXT_Pump2 , &Pump2_On },
		
	//Timers
	{ LogItemType::string_ptr , TXT_Timer1 , &NarwhalTimer1().remainingMMSS },
	{ LogItemType::string_ptr , TXT_Timer2 , &NarwhalTimer2().remainingMMSS },
	
	//Thermocouples
	{ LogItemType::float_ptr , TXT_HLT_TC_V , &HLT_TC_V },
	{ LogItemType::float_ptr , TXT_MLT_TC_V , &MLT_TC_V },
	{ LogItemType::float_ptr , TXT_BK_TC_V , &BK_TC_V},
	{ LogItemType::bool_ptr , TXT_HLT_TC , &HLT_TC_ON },
	{ LogItemType::bool_ptr , TXT_MLT_TC , &MLT_TC_ON },
	{ LogItemType::bool_ptr , TXT_BK_TC , &BK_TC_ON},
	
	// -- All Feedback Probes -- 
	
	{ LogItemType::float_ptr , TXT_HLTBP , &HLT_RTD_BP.degF },
	{ LogItemType::float_ptr , TXT_HLTOP , &HLT_RTD_OP.degF },
	{ LogItemType::float_ptr , TXT_MLTBP , &MLT_RTD_BP.degF },
	{ LogItemType::float_ptr , TXT_MLTOP , &MLT_RTD_OP.degF },
	{ LogItemType::float_ptr , TXT_BKBP , &BK_RTD_BP.degF },
	{ LogItemType::float_ptr , TXT_BKOP , &BK_RTD_OP.degF },

	// --HLT Signals--
	{ LogItemType::int_ptr , TXT_HLTEnable , &(HLT_Controller()).ControlMode },
	{ LogItemType::float_ptr , TXT_HLTSetTemp , &(HLT_Controller()).SetTemp->value },
	{ LogItemType::float_ptr , TXT_HLTFeedbackTemp , &(HLT_Controller()).FeedbackTemp },
	{ LogItemType::bool_ptr , TXT_HLTGasValveLow , &HLT_LowOn },
	{ LogItemType::bool_ptr , TXT_HLTGasValveHigh , &HLT_HighOn},
	
	// --MLT Signals--
	{ LogItemType::int_ptr , TXT_MLTEnable , &MLT_Controller().ControlMode },
	{ LogItemType::float_ptr , TXT_MLTSetTemp , &MLT_Controller().SetTemp->value },
	{ LogItemType::float_ptr , TXT_MLTFeedbackTemp , &MLT_Controller().FeedbackTemp },
	{ LogItemType::bool_ptr , TXT_MLTGasValveLow , &MLT_LowOn },
	{ LogItemType::bool_ptr , TXT_MLTGasValveHigh , &MLT_HighOn },
		
	// --BK Signals--
	{ LogItemType::int_ptr , TXT_BKEnable , &BK_Controller().ControlMode },
	{ LogItemType::float_ptr , TXT_BKSetTemp , &BK_Controller().SetTemp->value },
	{ LogItemType::float_ptr , TXT_BKFeedbackTemp , &BK_Controller().FeedbackTemp },
	{ LogItemType::bool_ptr , TXT_BKGasValveLow , &BK_LowOn },
	{ LogItemType::bool_ptr , TXT_BKGasValveHigh , &BK_HighOn },
};
	