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

#include "EZUI.h"

struct MenuItem
{
	const EZUI_Control *Control;
};

class EZUI_Control_ToggleOption;
class EZUI_Menu
{
	//variables
	public:		
	protected:
	private:
		//Menu Items
		const MenuItem * items;
		unsigned int itemCount = 0;
		int currentItem = -1;
		
		//Keep track when to re-draw the page
		boolean itemChanged = false;
		boolean refresh = false;

	//functions
	public:
		//Default constructor and Destructor
		EZUI_Menu() { };
		~EZUI_Menu() {};
		
		//Different types of items which can be added
		void setItems(const MenuItem items[], unsigned int size);
		
		//Actions
		void display(EZUI *UI);			//Default display function
		void init(EZUI *UI);			//Initialization routines
		void cleanup(EZUI *UI);			//Cleanup when leaving this menu
		void prevItem();				//Moves cursor to next item (also calls display to refresh the LCD)
		void nextItem();				//Moves cursor to next item (also calls display to refresh the LCD)
		void selectItem(EZUI *UI);		//Select the Item, Passes the User interface parent by reference
		
	protected:
	private:
		void selectItem(EZUI *UI, EZUI_Control_ToggleOption const * ToggleOptRef);
		void selectItem(EZUI *UI, EZUI_Control_Link const * LinkOptRef);
		void printItem(int col, int row, LiquidCrystal_I2C * LCD, EZUI_Control_Link const *LinkRef);
		void printItem(int col, int row, LiquidCrystal_I2C * LCD, EZUI_Control_ToggleOption const *LinkRef);
		void printPage(EZUI *UI);
		//EZUI_Menu( const EZUI_Menu &c ) {};
		//EZUI_Menu& operator=( const EZUI_Menu &c ) {};

}; //LCDMenu


#endif //__LCDMENU_H__
