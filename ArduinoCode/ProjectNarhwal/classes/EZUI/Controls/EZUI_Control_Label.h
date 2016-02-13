/*
 *        File: EZUI_Control_Label.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - Label Control
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#ifndef __EZUI_CONTROL_LABEL_H__
#define __EZUI_CONTROL_LABEL_H__

#include "../../include/LiquidCrystal/LiquidCrystal_I2C.h"

class EZUI_Control_Label
{
//variables
public:
	enum EZUI_Control_Label_Type {None, StaticString, StaticFloat, StaticDouble, StaticInt, StaticUInt, StaticLong, StaticULong, StaticBool};
	EZUI_Control_Label_Type Type = None;	//Not initialized to any value
	
protected:
private:
	//When was this last printed.  Used to refresh page
	unsigned long timeLastPrinted = -1;
	
	//Values to be stored for the different types of labels
	String *stringVal = NULL;
	float *floatVal = NULL;
	double *doubleVal = NULL;
	bool *boolVal = NULL;
	int *intVal = NULL;
	unsigned int *uIntVal = NULL;
	long *longVal = NULL;
	unsigned long *uLongVal = NULL;
	
	//Special items
	unsigned int decPlaces = NULL;		//Number of decimal places for int and double
	String prevOut = "";
	
//functions
public:
	//Destructor
	~EZUI_Control_Label();
	
	//Instantiate - No print format specifier
	EZUI_Control_Label(String val);
	EZUI_Control_Label(float val);
	EZUI_Control_Label(double val);
	EZUI_Control_Label(int val);
	EZUI_Control_Label(unsigned int val);
	EZUI_Control_Label(long val);
	EZUI_Control_Label(unsigned long val);
	EZUI_Control_Label(bool val);
	
	//Instantiate - With print format specifier
	EZUI_Control_Label(float val, unsigned int decPlaces);
	EZUI_Control_Label(double val, unsigned int decPlaces);
	
	//Print
	void Print(LiquidCrystal_I2C * LCD, uint8_t col, uint8_t row);
	String Text();
	
protected:
private:
	EZUI_Control_Label( const EZUI_Control_Label &c );
	EZUI_Control_Label& operator=( const EZUI_Control_Label &c );

}; //EZUI_Control_Lablel

#endif //__EZUI_CONTROL_LABLEL_H__
