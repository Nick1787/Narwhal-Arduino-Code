/*
 *        File: EZUI_Control.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - Control Base Class
 */


#include "EZUI_Control.h"

boolean EZUI_Control::isSelectable()  const { 
	return false;
};
boolean EZUI_Control::hasValueText()  const {
	 return false; 
};
void EZUI_Control::Select(EZUI *UI) const {
	/* Do nothing */
};
String EZUI_Control::LabelText()  { 
	return "LabelText!"; 
};
String EZUI_Control::ValueText()  { 
	return "ValueText!"; 
};
		
// default destructor
EZUI_Control::~EZUI_Control()
{
} //~EZUI_Control

