/*
 *        File: WheatstoneBridge.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Class Code for the wheatstone Bridge board
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "WheatstoneBridge.h"

//Class Instantiation
WheatstoneBridge::WheatstoneBridge(LUT1D _LUT_R2DEGC, float _R2, float _R3, float _R4){
	LUT_R2DEGC = &_LUT_R2DEGC;
	R2 = _R2;
	R3 = _R3;
	R4 = _R4;
	Rs = 0;			//None Specified;
	AmpGain = 1;	//None Specified
}

//Class Instantiation
WheatstoneBridge::WheatstoneBridge(LUT1D _LUT_R2DEGC, float _R2, float _R3, float _R4, float _AmpGain){
	LUT_R2DEGC = &_LUT_R2DEGC;
	R2 = _R2;
	R3 = _R3;
	R4 = _R4;
	Rs = 0;			//None Specified;
	AmpGain = _AmpGain;
}

//Class Instantiation
WheatstoneBridge::WheatstoneBridge(LUT1D _LUT_R2DEGC, float _R2, float _R3, float _R4, float _AmpGain, float _Rs){
	LUT_R2DEGC = &_LUT_R2DEGC;
	R2 = _R2;
	R3 = _R3;
	R4 = _R4;
	Rs = _Rs;
	AmpGain = _AmpGain;
}

//Read RTD resistance
float WheatstoneBridge::Update(float _Vs, float _Vo){
	float Vbridge = _Vo / AmpGain;
	float Vb_q_Vs = Vbridge / _Vs;

	float Rcalc_num = (R2*R4 + (Vb_q_Vs)*(R2*(R3 + R4)));
	float Rcalc_den = (R3 - (Vb_q_Vs)*(R3+R4));
	Rcalc = Rcalc_num / Rcalc_den - Rs;
	degC = LUT_R2DEGC->lookup(Rcalc);
	degF = degC * 9/5 + 32;
}
