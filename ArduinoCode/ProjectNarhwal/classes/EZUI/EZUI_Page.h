/*
 *        File: EZUI_Page.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Display Page Class
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#ifndef __EZUI_PAGE_H__
#define __EZUI_PAGE_H__

#include "../../include/LinkedList/LinkedList.h"
#include "../../include/LiquidCrystal/LiquidCrystal_I2C.h"
#include "EZUI_PageItem.h"
#include "EZUI_MenuItem.h"
#include "EZUI_Menu.h"
#include "EZUI.h"

class EZUI_Menu;
class EZUI_PageItem;
class EZUI;
class EZUI_Page
{
//variables
public:
	int refreshRate = 1000;	//refresh rate in ms (default 1000ms)
	String Name = "";
	
protected:
private:
	LinkedList<EZUI_PageItem> _Items = LinkedList<EZUI_PageItem>();
	LinkedList<int> SelectableItems = LinkedList<int>();
	EZUI_Page *_ParentPageRef = NULL;
	EZUI_Menu *_ParentMenuRef = NULL;
	unsigned long lastUpdate = 0;
	int currentItem = -1;
	int refresh = 1;

//functions
public:
	EZUI_Page();
	EZUI_Page(String _Name);
	~EZUI_Page();
	
	void addItem(EZUI_PageItem *item);
	void display(EZUI *UI);
	void prevItem();						//Moves cursor to next item (also calls display to refresh the LCD)
	void nextItem();						//Moves cursor to next item (also calls display to refresh the LCD)
	void selectItem(EZUI *UI);		//Select the Item, Passes the User interface parent by reference
	
protected:
private:

}; //LCDPage

#endif //__LCDPAGE_H__
