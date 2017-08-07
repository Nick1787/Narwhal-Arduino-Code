/*
 *        File: EZUI_Control_Link.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - Link Control
 *			- Links can be created to other pages or menus
 */

#include "EZUI_Control_Link.h"
#include "EZUI.h"

boolean EZUI_Control_Link::isSelectable() const {return true;};
boolean EZUI_Control_Link::hasValueText() const { return false;};
const char* EZUI_Control_Link::LabelText(void) { 
	
	if(isFlash){
		String ret = (__FlashStringHelper*)_Label;
		ret.toCharArray(strbuffer, str_buffer_size);
		return (strbuffer);
	}else{
		return ((const char*)_Label);
	}
};
const char* EZUI_Control_Link::ValueText(void) {
	return "";
};
void EZUI_Control_Link::Select(EZUI *UI) const {
	UI->setUI(_LinkRef);
};
