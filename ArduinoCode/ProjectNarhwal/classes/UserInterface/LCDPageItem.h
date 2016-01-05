/* 
* LCDPageItem.h
*
* Created: 12/14/2015 9:22:40 PM
* Author: Customer
*/


#ifndef __LCDPAGEITEM_H__
#define __LCDPAGEITEM_H__

#include "LCDMenuItem.h"
#include "LCDMenu.h"

class LCDMenuItem;
class LCDPageItem
{
//variables
public:
	uint8_t col = 0;
	uint8_t row = 0;
	enum PageItemType { StaticString, StaticFloat, StaticInt, StaticUInt, StaticLong, StaticULong, StaticBool, StaticBoolWithText, VarString, VarFloat, VarInt, VarUInt, VarLong, VarULong, VarBool, VarBoolWithText, Button, None };
	PageItemType Type = None;
	
protected:
private:
	//Static Values
	String StrVal = "";
	float FltVal = 0.0;
	bool BlnVal = false;
	int IntVal = 0;
	int UIntVal = 0;
	int LongVal = 0;
	int ULongVal = 0;
	
	int floatPrecision = -1;
	String BoolTrueText = "";
	String BoolFalseText = "";
	
	//Referenced Values
	String *StrRef = NULL;
	float *FltRef = NULL;
	bool *BlnRef = NULL;
	int *IntRef = NULL;
	unsigned int *UIntRef = NULL;
	long *LongRef = NULL;
	unsigned long *ULongRef = NULL;
	
	//Button Value
	String ButtonName = "";
	int displayWidth = 0;
	LCDMenuItem * BtnLink = NULL;
	

//functions
public:
	//Instantiate - Constants
	LCDPageItem(uint8_t Ln, uint8_t Char, String val);
	LCDPageItem(uint8_t Ln, uint8_t Char, float val);
	LCDPageItem(uint8_t Ln, uint8_t Char, float val, int precision);
	LCDPageItem(uint8_t Ln, uint8_t Char, int val);
	LCDPageItem(uint8_t Ln, uint8_t Char, unsigned int val);
	LCDPageItem(uint8_t Ln, uint8_t Char, long val);
	LCDPageItem(uint8_t Ln, uint8_t Char, unsigned long val);
	LCDPageItem(uint8_t Ln, uint8_t Char, bool val);
	LCDPageItem(uint8_t Ln, uint8_t Char, bool val, String TrueText, String FalseText);
	
	//Instantiate - Variables
	LCDPageItem(uint8_t Ln, uint8_t Char, String * val);
	LCDPageItem(uint8_t Ln, uint8_t Char, float * val);
	LCDPageItem(uint8_t Ln, uint8_t Char, float * val, int precision);
	LCDPageItem(uint8_t Ln, uint8_t Char, int * val);
	LCDPageItem(uint8_t Ln, uint8_t Char, unsigned int * val);
	LCDPageItem(uint8_t Ln, uint8_t Char, long * val);
	LCDPageItem(uint8_t Ln, uint8_t Char, unsigned long * val);
	LCDPageItem(uint8_t Ln, uint8_t Char, bool * val);
	LCDPageItem(uint8_t Ln, uint8_t Char, bool * val, String TrueText, String FalseText);
	
	//Instantiate - Button
	LCDPageItem(uint8_t Ln, uint8_t Char, String BtnText, LCDMenuItem * SubMenu);
	
	//Print
	void print(LiquidCrystal_I2C * LCD);
	
	//Deconstruct
	LCDPageItem();
	~LCDPageItem();
protected:
private:
	//LCDPageItem( const LCDPageItem &c );
	//LCDPageItem& operator=( const LCDPageItem &c );

}; //LCDPageItem

#endif //__LCDPAGEITEM_H__
