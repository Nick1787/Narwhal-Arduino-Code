/* 
* LCDToggleOption.h
*
* Created: 1/4/2016 9:06:37 PM
* Author: Customer
*/

#include "../../EnhancedIO/DigitalIO.h"

#ifndef __LCDTOGGLEOPTION_H__
#define __LCDTOGGLEOPTION_H__

class EZUI_Control_ToggleOption
{
//variables
public:
	String Label = "";
	enum ToggleOptionType { VarDigIO , StaticBool, VarBool };
	ToggleOptionType Type = StaticBool;
	
protected:
private:
	String BoolTrueText = "true";
	String BoolFalseText = "false";
	bool BlnVal = false;
	bool *BlnRef = NULL;
	DigitalIO * DIORef = NULL;

//functions
public:
	EZUI_Control_ToggleOption();
	String TrueLabel(void);
	String FalseLabel(void);
	int Value();
	void Write(int value);
	void Toggle();
	EZUI_Control_ToggleOption(String Label, DigitalIO * DigIO_Object);
	EZUI_Control_ToggleOption(String Label, bool val);
	EZUI_Control_ToggleOption(String Label, bool val, String TrueLabel, String FalseTable);
	EZUI_Control_ToggleOption(String Label, bool * val);
	EZUI_Control_ToggleOption(String Label, bool * val, String TrueLabel, String FalseTable);
	~EZUI_Control_ToggleOption();
	
protected:
private:
	//LCDToggleOption( const LCDToggleOption &c );
	//LCDToggleOption& operator=( const LCDToggleOption &c );

}; //LCDToggleOption

#endif //__LCDTOGGLEOPTION_H__
