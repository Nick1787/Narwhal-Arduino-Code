/*
 *        File: EZUI_PageITem.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Display Page Item Class
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */


#ifndef __EZUI_PAGEITEM_H__
#define __EZUI_PAGEITEM_H__

#include "EZUI.h"
#include "EZUI_Menu.h"
#include "EZUI_MenuItem.h"
#include "./Controls/EZUI_Control_ToggleOption.h"
#include "./Controls/EZUI_Control_Link.h"

class EZUI;
class EZUI_Control_ToggleOption;
class EZUI_Control_Link;
class EZUI_Control_Button;
class EZUI_MenuItem;
class EZUI_PageItem
{
//variables
public:
	uint8_t col = 0;
	uint8_t row = 0;
	enum PageItemType { StaticString, StaticFloat, StaticDouble, StaticInt, StaticUInt, StaticLong, StaticULong, StaticBool, StaticBoolWithText, VarString, VarFloat, VarDouble, VarInt, VarUInt, VarLong, VarULong, VarBool, VarBoolWithText, ToggleOption, Link, None };
	PageItemType Type = None;
	
protected:
private:
	//Static Values
	String StrVal = "";
	float FltVal = 0.0;
	double DblVal = 0.0;
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
	double *DblRef = NULL;
	bool *BlnRef = NULL;
	int *IntRef = NULL;
	unsigned int *UIntRef = NULL;
	long *LongRef = NULL;
	unsigned long *ULongRef = NULL;
	
	//UI Items
	int displayWidth = 0;
	EZUI_Control_ToggleOption * TglOptRef = NULL;
	EZUI_Control_Link * LnkRef = NULL;

//functions
public:
	//Instantiate - Constants
	EZUI_PageItem(uint8_t col, uint8_t row, String val);
	EZUI_PageItem(uint8_t col, uint8_t row, float val);
	EZUI_PageItem(uint8_t col, uint8_t row, float val, int precision);
	EZUI_PageItem(uint8_t col, uint8_t row, double val);
	EZUI_PageItem(uint8_t col, uint8_t row, double val, int precision);
	EZUI_PageItem(uint8_t col, uint8_t row, int val);
	EZUI_PageItem(uint8_t col, uint8_t row, unsigned int val);
	EZUI_PageItem(uint8_t col, uint8_t row, long val);
	EZUI_PageItem(uint8_t col, uint8_t row, unsigned long val);
	EZUI_PageItem(uint8_t col, uint8_t row, bool val);
	EZUI_PageItem(uint8_t col, uint8_t row, bool val, String TrueText, String FalseText);
	
	//Instantiate - Variables
	EZUI_PageItem(uint8_t col, uint8_t row, String * val);
	EZUI_PageItem(uint8_t col, uint8_t row, float * val);
	EZUI_PageItem(uint8_t col, uint8_t row, float * val, int precision);
	EZUI_PageItem(uint8_t col, uint8_t row, double * val);
	EZUI_PageItem(uint8_t col, uint8_t row, double * val, int precision);
	EZUI_PageItem(uint8_t col, uint8_t row, int * val);
	EZUI_PageItem(uint8_t col, uint8_t row, unsigned int * val);
	EZUI_PageItem(uint8_t col, uint8_t row, long * val);
	EZUI_PageItem(uint8_t col, uint8_t row, unsigned long * val);
	EZUI_PageItem(uint8_t col, uint8_t row, bool * val);
	EZUI_PageItem(uint8_t col, uint8_t row, bool * val, String TrueText, String FalseText);
	
	//Instantiate - Interactable Items
	EZUI_PageItem(uint8_t col, uint8_t row, EZUI_MenuItem * SubMenu);
	EZUI_PageItem(uint8_t col, uint8_t row, EZUI_Control_ToggleOption * Item);
	EZUI_PageItem(uint8_t col, uint8_t row, EZUI_Control_Link * Item);
	
	//Print
	void print(LiquidCrystal_I2C * LCD, bool refresh);
	void ItemSelect(EZUI *UI);						//Prints Menu Item to Screen
	
	//Deconstruct
	EZUI_PageItem();
	~EZUI_PageItem();
protected:
private:
	//LCDPageItem( const LCDPageItem &c );
	//LCDPageItem& operator=( const LCDPageItem &c );

}; //LCDPageItem

#endif //__LCDPAGEITEM_H__
