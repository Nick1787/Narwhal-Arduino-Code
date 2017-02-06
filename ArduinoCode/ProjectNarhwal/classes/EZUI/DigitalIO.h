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
	const char* TrueLabel = "true";
	const char* FalseLabel = "false";
	int value;
	
protected:
	
private:
	const int _Pin = -1;
	PinModes _Mode = IN;
	
//functions
public:
	//Constructors
	DigitalIO(int Pin, PinModes Mode): _Pin(Pin), _Mode(Mode){};
	DigitalIO(int Pin, PinModes Mode, const char* StrTrueLabel, const char* StrFalseLabel): _Pin(Pin), _Mode(Mode), TrueLabel(StrTrueLabel), FalseLabel(StrFalseLabel){};

	//Destructor
	~DigitalIO(){};

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
		
		Serial.println("--DIGIO---");
		Serial.print("CVal:");
		Serial.println(value);
		Serial.print("nVal:");
		Serial.println(newValue);
		Serial.println("----------");
		
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
