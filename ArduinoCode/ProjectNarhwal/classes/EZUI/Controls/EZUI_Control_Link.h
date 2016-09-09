/*
 *        File: EZUI_Control_Link.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - Link Control
 *			- Links can be created to other pages or menus
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#ifndef __EZUI_CONTROL_LINK_H__
#define __EZUI_CONTROL_LINK_H__

//Includes
#include "EZUI_Control.h"
#include "../EZUI.h"

//Forward Declarations
class EZUI;
class EZUI_Page;
class EZUI_Menu;
class DigitalIO;

class EZUI_Control_Link : public EZUI_Control
{
//variables
public:
	using EZUI_Control::Type;
	String Label = "";
	
protected:
private:
	enum LinkType{MenuLink, PageLink};
	LinkType Link = MenuLink;
	void *LinkRef = NULL;

//functions
public:
	//Over-ridden base class functions
	String Text(void) const  override;
	boolean isSelectable() const  override {return true;};
	void Select(EZUI *UI) const override;
	
	//void FollowLink(EZUI *UI) const;
	EZUI_Control_Link(String Text, EZUI_Menu * MenuLink);
	EZUI_Control_Link(String Text, EZUI_Page * PageLink);
	~EZUI_Control_Link() override {};
	
protected:
private:
	//EZUI_Control_Link( const EZUI_Control_Link &c );
	//EZUI_Control_Link& operator=( const EZUI_Control_Link &c );

}; //EZUI_Control_Link

#endif //__EZUI_CONTROL_LINK_H__
