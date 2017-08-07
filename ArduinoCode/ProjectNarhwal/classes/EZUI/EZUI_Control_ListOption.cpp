/*
 *        File: EZUI_Control_ListOption.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - List Option
 *			- Control for interacting with a list option
 */

#include "EZUI_Control_ListOption.h"
#include "EZUI.h"

//Destructor

EZUI_Control_ListOption::~EZUI_Control_ListOption(){};
	
boolean EZUI_Control_ListOption::isSelectable() const { return true; };
boolean EZUI_Control_ListOption::hasValueText() const { return true; };
const char* EZUI_Control_ListOption::LabelText(void) { 
	if(isFlash){
		String ret = (__FlashStringHelper*)_Label;
		ret.toCharArray(strbuffer, str_buffer_size);
		return (strbuffer);
		}else{
		return ((const char*)_Label);
	}
};
const char* EZUI_Control_ListOption::ValueText(void) { 
	String ret = (__FlashStringHelper*)_Ref->itemText(_Ref->currentItem());
	ret.toCharArray(strbuffer, str_buffer_size);
	return (strbuffer);
};
void EZUI_Control_ListOption::Select(EZUI *UI) const {
	UI->EditListOption(_Ref);
};

