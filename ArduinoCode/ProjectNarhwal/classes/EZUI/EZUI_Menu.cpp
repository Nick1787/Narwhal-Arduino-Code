/*
 *        File: LCDMenu.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: LCD Menu
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "EZUI_Menu.h"

// Top Level Menu (No Parent)
EZUI_Menu::EZUI_Menu(String _Name)
{
	this->Name = _Name;
}

// default destructor
EZUI_Menu::~EZUI_Menu()
{
}

void EZUI_Menu::addItem(EZUI_Control_Link * Link){
	EZUI_MenuItem MenuItem = EZUI_MenuItem(Link);
	this->_Items.add(MenuItem);
}

void EZUI_Menu::addItem(EZUI_Control_ToggleOption * ToggleOpt){
	EZUI_MenuItem MenuItem = EZUI_MenuItem(ToggleOpt);
	this->_Items.add(MenuItem);
}

void EZUI_Menu::display(EZUI *UI){
	LiquidCrystal_I2C *LCD = UI->LCD;
	if (refresh==1){
		//Print the Menu Header
		LCD->clear();
		LCD->setCursor(0,0);
		LCD->print("=");
		LCD->print(Name);
	
		for(int i=0; i<(20 - Name.length() - 1); i++){
			LCD->print("=");
		}
	
		//Print each menu item (3 items left on line)
		int firstItemToPrint = (int)(currentItem/3);
		int ln = 1;
		for(int i=firstItemToPrint; i<min(_Items.size(),firstItemToPrint + 3); i++){
			LCD->setCursor(0,ln);
			if (i == currentItem){
				LCD->print(">");
			}else{
				LCD->print(" ");
			}
			_Items.get(i).Print(1,ln,UI);
			ln++;
		}
		refresh = 0;
	}
}

void EZUI_Menu::prevItem(void){
	currentItem--;
	if (currentItem < 0){ 
		currentItem = 0;
	}
	Serial.print(Name);
	Serial.print(" - Encoder Item: ");
	Serial.println(currentItem);
	refresh = 1;
}

void EZUI_Menu::nextItem(void){
	currentItem++;
	if (currentItem >= _Items.size()){
		currentItem = _Items.size()-1;
	}
	Serial.print(Name);
	Serial.print(" - Encoder Item: ");
	Serial.println(currentItem);
	refresh = 1;
}

void EZUI_Menu::selectItem(EZUI *UI){
	_Items.get(currentItem).ItemSelect(UI);
	refresh = 1;
}
