/*
 *        File: EZUI_Control_ToggleOption.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - Toggle Option
 */

#ifndef __LCDTOGGLEOPTION_H__
#define __LCDTOGGLEOPTION_H__

//Includes
#include "EZUI_Control.h"

//Forward Declarations
class EZUI;
class EZUI_UI;

class EZUI_Control_ToggleOption : public EZUI_Control
{
//variables
public:
protected:
private:
	const bool isFlash = false;
	const void* _Label;
	enum ToggleOptionType { VarDigIO , VarBool };
	const ToggleOptionType ToggleType;
	const void * BoolTrueText;
	const void * BoolFalseText;
	
	bool * BlnRef = NULL;
	DigitalIO * DIORef = NULL;

//functions
public:

	//Over-ridden base classes
	boolean isSelectable() const  override;
	boolean hasValueText() const override;
	const char* LabelText() override;
	const char* ValueText() override;
	void Select(EZUI *UI) const override;
	
	~EZUI_Control_ToggleOption(){};
	
	//Constructors
	EZUI_Control_ToggleOption(char* Label, DigitalIO * DigIO_Object):											isFlash(false), EZUI_Control(EZUI_ControlType::ToggleControl), _Label(Label), ToggleType(VarDigIO), DIORef(DigIO_Object){};
	EZUI_Control_ToggleOption(const char* Label, DigitalIO * DigIO_Object):										isFlash(false), EZUI_Control(EZUI_ControlType::ToggleControl), _Label(Label), ToggleType(VarDigIO), DIORef(DigIO_Object){};
	EZUI_Control_ToggleOption(const char* Label, bool * val, char* TrueLabel, char* FalseLabel):				isFlash(false), EZUI_Control(EZUI_ControlType::ToggleControl), _Label(Label), ToggleType(VarBool),  BlnRef(val), BoolTrueText((void*)TrueLabel), BoolFalseText((void*)FalseLabel){};
	EZUI_Control_ToggleOption(const char* Label, bool * val, const char* TrueLabel, const char* FalseLabel):	isFlash(false), EZUI_Control(EZUI_ControlType::ToggleControl), _Label(Label), ToggleType(VarBool),  BlnRef(val), BoolTrueText((void*)TrueLabel), BoolFalseText((void*)FalseLabel){};
	
	//Constructors - FlashString
	EZUI_Control_ToggleOption(const __FlashStringHelper* Label, DigitalIO * DigIO_Object):																isFlash(true), EZUI_Control(EZUI_ControlType::ToggleControl), _Label(Label), ToggleType(VarDigIO), DIORef(DigIO_Object){};
	EZUI_Control_ToggleOption(const __FlashStringHelper* Label, bool * val, __FlashStringHelper* TrueLabel, __FlashStringHelper* FalseLabel):				isFlash(true), EZUI_Control(EZUI_ControlType::ToggleControl), _Label(Label), ToggleType(VarBool),  BlnRef(val), BoolTrueText((void*)TrueLabel), BoolFalseText((void*)FalseLabel){};
	EZUI_Control_ToggleOption(bool * val, __FlashStringHelper* TrueLabel, __FlashStringHelper* FalseLabel):	isFlash(true), EZUI_Control(EZUI_ControlType::ToggleControl), _Label(F("")), ToggleType(VarBool),  BlnRef(val), BoolTrueText((void*)TrueLabel), BoolFalseText((void*)FalseLabel){};
	
	//Get the Value
	int Value();
	
protected:
private:
	//LCDToggleOption( const LCDToggleOption &c );
	//LCDToggleOption& operator=( const LCDToggleOption &c );

}; //LCDToggleOption

#endif //__LCDTOGGLEOPTION_H__
