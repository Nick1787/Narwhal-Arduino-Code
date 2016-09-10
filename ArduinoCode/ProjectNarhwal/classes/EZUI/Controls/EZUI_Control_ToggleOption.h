/* 
* LCDToggleOption.h
*
* Created: 1/4/2016 9:06:37 PM
* Author: Customer
*/

#ifndef __LCDTOGGLEOPTION_H__
#define __LCDTOGGLEOPTION_H__

#include "../EZUI.h"
#include "../../EnhancedTypes/DigitalIO.h"

class EZUI_Control_ToggleOption : public EZUI_Control
{
//variables
public:
protected:
private:
	const char* _Label;
	enum ToggleOptionType { VarDigIO , VarBool };
	const PROGMEM ToggleOptionType ToggleType;
	const PROGMEM char * BoolTrueText;
	const PROGMEM char * BoolFalseText;
	
	bool * BlnRef = NULL;
	DigitalIO * DIORef = NULL;

//functions
public:

	//Over-ridden base classes
	boolean isSelectable() const  override {return true;};
	boolean hasValueText() const override {return true;};
	String LabelText() override {return _Label;};
	String ValueText() override{
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
	void Select(EZUI *UI) const override {
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
	
	~EZUI_Control_ToggleOption(){};
	
	//Constructors
	EZUI_Control_ToggleOption(char* Label, DigitalIO * DigIO_Object):			EZUI_Control(EZUI_ControlType::ToggleControl), _Label(Label), ToggleType(VarDigIO), DIORef(DigIO_Object){};
	EZUI_Control_ToggleOption(const char* Label, DigitalIO * DigIO_Object):		EZUI_Control(EZUI_ControlType::ToggleControl), _Label(Label), ToggleType(VarDigIO), DIORef(DigIO_Object){};
	EZUI_Control_ToggleOption(char* Label, bool * val):							EZUI_Control(EZUI_ControlType::ToggleControl), _Label(Label), ToggleType(VarBool),  BlnRef(val), BoolTrueText("True"), BoolFalseText("False"){};
	EZUI_Control_ToggleOption(const char* Label, bool * val):					EZUI_Control(EZUI_ControlType::ToggleControl), _Label(Label), ToggleType(VarBool),  BlnRef(val), BoolTrueText("True"), BoolFalseText("False"){};
	EZUI_Control_ToggleOption(const char* Label, bool * val, char* TrueLabel, char* FalseLabel):				EZUI_Control(EZUI_ControlType::ToggleControl), _Label(Label), ToggleType(VarBool),  BlnRef(val), BoolTrueText(TrueLabel), BoolFalseText(FalseLabel){};
	EZUI_Control_ToggleOption(const char* Label, bool * val, const char* TrueLabel, const char* FalseLabel):	EZUI_Control(EZUI_ControlType::ToggleControl), _Label(Label), ToggleType(VarBool),  BlnRef(val), BoolTrueText(TrueLabel), BoolFalseText(FalseLabel){};
	
	//Get the Value
	int Value(){
		switch(ToggleType){
			case(VarDigIO):
				DigitalIO *DIO;
				DIO = DIORef;
				return (*DIO).Value();
			case(VarBool):
				return *BlnRef;
		}
	};
	
protected:
private:
	//LCDToggleOption( const LCDToggleOption &c );
	//LCDToggleOption& operator=( const LCDToggleOption &c );

}; //LCDToggleOption

#endif //__LCDTOGGLEOPTION_H__
