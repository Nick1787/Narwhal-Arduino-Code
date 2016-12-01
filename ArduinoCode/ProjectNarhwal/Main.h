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

//Hardware Includes
#include "./include/LiquidCrystal/LiquidCrystal_I2C.h"
#include "./include/TimerOne/TimerOne.h"
#include "./include/AdvancedSerial/AdvancedSerial.h"
#include "./include/MemoryFree/MemoryFree.h"
#include "./classes/EZUI/ClickEncoderWithEvents.h"

//Enhanced Types
#include "./classes/EnhancedTypes/DigitalIO.h"
#include "./classes/EnhancedTypes/AdjustableParam.h"
#include "./classes/EnhancedTypes/ListOption.h"

//Custom Class Code
#include "./classes/WheatstoneBridge.h"
#include "./classes/BurnerController.h"
#include "./classes/Hardware.h"
#include "./classes/Executive.h"

//UIs
#include "./classes/EZUI/EZUI.h"
#include "./classes/UI/UI_Shared.h"
#include "./classes/UI/UI_MAIN.h"
#include "./classes/UI/UI_MLT.h"
#include "./classes/UI/UI_HLT.h"
#include "./classes/UI/UI_BK.h"



#endif /* MAIN_H_ */