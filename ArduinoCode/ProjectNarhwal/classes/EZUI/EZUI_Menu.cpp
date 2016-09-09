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


void EZUI_Menu::setItems(const MenuItem items[], unsigned int size){
	/*for(int i=0; i<size;i++){
		Serial.print(F(" --");
		Serial.print(i);
		Serial.print(F("--");
		Serial.print(items[i].Control->Text());
		Serial.println(F("--");
		Serial.flush();
	}*/
	this->items = items;
	this->itemCount = size;
	
	//Determine the current item as the first selectable item
	currentItem = -1;
	for(int i=0; i<size;i++){
		if(items[i].Control->isSelectable()){
			//Serial.print(F("--CurrentItem-");
			//Serial.print(i);
			//Serial.println(F("-");
			currentItem = i;
			break;
		}
	}
}
void EZUI_Menu::display(EZUI *UI){
	LiquidCrystal_I2C *LCD = UI->LCD;
	
	if(refresh){
		printPage(UI);
	}
	
	if (refresh || itemChanged){
		//Print each menu item (3 items left on line)
		int firstItemToPrint = (int)(currentItem/3);
		int ln = 0;
		for(int i=firstItemToPrint; i<min(itemCount,firstItemToPrint + 4); i++){
			LCD->setCursor(0,ln);
			if (i==currentItem)
			{
				LCD->print(">");
			}else{
				LCD->print(" ");
			}
			ln++;
		}
	}
	

	if(refresh){
		refresh = false;
	}
}

void EZUI_Menu::printPage(EZUI *UI){
	LiquidCrystal_I2C *LCD = UI->LCD;
	UI->LCD->clear();
	
	//Clear the refresh flag
	refresh = false;

	//print the items
	int firstItemToPrint = (int)(currentItem/3);
	int ln = 0;
	for(int i=firstItemToPrint; i<min(itemCount,firstItemToPrint + 4); i++){
		LCD->setCursor(0,ln);
		if (i==currentItem)
		{
			LCD->print(">");
			}else{
			LCD->print(" ");
		}
		
		switch (items[i].Control->Type) {
			case(EZUI_Control::Link):{
				EZUI_Control_Link const * Item = (EZUI_Control_Link const*)(items[i].Control);
				EZUI_Menu::printItem(1,ln,LCD,Item);
			}break;
			case(EZUI_Control::ToggleOpt):{
				EZUI_Control_ToggleOption const * Item = (EZUI_Control_ToggleOption const*)(items[i].Control);
				EZUI_Menu::printItem(1,ln,LCD,Item);
			}break;
			default:{
				Serial.println(F("  ERR! Unknown Menu Item Type"));
			}break;
		}
		ln++;
	}
}

void EZUI_Menu::init(EZUI *UI){
	refresh = true;
}

void EZUI_Menu::cleanup(EZUI *UI){
}

void EZUI_Menu::prevItem(){
	int oldCurrentItem = currentItem;
	currentItem--;
	if (currentItem < 0){ 
		currentItem = 0;
	}
	itemChanged = true;
	
	//Determine if we changed the menu page, if so- reprint it;
	if((currentItem % 4==3) && (currentItem < oldCurrentItem)){
		Serial.println(F("  Redraw"));
		refresh = true;
	}
	
	Serial.print(F("  Menu Item:"));
	Serial.println(currentItem);
}

void EZUI_Menu::nextItem(){
	int oldCurrentItem = currentItem;
	currentItem++;
	if (currentItem >= itemCount){
		currentItem = itemCount-1;
	}
	itemChanged = true;
	
	//Determine if we changed the menu page, if so- reprint it;
	if((currentItem % 4 == 0) && (currentItem>oldCurrentItem)){
		Serial.println(F("  Redraw"));
		refresh = true;
	}
		
	Serial.print(F("  Menu Item:"));
	Serial.println(currentItem);
}

void EZUI_Menu::selectItem(EZUI *UI){
	EZUI_Control::ControlType Type = items[currentItem].Control->Type;
	switch (Type) {
		case(EZUI_Control::Link):{
			EZUI_Control_Link const * Item = (EZUI_Control_Link const*)(items[currentItem].Control);
			EZUI_Menu::selectItem(UI,Item);
		}break;
		case(EZUI_Control::ToggleOpt):{
			EZUI_Control_ToggleOption const * Item = (EZUI_Control_ToggleOption const*)(items[currentItem].Control);
			EZUI_Menu::selectItem(UI,Item);
		}break;
	}
}

//Item Select
void EZUI_Menu::selectItem(EZUI *UI, EZUI_Control_Link const * LinkRef){
		if (LinkRef == NULL){
			UI->LCD->clear();
			UI->LCD->setCursor(0,0);
			UI->LCD->println("Error!");
			UI->LCD->setCursor(0,1);
			UI->LCD->println("Selected Menu item null");
			delay(3000);
			UI->display();
		}else{
			LinkRef->Select(UI);
		}
}

void EZUI_Menu::selectItem(EZUI *UI, EZUI_Control_ToggleOption const * ToggleOptRef){
	(*ToggleOptRef).Toggle();
	UI->display();
	refresh = true;
	itemChanged = true;
}

//Print
void EZUI_Menu::printItem(int col, int row, LiquidCrystal_I2C * LCD, EZUI_Control_Link const *LinkRef){
	if(!(LinkRef == NULL)){
		//Serial.println(F("PrintingLinkRef");
		LCD->setCursor(col,row);
		LCD->print((*LinkRef).Label);
	}
}

void EZUI_Menu::printItem(int col, int row, LiquidCrystal_I2C * LCD, EZUI_Control_ToggleOption const * ToggleOptRef){
	if (!(ToggleOptRef == NULL)){
		//Serial.println(F("PrintingToggleOpts");
		EZUI_Control_ToggleOption TglOpt = *ToggleOptRef;
		LCD->setCursor(col,row);
		LCD->print(TglOpt.Label);
		
		String TrueLabel = TglOpt.TrueLabel();
		int TrueTextLen = TrueLabel.length();
		String FalseLabel = TglOpt.FalseLabel();
		int FalseTextLen = FalseLabel.length();
		
		//Set Cursor Position
		int display_width = 20;
		if(TrueTextLen>FalseTextLen){
			int StartPos = display_width-TrueTextLen - 1;
			LCD->setCursor(StartPos,row);
			
			//Print spaces to clear the label
			int i=0;
			for(i=StartPos; i<=display_width; i++){
				LCD->print(" ");
			}
			LCD->setCursor(StartPos,row);
			}else{
			int StartPos = display_width-FalseTextLen - 1;
			LCD->setCursor(StartPos,row);
			
			//Print spaces to clear the label
			int i=0;
			for(i=StartPos; i<=display_width; i++){
				LCD->print(" ");
			}
			LCD->setCursor(StartPos,row);
		}
		
		//Print current value
		if(TglOpt.Value() == 1){
			LCD->print(TrueLabel);
			}else{
			LCD->print(FalseLabel);
		}
	}
}