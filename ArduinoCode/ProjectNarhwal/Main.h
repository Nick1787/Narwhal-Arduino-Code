/*
 * Main.h
 *
 * Created: 11/24/2016 7:15:47 PM
 *  Author: Nick1
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#include <Arduino.h>
#include "iodef.h"
#include "config.h"
#include "ListsAndAdjustments.h"
#include "LoggedItems.h"

//Executive
#include "./classes/Executive.h"

//Hardware Includes
//#include "./include/SdFat/SdFat.h"
#include "./include/SD/SD.h"
#include "./include/LiquidCrystal/LiquidCrystal_I2C.h"
#include "./include/TimerOne/TimerOne.h"
#include "./include/AdvancedSerial/AdvancedSerial.h"
#include "./include/MemoryFree/MemoryFree.h"
#include "./classes/EZUI/EZUI_Hardware_ClickEncoder.h"

//Enhanced Types
#include "./classes/EZUI/DigitalIO.h"
#include "./classes/EZUI/AdjustableParam.h"
#include "./classes/EZUI/ListOption.h"

//Custom Class Code
#include "./classes/WheatstoneBridge.h"
#include "./classes/BurnerController.h"
#include "./classes/DataLogger.h"
#include "./classes/Hardware.h"
#include "./classes/DS323RealTimeClock.h"
#include "./classes/NarwhalTimer.h"

//UIs
#include "./classes/EZUI/EZUI.h"
#include "./classes/UI/UI_Shared.h"
#include "./classes/UI/UI_MAIN.h"
#include "./classes/UI/UI_MLT.h"
#include "./classes/UI/UI_HLT.h"
#include "./classes/UI/UI_BK.h"



#endif /* MAIN_H_ */