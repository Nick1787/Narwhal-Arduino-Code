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
	switch(ToggleType){
		case(VarDigIO):
			DigitalIO *DIO;
			DIO = DIORef;
			return (*DIO).TrueLabel;
		case(VarBool):
			return BoolTrueText;
	}
}

String EZUI_Control_ToggleOption::FalseLabel(void){
	switch(ToggleType){
		case(VarDigIO):
			DigitalIO *DIO;
			DIO = DIORef;
			return (*DIO).FalseLabel;
		case(VarBool):
			return BoolFalseText;
	}	
}

int EZUI_Control_ToggleOption::Value(){
	switch(ToggleType){
		case(VarDigIO):
			DigitalIO *DIO;
			DIO = DIORef;
			return (*DIO).Value();
		case(VarBool):
			return *BlnRef;
	}
}

void EZUI_Control_ToggleOption::Write(int _value){
	switch(ToggleType){
		case(VarDigIO):
			DigitalIO *DIO;
			DIO = DIORef;
			(*DIO).Write(_value);
			break;
		case(VarBool):
			*BlnRef = _value;
			break;
	}
}

void EZUI_Control_ToggleOption::Toggle(void) const{
	switch(ToggleType){
		case(VarDigIO):
			DigitalIO *DIO;
			DIO = DIORef;
			if ((*DIO).Value()){
				(*DIO).Write(0);
			}else{
				(*DIO).Write(1);
			}
			break;
		case(VarBool):
			*BlnRef = !(*BlnRef);
			break;
	}
}

EZUI_Control_ToggleOption::EZUI_Control_ToggleOption(String _Label, DigitalIO * DigitalIOObject)
{
	Type = ToggleOpt;
	Label = _Label;
	ToggleType = VarDigIO;
	DIORef = DigitalIOObject;	
}


EZUI_Control_ToggleOption::EZUI_Control_ToggleOption(String _Label, bool * _val)
{
	Type = ToggleOpt;
	ToggleType = VarBool;
	Label = _Label;
	BlnRef = _val;
}

EZUI_Control_ToggleOption::EZUI_Control_ToggleOption(String _Label, bool * _val, String _TrueLabel, String _FalseLabel)
{
	ToggleType = VarBool;
	Label = _Label;
	BlnRef = _val;
	BoolTrueText = _TrueLabel;
	BoolFalseText = _FalseLabel;
}
