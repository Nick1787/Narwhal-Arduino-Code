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
#include "RTD.h"
#include "DigIO.h"
#include "Executive.h"
#include "../include/TimerOne/TimerOne.h"
#include "../iodef.h"
#include "../config.h"

#include "UserInterface/ClickEncoderWithEvents.h"
#include "UserInterface/UserInterface.h"
#include "MAIN/MAIN_UI.h"

/**************************
*	Functions
**************************/
extern void serviceEncoders();
extern void hardware_init();

/**************************
*	Alarms
**************************/
extern DigIO * TimerAlarmDIO;
extern DigIO * TempAlarmDIO;

/**************************
*	Main Screen
**************************/
extern LiquidCrystal_I2C MAIN_LCD;
extern ClickEncoderWithEvents *MAIN_ENC;
//extern RTD_CV_3Wire *HLT_RTD1;
//extern RTD_CV_3Wire *HLT_RTD2;

/**************************
*	Hot Liquor Tank
**************************/
extern LiquidCrystal_I2C HLT_LCD;
extern ClickEncoderWithEvents *HLT_ENC;
//extern RTD_CV_3Wire *HLT_RTD1;
//extern RTD_CV_3Wire *HLT_RTD2;

extern UserInterface *HLT_UI;

/**************************
*	Mach Liquor Tank
**************************/
extern LiquidCrystal_I2C MLT_LCD;
extern ClickEncoderWithEvents *MLT_ENC;
//extern RTD_CV_3Wire *MLT_RTD1;
//extern RTD_CV_3Wire *MLT_RTD2;

extern UserInterface *MLT_UI;

/**************************
*	Boil Kettle
**************************/
extern LiquidCrystal_I2C BK_LCD;
extern ClickEncoderWithEvents *BK_ENC;
//extern RTD_CV_3Wire *BK_RTD1;
//extern RTD_CV_3Wire *BK_RTD2;

extern UserInterface *BK_UI;

#endif