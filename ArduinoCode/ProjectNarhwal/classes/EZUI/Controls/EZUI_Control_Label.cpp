/* 
* EZUI_Control_Lablel.cpp
*
* Created: 1/10/2016 9:22:27 AM
* Author: Customer
*/


#include "EZUI_Control_Label.h"

// default destructor
EZUI_Control_Label::~EZUI_Control_Label()
{
} //~EZUI_Control_Lablel

/****************************************************************************
	Constructors - Static Values
*****************************************************************************/

EZUI_Control_Label::EZUI_Control_Label(String val){
	Type = StaticString;
	
	//Save the value
	this->ItemRef = new String();
	*(String*)(this->ItemRef) = val;
}

EZUI_Control_Label::EZUI_Control_Label(float val){
	this->Type = StaticFloat;
	
	//Save the value
	this->ItemRef = new float();
	*(float*)(this->ItemRef) = val;
}

EZUI_Control_Label::EZUI_Control_Label(double val){
	this->Type = StaticDouble;
	
	//Save the value
	this->ItemRef = new double();
	*(double*)(this->ItemRef) = val;
}

EZUI_Control_Label::EZUI_Control_Label(int val){
	this->Type = StaticInt;
	
	//Save the value
	this->ItemRef = new int();
	*(int*)(this->ItemRef) = val;
}

EZUI_Control_Label::EZUI_Control_Label(unsigned int val){
	this->Type = StaticUInt;
	
	//Save the value
	this->ItemRef = new unsigned int();
	*(unsigned int*)(this->ItemRef) = val;
}

EZUI_Control_Label::EZUI_Control_Label(long val){
	this->Type = StaticLong;
	
	//Save the value
	this->ItemRef = new long();
	*(long*)(this->ItemRef) = val;
}

EZUI_Control_Label::EZUI_Control_Label(unsigned long val){
	this->Type = StaticULong;
	
	//Save the value
	this->ItemRef = new unsigned long();
	*(unsigned long*)(this->ItemRef) = val;
}

EZUI_Control_Label::EZUI_Control_Label(bool val){
	this->Type = StaticBool;
	
	//Save the value
	this->ItemRef = new bool();
	*(bool*)(this->ItemRef) = val;
}

/****************************************************************************
	Constructors - Dynamic Values
*****************************************************************************/

EZUI_Control_Label::EZUI_Control_Label(String *val){
	Type = DynamicString;
	this->ItemRef = val;
}

EZUI_Control_Label::EZUI_Control_Label(float *val){
	Type = DynamicFloat;
	this->ItemRef = val;
}

EZUI_Control_Label::EZUI_Control_Label(double *val){
	Type = DynamicDouble;
	this->ItemRef = val;
}

EZUI_Control_Label::EZUI_Control_Label(int *val){
	Type = DynamicInt;
	this->ItemRef = val;
}

EZUI_Control_Label::EZUI_Control_Label(unsigned int *val){
	Type = DynamicUInt;
	this->ItemRef = val;
}

EZUI_Control_Label::EZUI_Control_Label(long *val){
	Type = DynamicLong;
	this->ItemRef = val;
}

EZUI_Control_Label::EZUI_Control_Label(unsigned long *val){
	Type = DynamicULong;
	this->ItemRef = val;
}

EZUI_Control_Label::EZUI_Control_Label(bool *val){
	Type = DynamicBool;
	this->ItemRef = val;
}


/****************************************************************************
	Constructors - With number of decimal places
*****************************************************************************/

//TODO (maybe)

/****************************************************************************
	Print and Text Format
*****************************************************************************/
String EZUI_Control_Label::Text(){
	String Str = "";
	switch(this->Type){
		case(StaticString):
			Str = *(String*)(this->ItemRef);
			break;
		case(StaticFloat):
			Str = String(*(float*)(this->ItemRef));
			break;
		case(StaticDouble):
			Str = String(*(double*)(this->ItemRef));
			break;
		case(StaticInt):
			Str = String(*(int*)(this->ItemRef));
			break;
		case(StaticUInt):
			Str = String(*(unsigned int*)(this->ItemRef));
			break;
		case(StaticLong):
			Str = String(*(long*)(this->ItemRef));
			break;
		case(StaticULong):
			Str = String(*(unsigned long*)(this->ItemRef));
			break;
		case(StaticBool):
			Str = String(*(bool*)(this->ItemRef));
			break;
		
		case(DynamicString):
			Str = *(String*)(this->ItemRef);
			break;
		case(DynamicFloat):
			Str = String(*(float*)(this->ItemRef));
			break;
		case(DynamicDouble):
			Str = String(*(double*)(this->ItemRef));
			break;
		case(DynamicInt):
			Str = String(*(int*)(this->ItemRef));
			break;
		case(DynamicUInt):
			Str = String(*(unsigned int*)(this->ItemRef));
			break;
		case(DynamicLong):
			Str = String(*(long*)(this->ItemRef));
			break;
		case(DynamicULong):
			Str = String(*(unsigned long*)(this->ItemRef));
			break;
		case(DynamicBool):
			Str = String(*(bool*)(this->ItemRef));
			break;
	}
	return Str;
}

void EZUI_Control_Label::Print(LiquidCrystal_I2C *LCD, uint8_t col, uint8_t row){
	if((millis() - timeLastPrinted)>1000){
		//First Print blanks to over-write the whole field
		LCD->setCursor(col,row);
		int i=0;
		for(i=0;i<prevOut.length();i++){
			LCD->print(" ");
		}
	
		//Print the value
		LCD->setCursor(col,row);
		prevOut = Text();
		LCD->print(prevOut);
	}
	timeLastPrinted = millis();
}

