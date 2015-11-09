/*
 *        File: LCDMenu.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: LCD Menu
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "../include/LiquidCrystal/LiquidCrystal_I2C.h"
#include "LCDMenu.h"

// Top Level Menu (No Parent)
LCDMenu::LCDMenu(String _Name)
{
	Name = _Name;
	Parent = NULL;
	
	//Create the Back Option
	String BackName = "Exit";
	Back = new LCDMenuItem(BackName);
}

// Sub Menu With Parent
LCDMenu::LCDMenu(String _Name, LCDMenu *_Parent)
{
	Name = _Name;
	Parent = _Parent;
	
	//Create the Back Option
	String BackName = "Back";
	Back = new LCDMenuItem(BackName);
}


// default destructor
LCDMenu::~LCDMenu()
{
}

void LCDMenu::display(LiquidCrystal_I2C *LCD){
	//Print the Menu Header
	
	Serial.println("Here");
	Serial.println((unsigned)LCD);
	LCD->setCursor(0,0);
	Serial.println("Here");
	LCD->print(">>-");
	Serial.println("Here");
	LCD->moveCursorRight();
	LCD->moveCursorRight();
	LCD->moveCursorRight();
	LCD->print(Name);
	for(int i=0; i<Name.length(); i++){
		LCD->moveCursorRight();
	}
	
	Serial.println("Here");
	for(int i=0; i<(20 - Name.length() - 6); i++){
		LCD->print("-");
		LCD->moveCursorRight();
	}
	LCD->print("-<<");
	
	Serial.println("Here2");
	Serial.println(Items.size());
	//Print each menu item (3 items left on line)
	int firstItemToPrint = (int)(currentItem/3);
	int ln = 1;
	
	Serial.println(firstItemToPrint);
	for(int i=firstItemToPrint; i<min(Items.size(),firstItemToPrint + 3); i++){
		if (i == currentItem){
			LCD->setCursor(ln,0);
			LCD->print(">");
		}
		LCD->setCursor(ln,1);
		
		//Serial.println("Here3");
		LCD->print(Items.get(i).Name);
	}
	
	Serial.println("Here4");
}

void LCDMenu::prevItem(void){
	currentItem--;
	if (currentItem < 0){ 
		currentItem = 0;
	}
}

void LCDMenu::nextItem(void){
	currentItem++;
	if (currentItem > Items.size()){
		currentItem = Items.size();
	}
}

void LCDMenu::selectItem(LCDMenuItem Item){
	currentItem = currentItem;
}