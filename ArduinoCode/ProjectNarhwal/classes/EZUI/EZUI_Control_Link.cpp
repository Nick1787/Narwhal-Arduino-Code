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
String EZUI_Control_Link::LabelText(void) { return String(this->_Label); };
void EZUI_Control_Link::Select(EZUI *UI) const {
	Serial.print("SelectLinRef:");
	Serial.println((unsigned int)_LinkRef);
	Serial.flush();
	UI->setDisplay(_LinkRef);
};
