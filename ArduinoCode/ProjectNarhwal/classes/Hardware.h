/*
 *        File: hardware.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Code for ProjectNarwhal Hardware setup + Initialization
 * ----------------------------------------------------------------
 *    Revision:
 *		09152015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */
 
#include "../include/LiquidCrystal/LiquidCrystal_I2C.h"
#include "../include/ClickEncoder/ClickEncoder.h"
#include "UI_BurnerController.h"
#include "RTD.h"
#include "../iodef.h"
 
#ifndef _HARDWARE_H
#define _HARDWARE_H

/**************************
*	Hot Liquor Tank
**************************/
extern LiquidCrystal_I2C HLT_LCD;
extern ClickEncoder *HLT_ENC;
//extern RTD_CV_3Wire *HLT_RTD1;
//extern RTD_CV_3Wire *HLT_RTD2;

extern UI_BurnerController *HLT_UI;
	

#endif