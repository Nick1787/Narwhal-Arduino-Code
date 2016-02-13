/*
 *        File: hardware.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Code for ProjectNarwhal Hardware setup + Initialization
 * ----------------------------------------------------------------
 *    Revision:
 *		09152015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */
 
#ifndef _HARDWARE_H
#define _HARDWARE_H

#include "../include/LiquidCrystal/LiquidCrystal_I2C.h"
#include "../include/TimerOne/TimerOne.h"
#include "../iodef.h"
#include "../config.h"

#include "RTD.h"
#include "DigitalIO.h"
#include "Executive.h"

#include "EZUI/ClickEncoderWithEvents.h"
#include "EZUI/EZUI.h"
#include "MAIN/MAIN_UI.h"

/**************************
*	Functions
**************************/
extern void serviceEncoders();
extern void hardware_init();

/**************************
*	analogs
**************************/
extern float analog0;
extern float analog1;
extern float analog2;
extern float analog3;
extern float analog4;
extern float analog5;
extern float analog6;
extern float analog7;
extern float analog8;
extern float analog9;
extern float analog10;
extern float analog11;
extern float analog12;
extern float analog13;
extern float analog14;
extern float analog15;

/**************************
*	Solenoids
**************************/
extern DigitalIO RC1_OUT1;
extern DigitalIO RC1_OUT2;
extern DigitalIO RC1_OUT3;
extern DigitalIO RC1_OUT4;
extern DigitalIO RC1_OUT5;
extern DigitalIO RC1_OUT6;
extern DigitalIO RC1_OUT7;
extern DigitalIO RC1_OUT8;

extern DigitalIO RC2_OUT1;
extern DigitalIO RC2_OUT2;
extern DigitalIO RC2_OUT3;
extern DigitalIO RC2_OUT4;
extern DigitalIO RC2_OUT5;
extern DigitalIO RC2_OUT6;
extern DigitalIO RC2_OUT7;
extern DigitalIO RC2_OUT8;

/**************************
*	Main Screen
**************************/
extern LiquidCrystal_I2C MAIN_LCD;
extern ClickEncoderWithEvents *MAIN_ENC;

extern EZUI *MAIN_UI;

/**************************
*	Hot Liquor Tank
**************************/
extern LiquidCrystal_I2C HLT_LCD;
extern ClickEncoderWithEvents *HLT_ENC;
extern WheatstoneBridge *HLT_RTD_BP;
//extern WheatstoneBridge *HLT_RTD_OP;

extern EZUI *HLT_UI;

/**************************
*	Mach Liquor Tank
**************************/
extern LiquidCrystal_I2C MLT_LCD;
extern ClickEncoderWithEvents *MLT_ENC;
//extern WheatstoneBridge *MLT_RTD_BP;
//extern WheatstoneBridge *MLT_RTD_OP;

extern EZUI *MLT_UI;

/**************************
*	Boil Kettle
**************************/
extern LiquidCrystal_I2C BK_LCD;
extern ClickEncoderWithEvents *BK_ENC;
//extern WheatstoneBridge *BK_RTD_BP;
//extern WheatstoneBridge *BK_RTD_OP;

extern EZUI *BK_UI;

#endif