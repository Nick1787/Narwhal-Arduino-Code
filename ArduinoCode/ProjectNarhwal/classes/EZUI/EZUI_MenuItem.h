/*
 *        File: EZUI_MenuItem.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Menu Item Class
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#ifndef __EZUI_MENUITEM_H__
#define __EZUI_MENUITEM_H__

#include "../../include/LinkedList/LinkedList.h"
#include "../../include/LiquidCrystal/LiquidCrystal_I2C.h"

#include "EZUI.h"
#include "EZUI_Page.h"
#include "EZUI_Menu.h"
#include "./Controls/EZUI_Control_ToggleOption.h"
#include "./Controls/EZUI_Control_Link.h"
#include <string.h>

class EZUI;
class EZUI_Menu;
class EZUI_Page;
class EZUI_Control_Link;
class EZUI_Control_ToggleOption;
class EZUI_MenuItem
{
//variables
public:
	enum MenuItemType { None, LinkControl, ToggleOptionControl};
	MenuItemType Type = None;
	
protected:

private:
	EZUI_Control_Link * LinkRef = NULL;
	EZUI_Control_ToggleOption * ToggleOptRef = NULL;

//functions
public:
	EZUI_MenuItem(EZUI_Control_Link * Link);
	EZUI_MenuItem(EZUI_Control_ToggleOption * ToggleOption);
	EZUI_MenuItem();
	~EZUI_MenuItem();
	void Print(int col, int rw, EZUI *UI);			//Prints Menu Item to Screen
	void ItemSelect(EZUI *UI);						//Prints Menu Item to Screen

protected:
	
private:

}; //LCDMenuItem

#endif //__LCDMENUITEM_H__
