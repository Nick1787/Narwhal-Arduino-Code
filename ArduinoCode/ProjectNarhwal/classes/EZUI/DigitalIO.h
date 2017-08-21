/*
 *        File: DigitalIO.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Digital IO - State class for Digital IO interface
 * ----------------------------------------------------------------
 *    Revision:
 *		09152015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#ifndef __DigitalIO_H__
#define __DigitalIO_H__

#include<Arduino.h>

class DigitalIO
{
//variables
public:
	enum PinModes {IN, OUT, IN_PULLUP};
	const void* _TrueLabel;
	const void* _FalseLabel;
	bool value;
	
protected:
	
private:
	boolean _isFlash = false;
	const int8_t _Pin = -1;
	PinModes _Mode = IN;
	
//functions
public:
	//Constructors
	DigitalIO(int Pin, PinModes Mode):  _isFlash(true), _TrueLabel(F("True")), _FalseLabel(F("False")), _Pin(Pin), _Mode(Mode){};
	DigitalIO(int Pin, PinModes Mode, const char* StrTrueLabel, const char* StrFalseLabel): _Pin(Pin), _Mode(Mode), _isFlash(false), _TrueLabel(StrTrueLabel), _FalseLabel(StrFalseLabel){};
	DigitalIO(int Pin, PinModes Mode, const  __FlashStringHelper* StrTrueLabel, const __FlashStringHelper* StrFalseLabel): _isFlash(true), _Pin(Pin), _Mode(Mode), _TrueLabel(StrTrueLabel), _FalseLabel(StrFalseLabel){};

	//Destructor
	~DigitalIO(){};

	//Text Functions
	const char* TrueLabel(){
		if(_isFlash){
			String ret = (__FlashStringHelper*)_TrueLabel;
			char copy[64];
			ret.toCharArray(copy, 64);
			return (copy);
		}else{
			return ((const char*)_TrueLabel);
		}
	}
	//Text Functions
	const char* FalseLabel(){
		if(_isFlash){
			String ret = (__FlashStringHelper*)_FalseLabel;
			char copy[64];
			ret.toCharArray(copy, 64);
			return (copy);
		}else{
			return ((const char*)_FalseLabel);
		}
	}
	//Custom Functions
	void SetMode(PinModes Mode){_Mode = Mode;};
	PinModes GetMode(void){ return _Mode;};
	int Value(void){
		switch(_Mode){
			case(IN):
				value = digitalRead(_Pin);
				break;
			case(IN_PULLUP):
				value = digitalRead(_Pin);
				break;
			case(OUT):
				break;
		}
		return value;
	};
	void Write(int newValue){
		
		if(!(_Mode == OUT)){
			pinMode(_Pin,OUTPUT);
		}
		value = newValue;
		pinMode(_Pin,OUTPUT);
		digitalWrite(_Pin,value);
	};
	
protected:
private:

}; //DIO

#endif //__DIO_H__
