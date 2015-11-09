/*
 * Hardware.cpp
 *
 * Created: 11/8/2015 5:18:14 PM
 *  Author: Customer
 */ 

#include "Hardware.h"
#include "../iodef.h"
#include "../include/LiquidCrystal/LiquidCrystal_I2C.h"
#include "../include/ClickEncoder/ClickEncoder.h"

/**************************
*	Hot Liquor Tank
**************************/
LiquidCrystal_I2C HLT_LCD(HLT_LCD_I2C_ADDR);
ClickEncoder *HLT_ENC = new ClickEncoder( HLT_ENC_A, HLT_ENC_B, HLT_ENC_SW );
UI_BurnerController *HLT_UI = new UI_BurnerController("HLT",&HLT_LCD,HLT_ENC);