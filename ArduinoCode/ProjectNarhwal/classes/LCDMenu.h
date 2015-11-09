/*
 *        File: LCDMenu.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: LCD Menu
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "../include/LinkedList/LinkedList.h"
#include "../include/LiquidCrystal/LiquidCrystal_I2C.h"
#include "LCDMenuItem.h"

#ifndef __LCDMENU_H__
#define __LCDMENU_H__


class LCDMenu
{
	//variables
	public:
		String Name = "";
		LinkedList<LCDMenuItem> Items = LinkedList<LCDMenuItem>();
		
	protected:
	
	private:
		LCDMenu *Parent;
		int currentItem = 0;
		LCDMenuItem *Back;

	//functions
	public:
		LCDMenu(String Name);
		LCDMenu(String Name, LCDMenu *Parent);
		~LCDMenu();
		void display(LiquidCrystal_I2C *LCD);
		void prevItem();						//Moves cursor to next item (also calls display to refresh the LCD)
		void nextItem();						//Moves cursor to next item (also calls display to refresh the LCD)
		void selectItem(LCDMenuItem MenuItem);	//Moves cursor to next item (also calls display to refresh the LCD)
		
	protected:
	private:
		//LCDMenu( const LCDMenu &c );
		//LCDMenu& operator=( const LCDMenu &c );

}; //LCDMenu

#endif //__LCDMENU_H__
