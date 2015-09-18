/*
 *        File: hardware.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Code for ProjectNarwhal Hardware setup + Initialization
 * ----------------------------------------------------------------
 *    Revision:
 *		09152015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */
 
 
#include "iodef.h"
#include "Hardware.h"

void Hardware::init(){

	/**************************
	*	Hot Liquor Tank
	**************************/
	// LCD
	LiquidCrystal_I2C _HLT_LCD( LCD_1_I2C_ADDR);
	HLT_LCD = &_HLT_LCD;
}

