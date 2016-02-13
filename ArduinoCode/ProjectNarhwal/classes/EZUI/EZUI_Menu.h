/*
 *        File: EZUI_MENU.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Menu Class
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#ifndef __EZUI_MENU_H__
#define __EZUI_MENU_H__

#include "../../include/LinkedList/LinkedList.h"
#include "../../include/LiquidCrystal/LiquidCrystal_I2C.h"
#include "EZUI.h"
#include "EZUI_MenuItem.h"
#include "EZUI_Page.h"
#include "./Controls/EZUI_Control_Link.h"
#include "./Controls/EZUI_Control_ToggleOption.h"

class EZUI;
class EZUI_Page;
class EZUI_MenuItem;
class EZUI_Control_Link;
class EZUI_Menu
{
	//variables
	public:
		String Name = "";
		
	protected:
	
	private:
		LinkedList<EZUI_MenuItem> _Items = LinkedList<EZUI_MenuItem>();
		EZUI_Menu *ParentMenu = NULL;
		EZUI_Page *ParentPage = NULL;
		EZUI_MenuItem *Back = NULL;
		int currentItem = 0;
		int refresh = 1;

	//functions
	public:
		EZUI_Menu(String MenuName);
		~EZUI_Menu();
		void display(EZUI *UI);
		void prevItem();						//Moves cursor to next item (also calls display to refresh the LCD)
		void nextItem();						//Moves cursor to next item (also calls display to refresh the LCD)
		void selectItem(EZUI *UI);		//Select the Item, Passes the User interface parent by reference
		
		//Different types of items which can be added
		void addItem(EZUI_Control_Link * LinkRef);
		void addItem(EZUI_Control_ToggleOption * ToggleOptRef);
		
	protected:
	private:
		//LCDMenu( const LCDMenu &c );
		//LCDMenu& operator=( const LCDMenu &c );

}; //LCDMenu

#endif //__LCDMENU_H__
