/*
 *        File: hardware.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Code for ProjectNarwhal Hardware setup + Initialization
 * ----------------------------------------------------------------
 *    Revision:
 *		09152015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */
 
#ifndef __HARDWARE_H__
#define __HARDWARE_H__


#include "../Main.h"

//Forward Declaration
class BurnerController;
class Executive;
class DS323RealTimeClock;

//Executive
extern Executive Exec;

//Datalogger
#define LoggerSize 50
#define LoggerRateMs 1000
extern DataLogger<LoggerSize>& Logger();

//Real time Clock
DS323RealTimeClock& RTC();

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
extern EZUI_ClickEncoder MAIN_ENC;

/**************************
*	Hot Liquor Tank
**************************/

BurnerController& HLT_Controller();
extern LiquidCrystal_I2C HLT_LCD;
extern EZUI_ClickEncoder HLT_ENC;
extern WheatstoneBridge HLT_RTD_BP;
extern WheatstoneBridge HLT_RTD_OP;

//IO
extern DigitalIO *HLT_SOL1;
extern DigitalIO *HLT_SOL2;

/**************************
*	Mach Liquor Tank
**************************/
BurnerController& MLT_Controller();
extern LiquidCrystal_I2C MLT_LCD;
extern EZUI_ClickEncoder MLT_ENC;
extern WheatstoneBridge MLT_RTD_BP;
extern WheatstoneBridge MLT_RTD_OP;

//IO
extern DigitalIO *MLT_SOL1;
extern DigitalIO *MLT_SOL2;

/**************************
*	Boil Kettle
**************************/
BurnerController& BK_Controller();
extern LiquidCrystal_I2C BK_LCD;
extern EZUI_ClickEncoder BK_ENC;
extern WheatstoneBridge BK_RTD_BP;
extern WheatstoneBridge BK_RTD_OP;

//IO
extern DigitalIO *BK_SOL1;
extern DigitalIO *BK_SOL2;

#endif