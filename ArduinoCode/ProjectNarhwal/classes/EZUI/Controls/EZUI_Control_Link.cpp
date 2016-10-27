/*
 *        File: EZUI_Control_Link.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - Link Control
 *			- Links can be created to other pages or menus
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */


#include "EZUI_Control_Link.h"

boolean EZUI_Control_Link::isSelectable() const {return true;};
boolean EZUI_Control_Link::hasValueText() const { return false;};
String EZUI_Control_Link::LabelText(void) { return String(this->_Label); };
void EZUI_Control_Link::Select(EZUI *UI) const {
	UI->setDisplay(_LinkRef);
};
