/*
 *        File: EZUI_Control_AdjustParam.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - Adjustable Param
 *			- Control for interacting with an adjustable parameter
 */

#include "EZUI_Control_AdjustParam.h"
#include "EZUI.h"

EZUI_Control_AdjustParam::~EZUI_Control_AdjustParam(){};

boolean EZUI_Control_AdjustParam::isSelectable() const { return true; };
boolean EZUI_Control_AdjustParam::hasValueText() const { return true; };
const char* EZUI_Control_AdjustParam::LabelText(void) { 
	
	if(isFlash){
		String ret = (__FlashStringHelper*)_Label;
		ret.toCharArray(strbuffer, str_buffer_size);
		return (strbuffer);
	}else{
		return ((const char*)_Label);
	}
	
};

const char* EZUI_Control_AdjustParam::ValueText(void) { 	
	String ret = String(_Ref->value);
	ret.toCharArray(strbuffer, str_buffer_size);
	return (strbuffer);
};

void EZUI_Control_AdjustParam::Select(EZUI *UI) const {
	UI->EditAdjustParam(_Ref);
};

