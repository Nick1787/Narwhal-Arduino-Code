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
	type = MenuLink;
	LinkRef = Lnk;
} //EZUI_Control_Link

// default constructor
EZUI_Control_Link::EZUI_Control_Link(String Text, EZUI_Page * Lnk)
{
	this->Label = Text;
	type = PageLink;
	LinkRef = Lnk;
} //EZUI_Control_Link

// default destructor
EZUI_Control_Link::~EZUI_Control_Link()
{
} //~EZUI_Control_Link


void EZUI_Control_Link::FollowLink(EZUI *UI){
	if (type == MenuLink){
		UI->setDisplay((EZUI_Menu*)LinkRef);
	}else if ( type == PageLink){
		UI->setDisplay((EZUI_Page*)LinkRef);
	}
}