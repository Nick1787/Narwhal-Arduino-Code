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
#include "../include/AdvancedSerial/AdvancedSerial.h"
#include "../include/MemoryFree/MemoryFree.h"
#include "../iodef.h"
#include "../config.h"

#include "WheatstoneBridge.h"
#include "EnhancedIO/DigitalIO.h"
#include "Executive.h"

#include "EZUI/ClickEncoderWithEvents.h"
#include "EZUI/EZUI.h"
#include "UI/UI_MAIN.h"
#include "UI/UI_HLT.h"
#include "UI/UI_MLT.h"
#include "UI/UI_BK.h"

/**************************
*	Functions
**************************/
extern void serviceEncoders();
extern void hardware_init();
extern long readVcc();
extern float VccMeasured;

/**************************
*	Advanced Serial
**************************/
//extern AdvancedSerial AdvSerial;
extern int freeSramBytes;
extern float freeSramPct;


/**************************
*	ThermoCouples
**************************/
extern float HLT_TC_V;
extern bool HLT_TC_ON;

extern float MLT_TC_V;
extern bool MLT_TC_ON;

extern float BK_TC_V;
extern bool BK_TC_ON;


/**************************
*	Pump Monitor
**************************/
extern float Pump1_V;
extern bool Pump1_On;
extern float Pump2_V;
extern bool Pump2_On;

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
extern ClickEncoderWithEvents MAIN_ENC;

extern EZUI *MAIN_UI;

/**************************
*	Hot Liquor Tank
**************************/
extern LiquidCrystal_I2C HLT_LCD;
extern ClickEncoderWithEvents HLT_ENC;
extern WheatstoneBridge HLT_RTD_BP;
extern WheatstoneBridge HLT_RTD_OP;
extern float HLT_RTD_Vs;
extern float HLT_RTD_BP_V;
extern float HLT_RTD_OP_V;

//User Interface
extern EZUI *HLTUI;

//IO
extern DigitalIO *HLT_SOL1;
extern DigitalIO *HLT_SOL2;

/**************************
*	Mach Liquor Tank
**************************/
extern LiquidCrystal_I2C MLT_LCD;
extern ClickEncoderWithEvents MLT_ENC;
extern WheatstoneBridge MLT_RTD_BP;
extern WheatstoneBridge MLT_RTD_OP;
extern float MLT_RTD_Vs;
extern float MLT_RTD_BP_V;
extern float MLT_RTD_OP_V;

//User Interface
extern EZUI *MLTUI;

//IO
extern DigitalIO *MLT_SOL1;
extern DigitalIO *MLT_SOL2;

/**************************
*	Boil Kettle
**************************/
extern LiquidCrystal_I2C BK_LCD;
extern ClickEncoderWithEvents BK_ENC;
extern WheatstoneBridge BK_RTD_BP;
extern WheatstoneBridge BK_RTD_OP;
extern float BK_RTD_Vs;
extern float BK_RTD_BP_V;
extern float BK_RTD_OP_V;

//User Interface
extern EZUI *BKUI;

//IO
extern DigitalIO *BK_SOL1;
extern DigitalIO *BK_SOL2;

#endif