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
	String *valCpy = new String();
	*valCpy = val;
	valRef = &valCpy;
	isStatic = true;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, float val){
	col = colIndx;
	row = rowIndx;
	Type = StaticFloat;
	float *valCpy = new float;
	*valCpy = val;
	valRef = &valCpy;
	isStatic = true;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, double val){
	col = colIndx;
	row = rowIndx;
	Type = StaticDouble;
	double *valCpy = new double;
	*valCpy = val;
	valRef = &valCpy;
	isStatic = true;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, int val){	
	col = colIndx;
	row = rowIndx;
	Type = StaticInt;
	int *valCpy = new int;
	*valCpy = val;
	valRef = &valCpy;
	isStatic = true;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, unsigned int val){	
	col = colIndx;
	row = rowIndx;
	Type = StaticUInt;
	float valCpy = val;
	valRef = &valCpy;
	isStatic = true;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, long val){
	col = colIndx;
	row = rowIndx;
	Type = StaticLong;
	long * valCpy = new long;
	*valCpy = val;
	valRef = &valCpy;
	isStatic = true;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, unsigned long val){
	col = colIndx;
	row = rowIndx;
	Type = StaticULong;
	unsigned long * valCpy = new unsigned long;
	*valCpy = val;
	valRef = &valCpy;
	isStatic = true;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, bool val){
	col = colIndx;
	row = rowIndx;
	Type = StaticBool;
	bool * valCpy = new bool;
	*valCpy = val;
	valRef = &valCpy;
	isStatic = true;
}

//Instantiate - Variables
EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, String *val){
	col = colIndx;
	row = rowIndx;
	Type = VarString;
	valRef = val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, float *val){
	col = colIndx;
	row = rowIndx;
	Type = VarFloat;
	valRef = val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, double *val){
	col = colIndx;
	row = rowIndx;
	Type = VarDouble;
	valRef = val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, int *val){
	col = colIndx;
	row = rowIndx;
	Type = VarInt;
	valRef = val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, unsigned int *val){
	col = colIndx;
	row = rowIndx;
	Type = VarUInt;
	valRef = val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, long *val){
	col = colIndx;
	row = rowIndx;
	Type = VarLong;
	valRef = val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, unsigned long *val){
	col = colIndx;
	row = rowIndx;
	Type = VarULong;
	valRef = val;
}

EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, bool *val){
	col = colIndx;
	row = rowIndx;
	Type = VarBool;
	valRef = val;
}


//Instantiate - Toggle Option
EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx, EZUI_Control_ToggleOption * val){
	col = colIndx;
	row = rowIndx;
	Type = ToggleOption;
	valRef = val;
}

//Instantiate - Link
EZUI_PageItem::EZUI_PageItem(uint8_t colIndx, uint8_t rowIndx,EZUI_Control_Link * val){
	col = colIndx;
	row = rowIndx;
	Type = Link;
	valRef = val;
}

void EZUI_PageItem::print(LiquidCrystal_I2C * LCD, bool refresh){
	LCD->setCursor(col, row);
	switch(Type){
		case None:
			break;
			
		case StaticInt:
		{
			//Serial.println("Printing Static Int");
			//Serial.println(StaticInt);
			LCD->print(*(int*)valRef);
		}
		break;
		
		case StaticUInt:
		{
			//Serial.println("Printing Static UInt");
			//Serial.println(UIntVal);
			LCD->print(*(unsigned int*)valRef);
		}
		break;
		
		case StaticLong:
		{
			//Serial.println("Printing Static Long");
			//Serial.println(LongVal);
			LCD->print(*(long*)valRef);
		}
		break;
		
		case StaticULong:
		{
			//Serial.println("Printing Static ULong");
			//Serial.println(ULongVal);
			LCD->print(*(unsigned long*)valRef);
		}
		break;
		
		case StaticFloat:
		{
			//Serial.println("Printing Static Float");
			//Serial.println(FltVal);
			LCD->print(*(float*)valRef);
		}
		break;
		
		case StaticDouble:
		{
			//Serial.println("Printing Static Double");
			//Serial.println(DblVal);
			LCD->print(*(double*)valRef);
		}
		break;
		
		case StaticBool:
		{
			//Serial.println("Printing Static Bool");
			//Serial.println(BlnVal);
			LCD->print(*(boolean*)valRef);
		}
		break;
		
		case StaticBoolWithText:
		{
			//Serial.println("Printing Static Bool with Text");
			//Serial.println(BlnVal);
			LCD->print(*(boolean*)valRef);
		}
		break;
		
		case StaticString:
		{
			//Serial.println("Printing Static STring");
			//Serial.println(StrVal);
			LCD->print(*(String*)valRef);
		}
		break;
		
		case VarInt:
		{
			//Serial.println("Printing Var Int");
			//Serial.println(*IntRef);
			LCD->print(*(int*)valRef);
		}
		break;
		
		case VarUInt:
		{
			//Serial.println("Printing Var UInt");
			//Serial.println(*UIntRef);
			LCD->print(*(unsigned int*)valRef);
		}
		break;
		
		case VarLong:
		{
			//Serial.println("Printing Var Long");
			//Serial.println(*LongRef);
			LCD->print(*(long*)valRef);
		}
		break;	
		
		case VarULong:
		{
			//Serial.println("Printing Var ULong");
			//Serial.println(*ULongRef);
			LCD->print(*(unsigned long*)valRef);
		}
		break;
			
		case VarFloat:
		{
			//Serial.println("Printing Var Float");
			//Serial.println(*FltRef);
			LCD->print(*(float*)valRef);
		}
		break;
				
		case VarDouble:
		{
			//Serial.println("Printing Var Double");
			//Serial.println(*DblRef);
			LCD->print(*(double*)valRef);
		}
		break;
			
		case VarBool:
		{
			//Serial.println("Printing Var Bool");
			//Serial.println(*BlnRef);
			LCD->print(*(boolean*)valRef);
		}
		break; 
			
		case VarBoolWithText:
		{
			//Serial.println("Printing Var Bool With Text");
			//Serial.println(*BlnRef);
			LCD->print(*(boolean*)valRef);
		}
		break;
			
		case VarString:
		{
			//Serial.println("Printing Var String");
			//Serial.println(*StrRef);
			LCD->print(*(String*)valRef);
		}
		break;
			
		case ToggleOption:
		{
			//Serial.println("Toggle Option");
			//Serial.println(TglOptRef->Label);
			EZUI_Control_ToggleOption * TglOpt;
			TglOpt = (EZUI_Control_ToggleOption*)valRef;
			LCD->print(" " + TglOpt->Label + ":" );
			
			String TrueLabel = TglOpt->TrueLabel();
			int TrueTextLen = TrueLabel.length();
			String FalseLabel = TglOpt->FalseLabel();
			int FalseTextLen = FalseLabel.length();
			if(TglOpt->Value()){
				LCD->print(TrueLabel);
			}else{
				LCD->print(FalseLabel);
			}
		}
		break;
	
		case Link:
		{
			//Serial.println("Link Option");
			//Serial.println(LnkRef->Label);
			EZUI_Control_Link *LnkOpt;
			LnkOpt = (EZUI_Control_Link*)valRef;
			LCD->print(" " + LnkOpt->Label);
		}
		break;
	}
}

//Item Select
void EZUI_PageItem::ItemSelect(EZUI *UI){
	switch (Type) {
		case(ToggleOption):
			EZUI_Control_ToggleOption * TglOpt;
			TglOpt = (EZUI_Control_ToggleOption *)valRef;
			TglOpt->Toggle();
			UI->display();
			break;
		case(Link):
			//Serial.print("***************************Following Link***************************");
			EZUI_Control_Link * LnkOpt;
			LnkOpt = (EZUI_Control_Link*)valRef;
			LnkOpt->FollowLink(UI);
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