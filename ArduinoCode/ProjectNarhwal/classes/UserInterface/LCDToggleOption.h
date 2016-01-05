/* 
* LCDToggleOption.h
*
* Created: 1/4/2016 9:06:37 PM
* Author: Customer
*/

#include "../DigIO.h"

#ifndef __LCDTOGGLEOPTION_H__
#define __LCDTOGGLEOPTION_H__

class LCDToggleOption
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
	DigIO * DIORef = NULL;

//functions
public:
	LCDToggleOption();
	String TrueLabel(void);
	String FalseLabel(void);
	int Value();
	void Write(int value);
	void Toggle();
	LCDToggleOption(String Label, DigIO * DigIO_Object);
	LCDToggleOption(String Label, bool val);
	LCDToggleOption(String Label, bool val, String TrueLabel, String FalseTable);
	LCDToggleOption(String Label, bool * val);
	LCDToggleOption(String Label, bool * val, String TrueLabel, String FalseTable);
	~LCDToggleOption();
	
protected:
private:
	//LCDToggleOption( const LCDToggleOption &c );
	//LCDToggleOption& operator=( const LCDToggleOption &c );

}; //LCDToggleOption

#endif //__LCDTOGGLEOPTION_H__
