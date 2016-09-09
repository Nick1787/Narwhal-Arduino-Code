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

// default constructor
EZUI_Control_Link::EZUI_Control_Link(String Text, EZUI_Menu * Lnk)
{
	this->Label = Text;
	Type = EZUI_Control::Link;
	Link = MenuLink;
	LinkRef = Lnk;
} //EZUI_Control_Link

// default constructor
EZUI_Control_Link::EZUI_Control_Link(String Text, EZUI_Page * Lnk)
{
	this->Label = Text;
	Type = EZUI_Control::Link;
	Link = PageLink;
	LinkRef = Lnk;
} //EZUI_Control_Link


String EZUI_Control_Link::Text(void) const{
	return this->Label;
}

void EZUI_Control_Link::Select(EZUI *UI) const{
	if (Link == MenuLink){
		UI->setDisplay((EZUI_Menu*)LinkRef);
	}else if ( Link == PageLink){
		UI->setDisplay((EZUI_Page*)LinkRef);
	}
}