/*
 *        File: RTD.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Class Code for RTD sensing circuit Calculations
 * ----------------------------------------------------------------
 *    Revision:
 *		09082015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */
 
#ifndef _RTD_H
#define _RTD_H

#include "LUT.h"

class RTD_CV_3Wire {

private:
	//Analog In Pins
	int AN_V;
	int AN_Vref;

public:
	//Calculated Resistance
	float degC;
	float degF;
	float R;
	
	//Convert Resistance to Temperature
	LUT1D *R2Deg;
	
	//Voltages
    float Vcc;		//Supply voltage to bridge
	float V;		//Sensed output voltage of Bridge
	
	//Bridge Resistors
	float R0;
	float R2;
	float R3;
	float R4;

	//Class Instantiation
	RTD_CV_3Wire( int AN_V, int AN_Vref, float R0, float R2, float R3, float R4, float AmpGn);
	float Read();		//Read in degC
	float ReadF();		//Read in degF
};

#endif
