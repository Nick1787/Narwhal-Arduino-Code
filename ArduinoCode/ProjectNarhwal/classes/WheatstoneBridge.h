/*
 *        File: WheatstoneBridge.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Class Code for the wheatstone Bridge board
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */


#ifndef WHEATSTONEBRIDGE_H_
#define WHEATSTONEBRIDGE_H_

#include "LUT.h"
#include <Arduino.h>

class WheatstoneBridge{
	
	private:
		
	public:		
		//Voltages
		float Vo;	//Output Voltage	
		float Vs;	//Source Voltage
		boolean isFaulted = false;
		
		//Bridge Properties
		float AmpGain;
		float Rs;
		float R2;
		float R3;
		float R4;
		
		//Calculated Resistance
		LUT *LUT_R2DEGC;
		
		//Outputs
		float Rcalc;
		float degC;
		float degF;
		
		//Analog in for both Source Voltage and Vout voltage
		WheatstoneBridge(LUT *_LUT_R2DEGC, float _R2, float _R3, float _R4){
			LUT_R2DEGC = _LUT_R2DEGC;
			R2 = _R2;
			R3 = _R3;
			R4 = _R4;
			Rs = 0;			//None Specified;
			AmpGain = 1;	//None Specified
		};	
	
		//Analog in for both Source Voltage and Vout voltage - With Amplifier 
		WheatstoneBridge(LUT *_LUT_R2DEGC, float _R2, float _R3, float _R4, float _AmpGain){
			LUT_R2DEGC = _LUT_R2DEGC;
			R2 = _R2;
			R3 = _R3;
			R4 = _R4;
			Rs = 0;			//None Specified;
			AmpGain = _AmpGain;
		};	
		
		//Analog in for both Source Voltage and Vout voltage - With Amplifier - With Rs shift resistor in series with Rrtd;	
		WheatstoneBridge(LUT *_LUT_R2DEGC, float _R2, float _R3, float _R4, float _AmpGain, float _Rs){
			LUT_R2DEGC = _LUT_R2DEGC;
			R2 = _R2;
			R3 = _R3;
			R4 = _R4;
			Rs = _Rs;
			AmpGain = _AmpGain;
		};		

		//Reading Bridge
		float Calculate(float _Vs, float _Vo){
			Vo = _Vo;
			Vs = _Vs;
			float div0_protection = 0.001;
			float Vbridge = Vo / max(AmpGain,div0_protection);
			float Vb_q_Vs = Vbridge / Vs;

			float Rcalc_num = (R2*R4 + (Vb_q_Vs)*(R2*(R3 + R4)));
			float Rcalc_den = (R3 - (Vb_q_Vs)*(R3+R4));
			Rcalc = Rcalc_num / max(Rcalc_den,div0_protection) - Rs;
			degC = LUT_R2DEGC->lookup(Rcalc);
			degF = degC * 9/5 + 32;
			
			
			if((Vs < 4) ||( Vo < 0.1 ) || ( Vo>Vs )){
				isFaulted = true;
			}else{
				isFaulted = false;
			}
			return degC;
		};
};




#endif /* WHEATSTONEBRIDGE_H_ */