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

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "CEncoder.h"
#include "RTD.h"
#include "iodef.h"

class Hardware {
	
  public:
			
	/**************************
	*	Hot Liquor Tank
	**************************/
	LiquidCrystal_I2C *HLT_LCD;
	CEncoder *HLT_ENC;
	RTD_CV_3Wire *HLT_RTD1;
	RTD_CV_3Wire *HLT_RTD2;

	/**************************
	*	Mash Liquor Tank
	**************************/
	LiquidCrystal_I2C *MLT_LCD;
	CEncoder *MLT_ENC;
	RTD_CV_3Wire *MLT_RTD1;
	RTD_CV_3Wire *MLT_RTD2;

	/**************************
	*	Boil Kettle
	**************************/
	LiquidCrystal_I2C *BK_LCD;
	CEncoder *BK_ENC;
	RTD_CV_3Wire *BK_RTD1;
	RTD_CV_3Wire *BK_RTD2;

	/**************************
	*	Boil Kettle
	**************************/
	LiquidCrystal_I2C *TMR_LCD;
	CEncoder *TMR_ENC;

	void init();
	
  private:
	  
};

#endif