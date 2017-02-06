/*
 *        File: EZUI_Control_ToggleOption.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - Toggle Option
 *			- Control for interacting with a Toggle Option
 */

#include "EZUI_Control_ToggleOption.h"

int EZUI_Control_ToggleOption::Value(){
	switch(ToggleType){
		case(VarDigIO):
			DigitalIO *DIO;
			DIO = DIORef;
			return (*DIO).Value();
		case(VarBool):
			return *BlnRef;
	}
};

//Over-ridden base classes
boolean EZUI_Control_ToggleOption::isSelectable() const  {return true;};
boolean EZUI_Control_ToggleOption::hasValueText() const {return true;};
String EZUI_Control_ToggleOption::LabelText() { 
	if(isFlash){
		return ((__FlashStringHelper*)_Label);
	}else{
		return ((const char*)_Label);
	}
};
String EZUI_Control_ToggleOption::ValueText() {
	int val = Value();
	switch(ToggleType){
		case(VarDigIO):
		DigitalIO *DIO;
		DIO = DIORef;
		if(val){
			return (*DIO).TrueLabel;
			}else{
			return (*DIO).FalseLabel;
		}
		case(VarBool):
		if(val){
			if(isFlash){
				return (__FlashStringHelper*) BoolTrueText;
			}else{
				return (const char*) BoolTrueText;
			}
		}else{
			if(isFlash){
				return (__FlashStringHelper*) BoolFalseText;
			}else{
				return (const char*) BoolFalseText;
			}
		}
	}
}
void EZUI_Control_ToggleOption::Select(EZUI *UI) const {

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
		default:
			break;
	}
};
