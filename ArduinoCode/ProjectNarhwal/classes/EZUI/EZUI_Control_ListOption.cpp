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
String EZUI_Control_ListOption::LabelText(void) { return String(this->_Label); };
String EZUI_Control_ListOption::ValueText(void) { return _Ref->itemText(_Ref->currentItem()); };
void EZUI_Control_ListOption::Select(EZUI *UI) const {
	UI->EditListOption(_Ref);
};

