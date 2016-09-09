/* 
* EZUI_Control_Lablel.cpp
*
* Created: 1/10/2016 9:22:27 AM
* Author: Customer
*/


#include "EZUI_Control_Label.h"

/****************************************************************************
	Constructors - Static Values
*****************************************************************************/

EZUI_Control_Label::EZUI_Control_Label(char val[]){
	//Serial.println(F("--Label-StaticString--");
	//Serial.flush();
	Label_Type = LblString;
	this->Type = Label;
	
	//Save the value
	//Serial.print(F("---");
	//Serial.print(val);
	//Serial.println(F("---");
	//Serial.flush();
	this->ItemRef = new String(val);
	
	//Serial.print(F(">>>");
	//Serial.print(*(String*)this->ItemRef);
	//Serial.print(F("<<<");
	//Serial.flush();
}

EZUI_Control_Label::EZUI_Control_Label(float *val){
	//Serial.println(F("--Label-DynamicFloat--");
	//Serial.flush();
	this->Label_Type = LblFloat;
	this->Type = Label;
	this->ItemRef = val;
}

EZUI_Control_Label::EZUI_Control_Label(double *val){
	//Serial.println(F("--Label-DynamicDouble--");
	//Serial.flush();
	Label_Type = LblDouble;
	this->Type = Label;
	this->ItemRef = val;
}

EZUI_Control_Label::EZUI_Control_Label(int *val){
	//Serial.println(F("--Label-DynamicInt--");
	//Serial.flush();
	Label_Type = LblInt;
	this->Type = Label;
	this->ItemRef = val;
}

EZUI_Control_Label::EZUI_Control_Label(unsigned int *val){
	//Serial.println(F("--Label-DynamicUint--");
	//Serial.flush();
	Label_Type = LblUInt;
	this->Type = Label;
	this->ItemRef = val;
}

EZUI_Control_Label::EZUI_Control_Label(long *val){
	//Serial.println(F("--Label-DynamicLong--");
	//Serial.flush();
	Label_Type = LblLong;
	this->Type = Label;
	this->ItemRef = val;
}

EZUI_Control_Label::EZUI_Control_Label(unsigned long *val){
	//Serial.println(F("--Label-DynamicULong--");
	//Serial.flush();
	Label_Type = LblULong;
	this->Type = Label;
	this->ItemRef = val;
}

EZUI_Control_Label::EZUI_Control_Label(boolean *val, String TrueTxt, String FalseTxt){
	Label_Type = LblBoolWithText;
	blnTrueTxt = TrueTxt;
	blnFalseTxt = FalseTxt;
	this->Type = Label;
	this->ItemRef = val;
}

EZUI_Control_Label::EZUI_Control_Label(DigitalIO *val){
	Label_Type = LblDigitalIO;
	this->Type = Label;
	this->ItemRef = val;
}


/****************************************************************************
	Constructors - With number of decimal places
*****************************************************************************/

//TODO (maybe)

/****************************************************************************
	Print and Text Format
*****************************************************************************/
String EZUI_Control_Label::Text() const {
	String Str = "";
	switch(this->Label_Type){;		
		case(LblString):
			Str = *(String*)(this->ItemRef);
			break;
		case(LblFloat):
			Str = String(*(float*)(this->ItemRef));
			break;
		case(LblDouble):
			Str = String(*(double*)(this->ItemRef));
			break;
		case(LblInt):
			Str = String(*(int*)(this->ItemRef));
			break;
		case(LblUInt):
			Str = String(*(unsigned int*)(this->ItemRef));
			break;
		case(LblLong):
			Str = String(*(long*)(this->ItemRef));
			break;
		case(LblULong):
			Str = String(*(unsigned long*)(this->ItemRef));
			break;
		case(LblBoolWithText):{
			boolean val = *(bool*)(this->ItemRef);
			if(val){
				Str = blnTrueTxt;
			}else{
				Str = blnFalseTxt;
			}
			break;
		}
		case(LblDigitalIO):
			DigitalIO val = *(DigitalIO*)(this->ItemRef);
			if(val.Value()){
				Str= val.TrueLabel;
			}else{
				Str = val.FalseLabel;
			}
			break;
	}
	return Str;
}

