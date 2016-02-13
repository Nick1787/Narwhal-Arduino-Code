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
WheatstoneBridge::WheatstoneBridge(String _Name, int _AnalogIn_Vs, int _AnalogIn_V, LUT1D _LUT_R2DEGC, float _R2, float _R3, float _R4){
	Name = _Name;
	LUT_R2DEGC = &_LUT_R2DEGC;
	R2 = _R2;
	R3 = _R3;
	R4 = _R4;
	Rs = 0;			//None Specified;
	AmpGain = 1;	//None Specified
	AN_Vs = _AnalogIn_Vs;
	AN_Vo = _AnalogIn_V;
}

//Class Instantiation
WheatstoneBridge::WheatstoneBridge(String _Name, int _AnalogIn_Vs, int _AnalogIn_V, LUT1D _LUT_R2DEGC, float _R2, float _R3, float _R4, float _AmpGain){
	Name = _Name;
	LUT_R2DEGC = &_LUT_R2DEGC;
	R2 = _R2;
	R3 = _R3;
	R4 = _R4;
	Rs = 0;			//None Specified;
	AmpGain = _AmpGain;
	AN_Vs = _AnalogIn_Vs;
	AN_Vo = _AnalogIn_V;
}

//Class Instantiation
WheatstoneBridge::WheatstoneBridge(String _Name, int _AnalogIn_Vs, int _AnalogIn_V, LUT1D _LUT_R2DEGC, float _R2, float _R3, float _R4, float _AmpGain, float _Rs){
	Name = _Name;
	LUT_R2DEGC = &_LUT_R2DEGC;
	R2 = _R2;
	R3 = _R3;
	R4 = _R4;
	Rs = _Rs;
	AmpGain = _AmpGain;
	AN_Vs = _AnalogIn_Vs;
	AN_Vo = _AnalogIn_V;
}

//Read RTD resistance
float WheatstoneBridge::Update(){
	
	Vs = (5.0*(float)analogRead(AN_Vs))/1023.0;
	Vo = (5.0*(float)analogRead(AN_Vo))/1023.0;
	float Vbridge = Vo / max(AmpGain,0.001);
	float Vb_q_Vs = Vbridge / Vs;

	float Rcalc_num = (R2*R4 + (Vb_q_Vs)*(R2*(R3 + R4)));
	float Rcalc_den = (R3 - (Vb_q_Vs)*(R3+R4));
	Rcalc = Rcalc_num / max(Rcalc_den - Rs,0.01);
	degC = LUT_R2DEGC->lookup(Rcalc);
	degF = degC * 9/5 + 32;
	
	//If in verbose mode 2 or above print out the RTD updated values
	//#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
	//	if((millis() - lastSerialPrint)>2000){
	//		lastSerialPrint = millis();
	//		Serial.println("  RTD:" + Name + " Vo:" + Vo + " Vs:" + Vs + " Rc:" + Rcalc + " Tc:" + degC + " Tf:" + degF);
	//	}
	//#endif
}
