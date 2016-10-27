/* 
* LCDToggleOption.cpp
*
* Created: 1/4/2016 9:06:37 PM
* Author: Customer
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
String EZUI_Control_ToggleOption::LabelText() {return _Label;};
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
			return BoolTrueText;
			}else{
			return BoolFalseText;
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
	}
};
