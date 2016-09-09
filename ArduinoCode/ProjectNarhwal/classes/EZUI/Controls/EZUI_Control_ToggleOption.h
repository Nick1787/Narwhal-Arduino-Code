/* 
* LCDToggleOption.h
*
* Created: 1/4/2016 9:06:37 PM
* Author: Customer
*/

#ifndef __LCDTOGGLEOPTION_H__
#define __LCDTOGGLEOPTION_H__

#include "../EZUI.h"
#include "../../EnhancedIO/DigitalIO.h"

class EZUI_Control_ToggleOption : public EZUI_Control
{
//variables
public:
	using EZUI_Control::Type;
	String Label = "";
	enum ToggleOptionType { VarDigIO , VarBool };
	ToggleOptionType ToggleType = VarBool;
	
protected:
private:
	String BoolTrueText = "true";
	String BoolFalseText = "false";
	bool *BlnRef = NULL;
	DigitalIO * DIORef = NULL;

//functions
public:

	boolean isSelectable() const  override {return true;};
	String Text() const override {return Label;};
	void Select(EZUI *UI) const override {Toggle();};
	
	EZUI_Control_ToggleOption();
	String TrueLabel(void);
	String FalseLabel(void);
	int Value();
	void Write(int value);
	void Toggle() const;
	EZUI_Control_ToggleOption(String Label, DigitalIO * DigIO_Object);
	EZUI_Control_ToggleOption(String Label, bool * val);
	EZUI_Control_ToggleOption(String Label, bool * val, String TrueLabel, String FalseLabel);
	~EZUI_Control_ToggleOption();
	
protected:
private:
	//LCDToggleOption( const LCDToggleOption &c );
	//LCDToggleOption& operator=( const LCDToggleOption &c );

}; //LCDToggleOption

#endif //__LCDTOGGLEOPTION_H__
