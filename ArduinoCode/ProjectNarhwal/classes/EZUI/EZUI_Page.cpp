/*
 *        File: EZUI_Page.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Display Page Class
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "EZUI_Page.h"

void EZUI_Page::setItems(const PageItem items[], unsigned int size){
	
	this->items = items;
	this->itemCount = size;
	
	//Determine the current item as the first selectable item
	currentItem = -1;
	for(int i=0; i<size;i++){
		if(items[i].Control->isSelectable()){
			currentItem = i;
			break;
		}
	}
}

void EZUI_Page::display(EZUI *UI){
	LiquidCrystal_I2C *LCD = UI->LCD;
	
	//Cycle through page items and refresh those which need it.
	unsigned long ctime = millis();
	if ((ctime - lastPrint)>=refreshRate){
		lastPrint = ctime;
		
		for(int i=0; i<(itemCount); i++){
			const PageItem *Item = &items[i];
			String newText = Item->Control->Text();
			
			//Truncate the string if needed
			if(newText.length() > Item->fieldWidth){
				newText = newText.substring(0,Item->fieldWidth);
			}
			String oldText = itemsText[i];
		
			unsigned long ctime = millis();
			if( refresh || !(newText.equals(oldText)) ) {
			
				//Print the new Text, if its a selectable item put a space before it;
				switch(Item->Control->Type){
					case(EZUI_Control::Label):
					{
						//Clear the old text
						LCD->setCursor(Item->col,Item->row);
						for(int k=0; k<oldText.length(); k++){
							LCD->print(" ");
						}
					
						//Write the New Text
						itemsText[i] = newText;
						LCD->setCursor(Item->col,Item->row);
						LCD->print(newText);
					} break;
					case(EZUI_Control::Link):
					{	
						//Clear the old text
						LCD->setCursor(Item->col+1,Item->row);
						for(int k=0; k<oldText.length(); k++){
							LCD->print(" ");
						}
					
						//Write the New Text
						itemsText[i] = newText;
						LCD->setCursor(Item->col+1,Item->row);
						LCD->print(newText);
					} break;
					case(EZUI_Control::ToggleOpt):
					{
						//Clear the old text
						LCD->setCursor(Item->col+1,Item->row);
						for(int k=0; k<oldText.length(); k++){
							LCD->print(" ");
						}
					
						//Write the New Tex
						itemsText[i] = newText;
						LCD->setCursor(Item->col+1,Item->row);
						LCD->print(newText);
					} break;
					default:{
						//Clear the old text
						LCD->setCursor(Item->col,Item->row);
						for(int k=0; k<oldText.length(); k++){
							LCD->print(" ");
						}
					
						//Write the New Text
						LCD->setCursor(Item->col+1,Item->row);
						LCD->print(newText);
					}break;
				}
			}
		}
	}
	
	//Clear refresh flag
	refresh = false; 
	
	if(itemChanged){			
		//Place the Cursor
			itemChanged = false;
			for(int i=0;i<itemCount;i++){
				const PageItem *Item = &items[i];
				if( Item->Control->isSelectable()){
					if(i==currentItem){
						LCD->setCursor(Item->col,Item->row);
						LCD->print(">");
					}else{
						LCD->setCursor(Item->col,Item->row);
						LCD->print(" ");
					}
				}
			}
	}
}

void EZUI_Page::prevItem(void){
	//See if theres a previously selectable item, if so set current item to that.
	for(int i=(currentItem-1);i>=0;i--){
		if( this->items[i].Control->isSelectable()){
			currentItem = i;
			break;
		}
	}
	itemChanged = true;
}

void EZUI_Page::nextItem(void){
	//See if theres a previously selectable item, if so set current item to that.
	//See if theres a previously selectable item, if so set current item to that.
	for(int i=(currentItem+1);i<itemCount;i++){
		if( this->items[i].Control->isSelectable()){
			currentItem = i;
			itemChanged = true;
			break;
		}
	}
	itemChanged = true;
}

void EZUI_Page::init(EZUI *UI){
	UI->LCD->clear();
	this->itemsText = new String[this->itemCount];
	for(int i=0; i<this->itemCount; i++){
		this->itemsText[i] = "!";
	}
	refresh = true;
	itemChanged = true;
}

void EZUI_Page::cleanup(EZUI *UI){
	UI->LCD->clear();
	String *txtArr = this->itemsText;
	delete[] txtArr; 
}

void EZUI_Page::selectItem(EZUI *UI){
	//See if theres a previously selectable item, if so set current item to that.
	if(currentItem > -1){
		items[currentItem].Control->Select(UI);
	}
}
