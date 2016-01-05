/* 
* LCDPageItem.cpp
*
* Created: 12/14/2015 9:22:39 PM
* Author: Customer
*/


#include "LCDPageItem.h"

// default constructor
LCDPageItem::LCDPageItem()
{
} //LCDPageItem

// default destructor
LCDPageItem::~LCDPageItem()
{
} //~LCDPageItem


LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, String val){
	col = colIndx;
	row = rowIndx;
	Type = StaticString;
	StrVal = val;
}

LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, float val){
	col = colIndx;
	row = rowIndx;
	Type = StaticFloat;
	FltVal = val;
}

LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, float val, int precision){	
	col = colIndx;
	row = rowIndx;
	Type = StaticFloat;
	floatPrecision = precision;
	FltVal = val;
}

LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, int val){	
	col = colIndx;
	row = rowIndx;
	Type = StaticInt;
	IntVal = val;
}

LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, unsigned int val){	
	col = colIndx;
	row = rowIndx;
	Type = StaticUInt;
	UIntVal = val;
}

LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, long val){
	col = colIndx;
	row = rowIndx;
	Type = StaticLong;
	LongVal = val;
}

LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, unsigned long val){
	col = colIndx;
	row = rowIndx;
	Type = StaticULong;
	LongVal = val;
}

LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, bool val){
	col = colIndx;
	row = rowIndx;
	Type = StaticBool;
	BlnVal = val;
}

LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, bool val, String TrueText, String FalseText){
	col = colIndx;
	row = rowIndx;
	Type = StaticBoolWithText;
	BoolTrueText = TrueText;
	BoolFalseText = FalseText;
	BlnVal = val;
}

//Instantiate - Variables
LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, String *val){
	col = colIndx;
	row = rowIndx;
	Type = VarString;
	StrRef = val;
	StrVal = *val;
}

LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, float *val){
	col = colIndx;
	row = rowIndx;
	Type = VarFloat;
	FltRef = val;
	FltVal = *val;
}

LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, float *val, int precision){
	col = colIndx;
	row = rowIndx;
	Type = VarFloat;
	FltRef = val;
	FltVal = *val;
	floatPrecision = precision;
}

LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, int *val){
	col = colIndx;
	row = rowIndx;
	Type = VarInt;
	IntRef = val;
	IntVal = *val;
}

LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, unsigned int *val){
	col = colIndx;
	row = rowIndx;
	Type = VarUInt;
	UIntRef = val;
	UIntVal = *val;
}

LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, long *val){
	col = colIndx;
	row = rowIndx;
	Type = VarLong;
	LongRef = val;
	LongVal = *val;
}

LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, unsigned long *val){
	col = colIndx;
	row = rowIndx;
	Type = VarULong;
	ULongRef = val;
	ULongVal = *val;
}

LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, bool *val){
	col = colIndx;
	row = rowIndx;
	Type = VarBool;
	BlnRef = val;
	BlnVal = *val;
}


LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, bool *val, String TrueText, String FalseText){
	col = colIndx;
	row = rowIndx;
	Type = VarBoolWithText;
	BlnRef = val;
	BlnVal = *val;
	BoolTrueText = TrueText;
	BoolFalseText = FalseText;
}

//Instantiate - Button
LCDPageItem::LCDPageItem(uint8_t colIndx, uint8_t rowIndx, String BtnText, LCDMenuItem * SubMenu){
	col = colIndx;
	row = rowIndx;
	Type = Button;
	ButtonName = BtnText;	
}

void LCDPageItem::print(LiquidCrystal_I2C * LCD){
	LCD->setCursor(row, col);
	switch(Type){
		case None:
			break;
			
		case StaticInt:
			LCD->print(IntVal);
			break;
		
		case StaticUInt:
			LCD->print(UIntVal);
			break;
		
		case StaticLong:
			LCD->print(LongVal);
			break;
		
		case StaticULong:
			LCD->print(ULongVal);
			break;
		
		case StaticFloat:
			LCD->print(FltVal);
			break;
		
		case StaticBool:
			LCD->print(BlnVal);
			break;
		
		case StaticBoolWithText:
			if(BlnVal == true){
				LCD->print(BoolTrueText);
			}else{
				LCD->print(BoolFalseText);
			}
			break;
		
		case StaticString:
			Serial.print("Printing Staic String: " + StrVal);
			LCD->print(StrVal);
			break;
		
		case VarInt:
			if( IntVal != *IntRef ){
				IntVal = *IntRef;
				LCD->print(IntVal);
			}
			break;
		
		case VarUInt:
			if( UIntVal != *UIntRef ){
				UIntVal = *UIntRef;
				LCD->print(UIntVal);
			}
			break;
		
		case VarLong:
			if( LongVal != *LongRef ){
				LongVal = *LongRef;
				LCD->print(LongVal);
			}
			break;	
		
		case VarULong:
			if( ULongVal != *ULongRef ){
				ULongVal = *ULongRef;
				LCD->print(ULongVal);
			}
			break;
			
		case VarFloat:
			if( FltVal != *FltRef ){
				FltVal = *FltRef;
				LCD->print(FltVal);
			}
			break;
			
		case VarBool:
			if( BlnVal != *BlnRef ){
				BlnVal = *BlnRef;
				LCD->print(BlnVal);
			}
			break; 
			
		case VarBoolWithText:
			if(BlnVal != *BlnRef){
				BlnVal = BlnRef;
				if(BlnVal == true){
					LCD->print(BoolTrueText);
				}else{
					LCD->print(BoolFalseText);	
				}
			}
			break;
			
		case VarString:
			if( StrVal != *StrRef ){
				StrVal = *StrRef;
				Serial.print("Printing Var String: " + StrVal);
				LCD->print(StrVal);
			}
			break;
			
	}
}