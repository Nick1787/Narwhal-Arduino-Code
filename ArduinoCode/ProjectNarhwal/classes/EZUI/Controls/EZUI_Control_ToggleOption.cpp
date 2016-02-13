/* 
* LCDToggleOption.cpp
*
* Created: 1/4/2016 9:06:37 PM
* Author: Customer
*/


#include "EZUI_Control_ToggleOption.h"

// default destructor
EZUI_Control_ToggleOption::~EZUI_Control_ToggleOption()
{
} //~LCDToggleOption

String EZUI_Control_ToggleOption::TrueLabel(void){
	switch(Type){
		case(VarDigIO):
			DigitalIO *DIO;
			DIO = DIORef;
			return (*DIO).TrueLabel;
		case(StaticBool):
			return BoolTrueText;
		case(VarBool):
			return BoolTrueText;
	}
}

String EZUI_Control_ToggleOption::FalseLabel(void){
	switch(Type){
		case(VarDigIO):
			DigitalIO *DIO;
			DIO = DIORef;
			return (*DIO).FalseLabel;
		case(StaticBool):
			return BoolFalseText;
		case(VarBool):
			return BoolFalseText;
	}	
}

int EZUI_Control_ToggleOption::Value(){
	switch(Type){
		case(VarDigIO):
			DigitalIO *DIO;
			DIO = DIORef;
			return (*DIO).Value();
		case(StaticBool):
			return BlnVal;
		case(VarBool):
			BlnVal = *BlnRef;
			return BlnVal;
	}
}

void EZUI_Control_ToggleOption::Write(int _value){
	switch(Type){
		case(VarDigIO):
			DigitalIO *DIO;
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

void EZUI_Control_ToggleOption::Toggle(void){
	switch(Type){
		case(VarDigIO):
			DigitalIO *DIO;
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

EZUI_Control_ToggleOption::EZUI_Control_ToggleOption(String _Label, DigitalIO * DigitalIOObject)
{
	Label = _Label;
	Type = VarDigIO;
	DIORef = DigitalIOObject;	
}

EZUI_Control_ToggleOption::EZUI_Control_ToggleOption(String _Label, bool _val)
{
	Type = StaticBool;
	Label = _Label;
	BlnVal = _val;
}

EZUI_Control_ToggleOption::EZUI_Control_ToggleOption(String _Label, bool _val, String _TrueLabel, String _FalseLabel)
{
	Type = StaticBool;
	Label = _Label;
	BlnVal = _val;
	BoolTrueText = _TrueLabel;
	BoolFalseText = _FalseLabel;
}

EZUI_Control_ToggleOption::EZUI_Control_ToggleOption(String _Label, bool * _val)
{
	Type = VarBool;
	Label = _Label;
	BlnRef = _val;
	BlnVal = *BlnRef;
}

EZUI_Control_ToggleOption::EZUI_Control_ToggleOption(String _Label, bool * _val, String _TrueLabel, String _FalseLabel)
{
	Type = VarBool;
	Label = _Label;
	BlnRef = _val;
	BlnVal = *BlnRef;
	BoolTrueText = _TrueLabel;
	BoolFalseText = _FalseLabel;
}
