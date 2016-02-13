/*
 *        File: EZUI_PageITem.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Display Page Item Class
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */


#include "EZUI_PageItem.h"

// default constructor
EZUI_PageItem::EZUI_PageItem()
{
} //LCDPageItem

// default destructor
EZUI_PageItem::~EZUI_PageItem()
{
} //~LCDPageItem


EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, String val){
	col = colIndx;
	row = rowIndx;
	Type = StaticString;
	StrVal = val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, float val){
	col = colIndx;
	row = rowIndx;
	Type = StaticFloat;
	FltVal = val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, double val){
	col = colIndx;
	row = rowIndx;
	Type = StaticDouble;
	DblVal = val;
}
EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, float val, int precision){	
	col = colIndx;
	row = rowIndx;
	Type = StaticFloat;
	floatPrecision = precision;
	FltVal = val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, int val){	
	col = colIndx;
	row = rowIndx;
	Type = StaticInt;
	IntVal = val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, unsigned int val){	
	col = colIndx;
	row = rowIndx;
	Type = StaticUInt;
	UIntVal = val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, long val){
	col = colIndx;
	row = rowIndx;
	Type = StaticLong;
	LongVal = val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, unsigned long val){
	col = colIndx;
	row = rowIndx;
	Type = StaticULong;
	LongVal = val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, bool val){
	col = colIndx;
	row = rowIndx;
	Type = StaticBool;
	BlnVal = val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, bool val, String TrueText, String FalseText){
	col = colIndx;
	row = rowIndx;
	Type = StaticBoolWithText;
	BoolTrueText = TrueText;
	BoolFalseText = FalseText;
	BlnVal = val;
}

//Instantiate - Variables
EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, String *val){
	col = colIndx;
	row = rowIndx;
	Type = VarString;
	StrRef = val;
	StrVal = *val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, float *val){
	col = colIndx;
	row = rowIndx;
	Type = VarFloat;
	FltRef = val;
	FltVal = *val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, double *val){
	col = colIndx;
	row = rowIndx;
	Type = VarDouble;
	DblRef = val;
	DblVal = *val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, float *val, int precision){
	col = colIndx;
	row = rowIndx;
	Type = VarFloat;
	FltRef = val;
	FltVal = *val;
	floatPrecision = precision;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, double *val, int precision){
	col = colIndx;
	row = rowIndx;
	Type = VarDouble;
	DblRef = val;
	DblVal = *val;
	floatPrecision = precision;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, int *val){
	col = colIndx;
	row = rowIndx;
	Type = VarInt;
	IntRef = val;
	IntVal = *val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, unsigned int *val){
	col = colIndx;
	row = rowIndx;
	Type = VarUInt;
	UIntRef = val;
	UIntVal = *val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, long *val){
	col = colIndx;
	row = rowIndx;
	Type = VarLong;
	LongRef = val;
	LongVal = *val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, unsigned long *val){
	col = colIndx;
	row = rowIndx;
	Type = VarULong;
	ULongRef = val;
	ULongVal = *val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, bool *val){
	col = colIndx;
	row = rowIndx;
	Type = VarBool;
	BlnRef = val;
	BlnVal = *val;
}


EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, bool *val, String TrueText, String FalseText){
	col = colIndx;
	row = rowIndx;
	Type = VarBoolWithText;
	BlnRef = val;
	BlnVal = *val;
	BoolTrueText = TrueText;
	BoolFalseText = FalseText;
}

//Instantiate - Toggle Option
EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, EZUI_Control_ToggleOption * TlgOpt){
	col = colIndx;
	row = rowIndx;
	Type = ToggleOption;
	TglOptRef = TglOptRef;
}

//Instantiate - Link
EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx,EZUI_Control_Link * Lnk){
	col = colIndx;
	row = rowIndx;
	Type = Link;
	LnkRef = Lnk;
}

void EZUI_PageItem::print(LiquidCrystal_I2C * LCD, bool refresh){
	LCD->setCursor(col, row);
	switch(Type){
		case None:
			break;
			
		case StaticInt:
			//Serial.println("Printing Static Int");
			//Serial.println(StaticInt);
			LCD->print(IntVal);
			break;
		
		case StaticUInt:
			//Serial.println("Printing Static UInt");
			//Serial.println(UIntVal);
			LCD->print(UIntVal);
			break;
		
		case StaticLong:
			//Serial.println("Printing Static Long");
			//Serial.println(LongVal);
			LCD->print(LongVal);
			break;
		
		case StaticULong:
			//Serial.println("Printing Static ULong");
			//Serial.println(ULongVal);
			LCD->print(ULongVal);
			break;
		
		case StaticFloat:
			//Serial.println("Printing Static Float");
			//Serial.println(FltVal);
			LCD->print(FltVal);
			break;
		
		case StaticDouble:
			//Serial.println("Printing Static Double");
			//Serial.println(DblVal);
			LCD->print(DblVal);
			break;
		
		case StaticBool:
			//Serial.println("Printing Static Bool");
			//Serial.println(BlnVal);
			LCD->print(BlnVal);
			break;
		
		case StaticBoolWithText:
			//Serial.println("Printing Static Bool with Text");
			//Serial.println(BlnVal);
			if(BlnVal == true){
				LCD->print(BoolTrueText);
			}else{
				LCD->print(BoolFalseText);
			}
			break;
		
		case StaticString:
			//Serial.println("Printing Static STring");
			//Serial.println(StrVal);
			LCD->print(StrVal);
			break;
		
		case VarInt:
			//Serial.println("Printing Var Int");
			//Serial.println(*IntRef);
			if((IntVal != *IntRef) || refresh){
				IntVal = *IntRef;
				LCD->print(IntVal);
			}
			break;
		
		case VarUInt:
			//Serial.println("Printing Var UInt");
			//Serial.println(*UIntRef);
			if((UIntVal != *UIntRef) || refresh ){
				UIntVal = *UIntRef;
				LCD->print(UIntVal);
			}
			break;
		
		case VarLong:
			//Serial.println("Printing Var Long");
			//Serial.println(*LongRef);
			if(( LongVal != *LongRef) || refresh ){
				LongVal = *LongRef;
				LCD->print(LongVal);
			}
			break;	
		
		case VarULong:
			//Serial.println("Printing Var ULong");
			//Serial.println(*ULongRef);
			if(( ULongVal != *ULongRef) || refresh ){
				ULongVal = *ULongRef;
				LCD->print(ULongVal);
			}
			break;
			
		case VarFloat:
			//Serial.println("Printing Var Float");
			//Serial.println(*FltRef);
			if((FltVal != *FltRef) || refresh ){
				FltVal = *FltRef;
				LCD->print(FltVal);
			}
			break;
				
		case VarDouble:
			//Serial.println("Printing Var Double");
			//Serial.println(*DblRef);
			if((DblVal != *DblRef) || refresh ){
				DblVal = *DblRef;
				LCD->print(DblVal);
			}
			break;
			
		case VarBool:
			//Serial.println("Printing Var Bool");
			//Serial.println(*BlnRef);
			if((BlnVal != *BlnRef) || refresh){
				BlnVal = *BlnRef;
				LCD->print(BlnVal);
			}
			break; 
			
		case VarBoolWithText:
			//Serial.println("Printing Var Bool With Text");
			//Serial.println(*BlnRef);
			if((BlnVal != *BlnRef) || refresh){
				BlnVal = BlnRef;
				if(BlnVal == true){
					LCD->print(BoolTrueText);
				}else{
					LCD->print(BoolFalseText);	
				}
			}
			break;
			
		case VarString:
			//Serial.println("Printing Var String");
			//Serial.println(*StrRef);
			if((StrVal != *StrRef ) || refresh){
				StrVal = *StrRef;
				LCD->print(StrVal);
			}
			break;
			
		case ToggleOption:
			//Serial.println("Toggle Option");
			//Serial.println(TglOptRef->Label);
			LCD->print(" " + TglOptRef->Label + ":" );
			
			/*String TrueLabel = TglOptRef->TrueLabel();
			int TrueTextLen = TrueLabel.length();
			String FalseLabel = TglOptRef->FalseLabel();
			int FalseTextLen = FalseLabel.length();
			if(TglOptRef->Value()){
				LCD->print(TrueLabel);
			}else{
				LCD->print(FalseLabel);
			}
			break;*/
		
		case Link:
			//Serial.println("Link Option");
			//Serial.println(LnkRef->Label);
			LCD->print(" " + LnkRef->Label);
			break;
	}
}

//Item Select
void EZUI_PageItem::ItemSelect(EZUI *UI){
	switch (Type) {
		case(ToggleOption):
			(*TglOptRef).Toggle();
			UI->display();
			break;
		case(Link):
			//Serial.print("***************************Following Link***************************");
			LnkRef->FollowLink(UI);
			break;
		default:
			UI->LCD->clear();
			UI->LCD->println("ERROR!:");
			UI->LCD->println("Menu Type not yet Supported");
			delay(3000);
			UI->display();
			break;
	}
}