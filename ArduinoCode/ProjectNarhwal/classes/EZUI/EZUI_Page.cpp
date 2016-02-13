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

// default constructor
EZUI_Page::EZUI_Page()
{
} //LCDPage

// constructor with name passed, no parent menu or page
EZUI_Page::EZUI_Page(String _Name)
{
	_ParentMenuRef = NULL;
	_ParentPageRef = NULL;
	Name = _Name;
}

// default destructor
EZUI_Page::~EZUI_Page()
{
} //~LCDPage

void EZUI_Page::display(EZUI *UI){
	if((millis() - lastUpdate)>refreshRate){
		lastUpdate = millis();
		
		LiquidCrystal_I2C *LCD = UI->LCD;
		LCD->clear();
		for(int i=0; i<_Items.size(); i++){
			_Items.get(i).print(LCD, true);
			
			Serial.print("  Item ...");
			//Print Cursor if at the current Item
			if (SelectableItems.size() > 0){
				if(i==currentItem){
					LCD->setCursor(_Items.get(i).col,_Items.get(i).row);
					LCD->print(">");
				}
			}
		}
	}
}


void EZUI_Page::addItem(EZUI_PageItem * _Item){
	_Items.add(*_Item);
	
	if((_Item->Type == EZUI_PageItem::Link) || (_Item->Type == EZUI_PageItem::ToggleOption)){
		SelectableItems.add(1);
		if(currentItem == -1){
			currentItem = SelectableItems.size()-1;
		}
	}else{
		SelectableItems.add(0);
	}
}

void EZUI_Page::prevItem(void){
	//See if theres a previously selectable item, if so set current item to that.
	if(currentItem > -1){
		for( int i=currentItem; i>0; i--){
			if (SelectableItems.get(i) == 1){
				currentItem = i;
				break;
			}
		}
	}
	Serial.println(Name + " - Encoder Item: ");
	Serial.println(currentItem);
	refresh = 1;
}

void EZUI_Page::nextItem(void){
	if(currentItem > -1){
		for( int i=currentItem; i<(SelectableItems.size()-1); i++){
			if (SelectableItems.get(i) == 1){
				currentItem = i;
				break;
			}
		}
	}
	Serial.println(Name + " - Encoder Item: ");
	Serial.println(currentItem);
	refresh = 1;
}

void EZUI_Page::selectItem(EZUI *UI){
	_Items.get(currentItem).ItemSelect(UI);
	refresh = 1;
}