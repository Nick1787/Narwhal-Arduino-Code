/* 
* LCDToggleOption.cpp
*
* Created: 1/4/2016 9:06:37 PM
* Author: Customer
*/


#include "LCDToggleOption.h"

// default destructor
LCDToggleOption::~LCDToggleOption()
{
} //~LCDToggleOption

String LCDToggleOption::TrueLabel(void){
	switch(Type){
		case(VarDigIO):
			DigIO *DIO;
			DIO = DIORef;
			return (*DIO).TrueLabel;
		case(StaticBool):
			return BoolTrueText;
		case(VarBool):
			return BoolTrueText;
	}
}

String LCDToggleOption::FalseLabel(void){
	switch(Type){
		case(VarDigIO):
			DigIO *DIO;
			DIO = DIORef;
			return (*DIO).FalseLabel;
		case(StaticBool):
			return BoolFalseText;
		case(VarBool):
			return BoolFalseText;
	}	
}

int LCDToggleOption::Value(){
	switch(Type){
		case(VarDigIO):
			DigIO *DIO;
			DIO = DIORef;
			return (*DIO).Value();
		case(StaticBool):
			return BlnVal;
		case(VarBool):
			BlnVal = *BlnRef;
			return BlnVal;
	}
}

void LCDToggleOption::Write(int _value){
	switch(Type){
		case(VarDigIO):
			DigIO *DIO;
			DIO = DIORef;
			(*DIO).Write(_value);
			break;
		case(StaticBool):
			BlnVal=_value;
			break;
		case(VarBool):
			*BlnRef = _value;
			BlnVal = *BlnRef;
			break;
	}
}

void LCDToggleOption::Toggle(void){
	switch(Type){
		case(VarDigIO):
			DigIO *DIO;
			DIO = DIORef;
			if ((*DIO).Value()){
				(*DIO).Write(0);
			}else{
				(*DIO).Write(1);
			}
			break;
		case(StaticBool):
			BlnVal=!BlnVal;
			break;
		case(VarBool):
			*BlnRef = !BlnVal;
			BlnVal = *BlnRef;
			break;
	}
}

LCDToggleOption::LCDToggleOption(String _Label, DigIO * DigitalIOObject)
{
	Label = _Label;
	Type = VarDigIO;
	DIORef = DigitalIOObject;	
}

LCDToggleOption::LCDToggleOption(String _Label, bool _val)
{
	Type = StaticBool;
	Label = _Label;
	BlnVal = _val;
}

LCDToggleOption::LCDToggleOption(String _Label, bool _val, String _TrueLabel, String _FalseLabel)
{
	Type = StaticBool;
	Label = _Label;
	BlnVal = _val;
	BoolTrueText = _TrueLabel;
	BoolFalseText = _FalseLabel;
}

LCDToggleOption::LCDToggleOption(String _Label, bool * _val)
{
	Type = VarBool;
	Label = _Label;
	BlnRef = _val;
	BlnVal = *BlnRef;
}

LCDToggleOption::LCDToggleOption(String _Label, bool * _val, String _TrueLabel, String _FalseLabel)
{
	Type = VarBool;
	Label = _Label;
	BlnRef = _val;
	BlnVal = *BlnRef;
	BoolTrueText = _TrueLabel;
	BoolFalseText = _FalseLabel;
}
