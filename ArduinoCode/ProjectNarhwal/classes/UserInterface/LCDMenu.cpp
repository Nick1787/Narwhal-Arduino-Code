/*
 *        File: LCDMenu.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: LCD Menu
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "LCDMenu.h"

// Top Level Menu (No Parent)
LCDMenu::LCDMenu(String _Name)
{
	Name = _Name;
	//Parent = NULL;
	
	//Create the Back Option
	String BackName = "Exit";
	Back = new LCDMenuItem(BackName);
}

// Sub Menu With Parent
LCDMenu::LCDMenu(String _Name, LCDMenu *_Parent)
{
	Name = _Name;
	ParentMenu = _Parent;
	
	//Create the Back Option
	String BackName = "Back";
	Back = new LCDMenuItem(BackName);
}


// default destructor
LCDMenu::~LCDMenu()
{
}

void LCDMenu::display(UserInterface *UI){
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
		for(int i=firstItemToPrint; i<min(Items.size(),firstItemToPrint + 3); i++){
			LCD->setCursor(0,ln);
			if (i == currentItem){
				LCD->print(">");
			}else{
				LCD->print(" ");
			}
			Items.get(i).Print(1,ln,UI);
			ln++;
		}
		refresh = 0;
	}
}

void LCDMenu::prevItem(void){
	currentItem--;
	if (currentItem < 0){ 
		currentItem = 0;
	}
	Serial.print("Encoder Item: ");
	Serial.println(currentItem);
	refresh = 1;
}

void LCDMenu::nextItem(void){
	currentItem++;
	if (currentItem > Items.size()){
		currentItem = Items.size();
	}
	Serial.print("Encoder Item: ");
	Serial.println(currentItem);
	refresh = 1;
}

void LCDMenu::selectItem(UserInterface *UI){
	Items.get(currentItem).ItemSelect(UI);
	refresh = 1;
}
