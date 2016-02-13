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
EZUI_Control_Link::EZUI_Control_Link(String Text, EZUI_Menu * MenuLink)
{
	this->Label = Text;
	PageRef = NULL;
	MenuRef = MenuLink;
} //EZUI_Control_Link

// default constructor
EZUI_Control_Link::EZUI_Control_Link(String Text, EZUI_Page * PageLink)
{
	this->Label = Text;
	PageRef = PageLink;
	MenuRef = NULL;
} //EZUI_Control_Link

// default destructor
EZUI_Control_Link::~EZUI_Control_Link()
{
} //~EZUI_Control_Link


void EZUI_Control_Link::FollowLink(EZUI *UI){
	if (!(PageRef == NULL)){
		UI->setDisplay(PageRef);
	}else if (!(MenuRef == NULL)){
		UI->setDisplay(MenuRef);
	}
}