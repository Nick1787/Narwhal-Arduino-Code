/*
 *        File: DigitalIO.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Digital IO - State class for Digital IO interface
 * ----------------------------------------------------------------
 *    Revision:
 *		09152015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "DigitalIO.h"

// default destructor
DigitalIO::~DigitalIO()
{
} //~DIO

int DigitalIO::Value(){
	switch(Mode){
		case(IN):
			_value = digitalRead(Pin);
			break;
		
		case(IN_PULLUP):
			_value = digitalRead(Pin);
			break;
		
		case(OUT):
			break;
	}
	return _value;
}

DigitalIO::PinModes DigitalIO::GetMode(void){
	return Mode;
}

void DigitalIO::Write(int _val){
	if(!(Mode == OUT)){
		pinMode(Pin,OUTPUT);
	}
	_value = _val;
	pinMode(Pin,OUTPUT);
	digitalWrite(Pin,_value);
}

void DigitalIO::SetMode(DigitalIO::PinModes _Mode){
	Mode = _Mode;
}
	
DigitalIO::DigitalIO(int _Pin, DigitalIO::PinModes _Mode){
	Pin = _Pin;
	Mode = _Mode;
}

DigitalIO::DigitalIO(int _Pin, DigitalIO::PinModes _Mode, String _TrueLabel, String _FalseLabel){
	Pin = _Pin;
	Mode = _Mode;
	TrueLabel = _TrueLabel;
	FalseLabel = _FalseLabel;
}
