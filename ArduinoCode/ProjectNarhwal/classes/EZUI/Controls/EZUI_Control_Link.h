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

#include "../EZUI.h"
#include "../EZUI_Menu.h"
#include "../EZUI_Page.h"

class EZUI;
class EZUI_Page;
class EZUI_Menu;
class EZUI_Control_Link
{
//variables
public:
	String Label = "";
	
protected:
private:
	EZUI_Menu * MenuRef = NULL;
	EZUI_Page * PageRef = NULL;

//functions
public:
	void FollowLink(EZUI *UI);
	EZUI_Control_Link(String Text, EZUI_Menu * MenuLink);
	EZUI_Control_Link(String Text, EZUI_Page * PageLink);
	~EZUI_Control_Link();
	
protected:
private:
	EZUI_Control_Link( const EZUI_Control_Link &c );
	EZUI_Control_Link& operator=( const EZUI_Control_Link &c );

}; //EZUI_Control_Link

#endif //__EZUI_CONTROL_LINK_H__
