/*
 *        File: EZUI_Control_Label.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - Label Control
 *			- Labels are test displays which users cannot interact with
 */


#include "EZUI_Control_Label.h"

/****************************************************************************
	Over-ride Functions
*****************************************************************************/

boolean  EZUI_Control_Label::isSelectable() const { return false; };
boolean  EZUI_Control_Label::hasValueText() const { return false; };
void  EZUI_Control_Label::Select(EZUI *UI) const { /* Do nothing */ };
String EZUI_Control_Label::LabelText(){
	String Str = "";
	switch(this->_Label_Type){
		case(LblCharArr):
		Str = String((char*)this->_ItemRef);
		break;
		case(LblCCharArr):
		Str = String((char*)this->_ItemRef);
		break;
		case(LblFloat):
		Str = String(*(float*)(this->_ItemRef));
		break;
		case(LblDouble):
		Str = String(*(double*)(this->_ItemRef));
		break;
		case(LblInt):
		Str = String(*(int*)(this->_ItemRef));
		break;
		case(LblUInt):
		Str = String(*(unsigned int*)(this->_ItemRef));
		break;
		case(LblLong):
		Str = String(*(long*)(this->_ItemRef));
		break;
		case(LblULong):
		Str = String(*(unsigned long*)(this->_ItemRef));
		break;
		case(LblBoolWithText):{
			boolean val = *(bool*)(this->_ItemRef);
			if(val){
				Str = _blnTrueTxt;
				}else{
				Str = _blnFalseTxt;
			}
			break;
		}
		case(LblDigitalIO):{
			DigitalIO val = *(DigitalIO*)(this->_ItemRef);
			if( val.Value() ){
				Str= val.TrueLabel;
			}else{
				Str = val.FalseLabel;
			}
			break;
		}
		case(LblListOpt):{
			GenericListOption *lObj = (GenericListOption*)(this->_ItemRef);
			Str = lObj->itemText(lObj->currentItem());
			break;
		}
		case(LblAdjParam):{
			AdjustableParam aObj = *(AdjustableParam*)(this->_ItemRef);
			Str = aObj.valueText();
			break;
		}
	}
	return Str;
};

