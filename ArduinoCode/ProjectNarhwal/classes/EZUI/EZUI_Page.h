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

#include "../Hardware.h"
#include "../../include/LinkedList/LinkedList.h"
#include "../../include/LiquidCrystal/LiquidCrystal_I2C.h"
#include "EZUI_Menu.h"
#include "EZUI.h"
#include "./Controls/EZUI_Control_Link.h"
#include "./Controls/EZUI_Control_ToggleOption.h"
#include "./Controls/EZUI_Control_Label.h"

class EZUI_Menu;
class EZUI;
class EZUI_Control_Link;
class EZUI_Control;

struct PageItem
{
	uint8_t col;
	uint8_t row;
	uint8_t fieldWidth;
	const EZUI_Control *Control;
};
	
class EZUI_Page
{
//variables
public:
	unsigned long refreshRate = 500;
			
protected:
private:
	const PageItem *items;
	String *itemsText;
	int itemCount = 0;
	int currentItem = -1;
	boolean itemChanged = true;
	boolean refresh = false;
	unsigned long lastPrint = 0;

//functions
public:
	EZUI_Page() {};
	~EZUI_Page() {};
	
	//Different types of items whih can be added
	void setItems(const PageItem items[], unsigned int size);
	
	//Actions
	void display(EZUI *UI);
	void init(EZUI *UI);
	void cleanup(EZUI *UI);
	void prevItem();				//Moves cursor to next item (also calls display to refresh the LCD)
	void nextItem();				//Moves cursor to next item (also calls display to refresh the LCD)
	void selectItem(EZUI *UI);		//Select the Item, Passes the User interface parent by reference
	
protected:
private:

}; //LCDPage

#endif //__LCDPAGE_H__
