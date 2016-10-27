/* 
* EZUI_Control.cpp
*
* Created: 5/20/2016 6:24:34 PM
* Author: Customer
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

