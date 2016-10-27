/* 
* EZUI_Control_ListOption.cpp
*
* Created: 1/10/2016 9:31:32 AM
* Author: Customer
*/


#include "EZUI_Control_ListOption.h"

//Destructor

EZUI_Control_ListOption::~EZUI_Control_ListOption(){};
	
boolean EZUI_Control_ListOption::isSelectable() const { return true; };
boolean EZUI_Control_ListOption::hasValueText() const { return false; };
String EZUI_Control_ListOption::LabelText(void) { return String(this->_Label); };
String EZUI_Control_ListOption::ValueText(void) { return _Ref->itemText(_Ref->currentItem()); };
void EZUI_Control_ListOption::Select(EZUI *UI) const {
	UI->EditListOption(_Ref);
};

