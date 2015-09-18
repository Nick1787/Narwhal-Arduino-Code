/*
 *        File: RTD.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Class Code for RTD sensing circuit Calculations
 * ----------------------------------------------------------------
 *    Revision:
 *		09082015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */
 
#include "RTD.h"
#include "LUT.h"

//Class Instantiation
RTD_CV_3Wire::RTD_CV_3Wire( int AN_V, int AN_Vref, float R0, float R2, float R3, float R4, float AmpGn){
	AN_V = AN_V;
	AN_Vref = AN_Vref;

	R0 = R0;
	R2 = R2;
	R3 = R3;
	R4 = R4;
		
	float x [36] = {80.31, 84.27, 88.22, 92.16, 96.09, 100, 103.9, 107.79, 111.67, 115.54, 119.4, 123.24, 127.08, 130.9, 134.71, 138.51, 142.29, 146.07, 149.83, 153.58, 157.33, 161.05, 164.77, 168.48, 172.17, 175.86, 179.53, 183.19, 186.84, 190.47, 194.1, 197.71, 201.31, 204.9, 208.48, 212.05};
	float z [36] = {-50, -40, -30, -20, -10, 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300};
	R2Deg = new LUT1D(36,x,z);
}

