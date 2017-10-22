/*
 *        File: EZUI_Control_Label.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - Label Control
 *			- Labels are test displays which users cannot interact with
 */

#include "EZUI.h"
#include "EZUI_Control_Label.h"

/****************************************************************************
	Over-ride Functions
*****************************************************************************/

boolean  EZUI_Control_Label::isSelectable() const { return false; };
boolean  EZUI_Control_Label::hasValueText() const { return true; };
void  EZUI_Control_Label::Select(EZUI *UI) const { /* Do nothing */ };
const char* EZUI_Control_Label::LabelText(void) { 
	if(_isFlash){
		String ret = (__FlashStringHelper*)_Label;
		ret.toCharArray(strbuffer, str_buffer_size);
		return (strbuffer);
	}else{
		return ((const char*)_Label);
	}
 };
const char* EZUI_Control_Label::ValueText(){
	String Str = "";
	switch(this->_Label_Type){
		case(LblCharArr):{
			if(_isFlash){
				Str = (__FlashStringHelper*)this->_ItemRef;
				break;
			}else{
				return (char*)this->_ItemRef;
			}
		}
		case(LblCCharArr):{
			
			if(_isFlash){
				Str = (__FlashStringHelper*)this->_ItemRef;
				break;
			}else{
				return (const char*)this->_ItemRef;
			}
		}
		case(LblFloat):{
			Str = String(*(float*)(this->_ItemRef));
			break;
		}
		case(LblDouble):{
			Str = String(*(double*)(this->_ItemRef));
			break;
		}
		case(LblInt):{
			Str = String(*(int*)(this->_ItemRef));
			break;
		}
		case(LblUInt):{
			Str = String(*(unsigned int*)(this->_ItemRef));
			break;
		}
		case(LblLong):{
			Str = String(*(long*)(this->_ItemRef));
			break;
		}
		case(LblULong):{
			Str = String(*(unsigned long*)(this->_ItemRef));
			break;
		}
		case(LblBoolWithText):{
			boolean val = *(bool*)(this->_ItemRef);
			if(val){
				if(_isFlash){
					Str = (__FlashStringHelper*)_blnTrueTxt;
					break;
				}else{
					return (const char*)_blnTrueTxt;
				}
			}else{
				if(_isFlash){
					Str = (__FlashStringHelper*)_blnFalseTxt;
					break;
				}else{
					return  (const char*)_blnFalseTxt;
				}
			}
		}
		case(LblDigitalIO):{
			DigitalIO val = *(DigitalIO*)(this->_ItemRef);
			if( val.Value() ){
				return val.TrueLabel();
			}else{
				return val.FalseLabel();
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
			Str = String(aObj.value);
			break;
		}
		case(LblStr):{
			Str = *(String*)(this->_ItemRef);
			String * Ref = (String*)(this->_ItemRef);

			Ref->toCharArray(strbuffer, str_buffer_size);
			return (strbuffer);
			break;
		}
}
Str.toCharArray(strbuffer, str_buffer_size);
return (strbuffer);
};

