/* 
* DIO.cpp
*
* Created: 1/4/2016 9:23:18 PM
* Author: Customer
*/


#include "DigIO.h"

// default destructor
DigIO::~DigIO()
{
} //~DIO

int DigIO::Value(){
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

DigIO::PinModes DigIO::GetMode(void){
	return Mode;
}

void DigIO::Write(int _val){
	if(!(Mode == OUT)){
		pinMode(Pin,OUTPUT);
	}
	_value = _val;
	digitalWrite(Pin,_value);
}

void DigIO::SetMode(DigIO::PinModes _Mode){
	Mode = _Mode;
}
	
DigIO::DigIO(int _Pin, DigIO::PinModes _Mode){
	Pin = _Pin;
	Mode = _Mode;
}

DigIO::DigIO(int _Pin, DigIO::PinModes _Mode, String _TrueLabel, String _FalseLabel){
	Pin = _Pin;
	Mode = _Mode;
	TrueLabel = _TrueLabel;
	FalseLabel = _FalseLabel;
}
