/*
 *        File: LCDMenu.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: LCD Menu
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#ifndef __LCDMENU_H__
#define __LCDMENU_H__

#include "../../include/LinkedList/LinkedList.h"
#include "../../include/LiquidCrystal/LiquidCrystal_I2C.h"
#include "UserInterface.h"
#include "LCDMenuItem.h"
#include "LCDPage.h"

class LCDMenuItem;
class LCDPage;
class UserInterface;
class LCDMenu
{
	//variables
	public:
		String Name = "";
		LinkedList<LCDMenuItem> Items = LinkedList<LCDMenuItem>();
		
	protected:
	
	private:
		LCDMenu *ParentMenu = NULL;
		LCDPage *ParentPage = NULL;
		LCDMenuItem *Back = NULL;
		int currentItem = 0;
		int refresh = 1;

	//functions
	public:
		LCDMenu(String Name);
		LCDMenu(String Name, LCDMenu *ParentMenu);
		LCDMenu(String Name, LCDPage *ParentPage);
		~LCDMenu();
		void display(UserInterface *UI);
		void prevItem();						//Moves cursor to next item (also calls display to refresh the LCD)
		void nextItem();						//Moves cursor to next item (also calls display to refresh the LCD)
		void selectItem(UserInterface *UI);		//Select the Item, Passes the User interface parent by reference
		
	protected:
	private:
		//LCDMenu( const LCDMenu &c );
		//LCDMenu& operator=( const LCDMenu &c );

}; //LCDMenu

#endif //__LCDMENU_H__
