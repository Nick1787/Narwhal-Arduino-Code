/*
 * LoggedItems.cpp
 *
 * Created: 8/19/2017 11:39:35 AM
 *  Author: Nick1
 */ 

#include "LoggedItems.h"

const PROGMEM char TXT_DateTime[] = "DateTime";
const PROGMEM char TXT_freememory[] = "freeMemory";
const PROGMEM char TXT_execHz[] = "execHz";

const PROGMEM char TXT_HLTEnable[] = "HLT.Enabled";
const PROGMEM char TXT_HLTSetTemp[] = "HLT.SetTemp";
const PROGMEM char TXT_HLTFeedbackTemp[] = "HLT.FeedbackTemp";
const PROGMEM char TXT_HLTGasValveLow[] = "HLT.GasValveLow";
const PROGMEM char TXT_HLTGasValveHigh[] = "HLT.GasValveHigh";

const PROGMEM char TXT_MLTEnable[] = "MLT.Enabled";
const PROGMEM char TXT_MLTSetTemp[] = "MLT.SetTemp";
const PROGMEM char TXT_MLTFeedbackTemp[] = "MLT.FeedbackTemp";
const PROGMEM char TXT_MLTGasValveLow[] = "MLT.GasValveLow";
const PROGMEM char TXT_MLTGasValveHigh[] = "MLT.GasValveHigh";

const PROGMEM char TXT_BKEnable[] = "BK.Enabled";
const PROGMEM char TXT_BKSetTemp[] = "BK.SetTemp";
const PROGMEM char TXT_BKFeedbackTemp[] = "BK.FeedbackTemp";
const PROGMEM char TXT_BKGasValveLow[] = "BK.GasValveLow";
const PROGMEM char TXT_BKGasValveHigh[] = "BK.GasValveHigh";

const PROGMEM LogItem ItemsToLog[]{
	{ LogItemType::string_ptr, TXT_DateTime , &CurrentDateTime },
	{ LogItemType::int_ptr, TXT_freememory , &freeSramBytes },
	{ LogItemType::int_ptr, TXT_execHz , &Exec.execHz },
	
	// --HLT Signals--
	{ LogItemType::int_ptr , TXT_HLTEnable , &HLT_Controller().ControlEnabled },
	{ LogItemType::float_ptr , TXT_HLTSetTemp , &HLT_Controller().SetTemp->value },
	{ LogItemType::float_ptr , TXT_HLTFeedbackTemp , &HLT_Controller().FeedbackTemp },
	{ LogItemType::bool_ptr , TXT_HLTGasValveLow , &HLT_Controller().GasValve_Low->value },
	{ LogItemType::bool_ptr , TXT_HLTGasValveHigh , &HLT_Controller().GasValve_High->value },
	
	// --MLT Signals--
	{ LogItemType::int_ptr , TXT_MLTEnable , &MLT_Controller().ControlEnabled },
	{ LogItemType::float_ptr , TXT_MLTSetTemp , &MLT_Controller().SetTemp->value },
	{ LogItemType::float_ptr , TXT_MLTFeedbackTemp , &MLT_Controller().FeedbackTemp },
	{ LogItemType::bool_ptr , TXT_MLTGasValveLow , &MLT_Controller().GasValve_Low->value },
	{ LogItemType::bool_ptr , TXT_MLTGasValveHigh , &MLT_Controller().GasValve_High->value },
		
	// --BK Signals--
	{ LogItemType::int_ptr , TXT_BKEnable , &BK_Controller().ControlEnabled },
	{ LogItemType::float_ptr , TXT_BKSetTemp , &BK_Controller().SetTemp->value },
	{ LogItemType::float_ptr , TXT_BKFeedbackTemp , &BK_Controller().FeedbackTemp },
	{ LogItemType::bool_ptr , TXT_BKGasValveLow , &BK_Controller().GasValve_Low->value },
	{ LogItemType::bool_ptr , TXT_BKGasValveHigh , &BK_Controller().GasValve_High->value },
};
	