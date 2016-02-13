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
	Constructors - No Print Format
*****************************************************************************/

EZUI_Control_Label::EZUI_Control_Label(String val){
	Type = StaticString;
	
	//Save the value
	this->stringVal = new String();
	*(this->stringVal) = val;
}

EZUI_Control_Label::EZUI_Control_Label(float val){
	this->Type = StaticDouble;
	
	//Save the value
	float *Storage = new float();
	*Storage = val;
	this->floatVal = Storage;
}

EZUI_Control_Label::EZUI_Control_Label(double val){
	this->Type = StaticDouble;
	
	//Save the value
	double *Storage = new double();
	*Storage = val;
	this->doubleVal = Storage;
}

EZUI_Control_Label::EZUI_Control_Label(int val){
	this->Type = StaticInt;
	
	//Save the value
	int *Storage = new int();
	*Storage = val;
	this->intVal = Storage;
}

EZUI_Control_Label::EZUI_Control_Label(unsigned int val){
	this->Type = StaticUInt;
	
	//Save the value
	unsigned int *Storage = new unsigned int();
	*Storage = val;
	this->uIntVal = Storage;
}

EZUI_Control_Label::EZUI_Control_Label(long val){
	this->Type = StaticLong;
	
	//Save the value
	long *Storage = new long();
	*Storage = val;
	this->longVal = Storage;
}

EZUI_Control_Label::EZUI_Control_Label(unsigned long val){
	this->Type = StaticULong;
	
	//Save the value
	unsigned long *Storage = new unsigned long();
	*Storage = val;
	this->uLongVal = Storage;
}

EZUI_Control_Label::EZUI_Control_Label(bool val){
	this->Type = StaticBool;
	
	//Save the value
	bool *Storage = new bool();
	*Storage = val;
	this->boolVal = Storage;
}


/****************************************************************************
	Constructors - With number of decimal places
*****************************************************************************/

EZUI_Control_Label::EZUI_Control_Label(float val, unsigned int decimalPlaces){
	this->Type = StaticDouble;
	
	//Save the value
	float *Storage = new float();
	*Storage = val;
	this->floatVal = Storage;
	
	//Save the print format
	this->decPlaces = decimalPlaces;
}

EZUI_Control_Label::EZUI_Control_Label(double val, unsigned int decimalPlaces){
	this->Type = StaticDouble;
	
	//Save the value
	double *Storage = new double();
	*Storage = val;
	this->doubleVal = Storage;
	
	//Save the print format
	this->decPlaces = decimalPlaces;
}

/****************************************************************************
	Print and Text Format
*****************************************************************************/
String EZUI_Control_Label::Text(){
	String Str = "";
	switch(this->Type){
		case(StaticString):
			Str = *(this->stringVal);
			break;
		case(StaticFloat):
			if(decPlaces == NULL){
				Str = String(*(this->floatVal));
			}else{
				Str = String(*(this->floatVal),decPlaces);
			}
			break;
		case(StaticDouble):
			if(decPlaces == NULL){
				Str = String(*(this->doubleVal));
			}else{
				Str = String(*(this->doubleVal),decPlaces);
			}
			break;
		case(StaticInt):
			Str = String(*(this->intVal));
			break;
		case(StaticUInt):
			Str = String(*(this->uIntVal));
			break;
		case(StaticLong):
			Str = String(*(this->longVal));
			break;
		case(StaticULong):
			Str = String(*(this->uIntVal));
			break;
		case(StaticBool):
			Str = String(*(this->boolVal));
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

