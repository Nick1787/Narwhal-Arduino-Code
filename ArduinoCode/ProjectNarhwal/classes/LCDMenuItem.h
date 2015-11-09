/* 
* LCDMenuItem.h
*
* Created: 11/8/2015 11:05:01 AM
* Author: Customer
*/

#include "../include/LinkedList/LinkedList.h"

#ifndef __LCDMENUITEM_H__
#define __LCDMENUITEM_H__

class LCDMenuItem
{
//variables
public:
	String Name = "";
	
protected:

private:
	enum MenuItemType { SubMenu, ToggleOption };
	MenuItemType Type = ToggleOption;

//functions
public:
	LCDMenuItem();
	LCDMenuItem(String Name);
	~LCDMenuItem();
	void LCDprint(LiquidCrystal_I2C * LCD);			//Prints Menu Item to Screen
	
	//LCDMenuItem( const LCDMenuItem &c );
	//LCDMenuItem& operator=( const LCDMenuItem &c );

protected:
	
private:

}; //LCDMenuItem

#endif //__LCDMENUITEM_H__
