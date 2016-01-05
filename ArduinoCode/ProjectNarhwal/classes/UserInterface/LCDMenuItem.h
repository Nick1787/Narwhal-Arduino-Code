/* 
* LCDMenuItem.h
*
* Created: 11/8/2015 11:05:01 AM
* Author: Customer
*/

#ifndef __LCDMENUITEM_H__
#define __LCDMENUITEM_H__

#include "../../include/LinkedList/LinkedList.h"
#include "../../include/LiquidCrystal/LiquidCrystal_I2C.h"
#include "LCDPage.h"
#include "LCDMenu.h"
#include "LCDToggleOption.h"
#include "UserInterface.h"
#include <string.h>

class LCDMenu;
class LCDToggleOption;
class UserInterface;
class LCDMenuItem
{
//variables
public:
	String Name = "";
	enum MenuItemType { SubPage, SubMenu, ToggleOption, None};
	MenuItemType Type = None;
	
protected:

private:
	LCDPage * PageRef = NULL;
	LCDMenu * MenuRef = NULL;
	LCDToggleOption * ToggleOptRef = NULL;

//functions
public:
	LCDMenuItem(String Name);
	LCDMenuItem(String Name, LCDMenu * Menu);
	LCDMenuItem(String Name, LCDPage * Page);
	LCDMenuItem(String Name, LCDToggleOption * ToggleOpt);
	LCDMenuItem();
	~LCDMenuItem();
	void Print(int col, int rw, UserInterface *UI);		//Prints Menu Item to Screen
	void ItemSelect(UserInterface *UI);						//Prints Menu Item to Screen
	
	//LCDMenuItem( const LCDMenuItem &c );
	//LCDMenuItem& operator=( const LCDMenuItem &c );

protected:
	
private:

}; //LCDMenuItem

#endif //__LCDMENUITEM_H__
