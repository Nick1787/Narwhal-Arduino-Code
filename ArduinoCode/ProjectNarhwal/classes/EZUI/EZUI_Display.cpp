/*
 * EZUI_Dispay.cpp
 *
 * Created: 8/12/2016 8:57:00 PM
 *  Author: Customer
 */ 

#include "EZUI_Display.h"

/* Page ********************************************************************/

void EZUI_Page::setItems(const PageItem _items[], unsigned int _size){
	
	this->items = _items;
	this->itemCount = _size;
	this->refresh = true;
	
	//Determine the current item as the first selectable item
	currentItem = -1;
	for(int i=0; i<_size;i++){
		PageItem Item;
		PROGMEM_readAnything (&this->items[i], Item);
		if(Item.Control->isSelectable()){
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
			
			PageItem Item;
			PROGMEM_readAnything (&this->items[i], Item);
			String newText = Item.Control->LabelText();
			
			//Truncate the string if needed
			if(newText.length() > Item.fieldWidth){
				newText = newText.substring(0,Item.fieldWidth);
			}
			String oldText = itemsText[i];
			
			unsigned long ctime = millis();
			if( refresh || !(newText.equals(oldText)) ) {
				
				//Clear the old text
				LCD->setCursor(Item.col,Item.row);
				for(int k=0; k<oldText.length(); k++){
					LCD->print(" ");
				}
				
				//Write the New Text
				itemsText[i] = newText;
				LCD->setCursor(Item.col,Item.row);
				if(Item.Control->isSelectable()){
					LCD->print(" ");
				}
				LCD->print(newText);
			}
		}
	}
	
	//Clear refresh flag
	refresh = false;
	
	if(itemChanged){
		//Place the Cursor
		itemChanged = false;
		for(int i=0;i<itemCount;i++){
			PageItem Item;
			PROGMEM_readAnything (&this->items[i], Item);
			if( Item.Control->isSelectable()){
				if(i==currentItem){
					LCD->setCursor(Item.col,Item.row);
					LCD->print(">");
					}else{
					LCD->setCursor(Item.col,Item.row);
					LCD->print(" ");
				}
			}
		}
	}
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

void EZUI_Page::prevItem(EZUI *UI){
	//See if theres a previously selectable item, if so set current item to that.
	for(int i=(currentItem-1);i>=0;i--){
		PageItem Item;
		PROGMEM_readAnything (&this->items[i], Item);
		if( Item.Control->isSelectable()){
			currentItem = i;
			break;
		}
	}
	itemChanged = true;
}

void EZUI_Page::nextItem(EZUI *UI){
	//See if theres a previously selectable item, if so set current item to that.
	for(int i=(currentItem+1);i<itemCount;i++){
		PageItem Item;
		PROGMEM_readAnything (&this->items[i], Item);
		if( Item.Control->isSelectable()){
			currentItem = i;
			itemChanged = true;
			break;
		}
	}
	itemChanged = true;
}

void EZUI_Page::selectItem(EZUI *UI){
	//See if theres a previously selectable item, if so set current item to that.
	if(currentItem > -1){
		PageItem Item;
		PROGMEM_readAnything (&this->items[currentItem], Item);
		Item.Control->Select(UI);
	}
}

/* MENU ********************************************************************/

void EZUI_Menu::init(EZUI *UI){
	refresh = true;
	itemChanged = true;
}

void EZUI_Menu::display(EZUI *UI){
	LiquidCrystal_I2C *LCD = UI->LCD;
	
	if(refresh){
		printPage(UI);
		refresh = false;
	}
	
	if (itemChanged){
		//Print each menu item (3 items left on line)
		for(int i=0; i<4; i++){
			LCD->setCursor(0,i);
			if (i==cursorLine){
				LCD->print(">");
			}else{
				LCD->print(" ");
			}
		}
	}
}

void EZUI_Menu::setItems(const MenuItem _items[], unsigned int _size){
	this->items = _items;
	this->itemCount = _size;
	this->refresh = true;
	
	//Determine the current item as the first selectable item
	currentItem = -1;
	for(int i=0; i<_size;i++){
		MenuItem Item;
		PROGMEM_readAnything (&this->items[i], Item);
		
		if(Item.Control->isSelectable()){
			currentItem = i;
			break;
		}
	}
}

void EZUI_Menu::prevItem(EZUI *UI){
	int oldCurrentItem = currentItem;
	currentItem = max(0,currentItem-1);
	itemChanged = true;
	
	if(cursorLine == 0){
		refresh = true;
	}else if(cursorLine > 0){
		cursorLine--;
	}
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>2)
		Serial.print(F("  Menu Item:"));
		Serial.println(currentItem);
	#endif
}

void EZUI_Menu::nextItem(EZUI *UI){
	int oldCurrentItem = currentItem;
	currentItem = min(itemCount-1,currentItem+1);
	itemChanged = true;
	
	if(cursorLine == 3){
		refresh = true;
	}
	
	if(cursorLine < itemCount-1){
		cursorLine++;
	}
	
	//Determine if we changed the menu page, if so- reprint it;
	if(cursorLine > 3){
		cursorLine = 3;
	}
	
#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>2)
		Serial.print(F("  Menu Item:"));
		Serial.println(currentItem);
#endif
}

void EZUI_Menu::selectItem(EZUI *UI){
	MenuItem Item;
	PROGMEM_readAnything (&this->items[currentItem], Item);
			
	EZUI_Control::EZUI_ControlType Type = Item.Control->Type;
	switch (Type) {
		case(EZUI_Control::Link):{
			const EZUI_Control_Link * CtrlItem = (EZUI_Control_Link*)(Item.Control);
			CtrlItem->Select(UI);
			refresh = true;
			itemChanged = true;
			}break;
		case(EZUI_Control::ToggleControl):{
			const EZUI_Control_ToggleOption * CtrlItem = (EZUI_Control_ToggleOption const*)(Item.Control);
			CtrlItem->Select(UI);
			UI->display();
			refresh = true;
			itemChanged = true;
			}break;
		case(EZUI_Control::ListControl):{
			const EZUI_Control_ListOption * CtrlItem = (EZUI_Control_ListOption const*)(Item.Control);
			CtrlItem->Select(UI);
			refresh = true;
			itemChanged = true;
		}break;
	}
}

void EZUI_Menu::printPage(EZUI *UI){
	LiquidCrystal_I2C *LCD = UI->LCD;
	UI->LCD->clear();
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>2)
		Serial.print(F("  Menu-currentItem:"));
		Serial.println(currentItem);
		Serial.print(F("  Menu-CursorLocation:"));
		Serial.println(cursorLine);
		Serial.print(F("  ItemCount:"));
		Serial.println(itemCount);
	#endif
		
	//print the items 
	if(cursorLine == 0){
		//If cursor is at line0, print the current item first
		int ln = 0;
		for(int i=currentItem; i<min(itemCount,currentItem+4); i++){
			printItem( UI, ln, i);
			ln++;
		}
	}else if(cursorLine == 3){
		//If cursor is at line3, print the current item last
		if( itemCount > 3){
			int ln = 3;
			for(int i=currentItem; i>=max(0,currentItem-3); i--){
				printItem( UI, ln, i);
				ln--;
			}
		}else{
			//This shouldnt happen, so try and recover
			cursorLine = itemCount-1;
			int ln = cursorLine;
			for(int i=currentItem; i--; i>0){
				printItem( UI, ln, i);
				ln--;
			}
		}
	}else{
		//Were somewhere in between, so figure out first item to print and go from there
		int firstItemToPrint = currentItem - cursorLine ;
		int ln = 0;
		for( int i = firstItemToPrint; i<min(itemCount, firstItemToPrint+4); i++){
			printItem( UI, ln, i);
			ln++;
		}
	}
	
	
	
}

void EZUI_Menu::printItem(EZUI *UI, unsigned int line, unsigned int ItemIndex){
	
	//Print the Label
	MenuItem Item;
	PROGMEM_readAnything (&this->items[ItemIndex], Item);
	String Label = Item.Control->LabelText();
	
	UI->LCD->setCursor(1,line);
	UI->LCD->print(Label);
		
	//If theres a value print it too, with alteast one space, but as far right as possible.
	if( Item.Control->hasValueText()){
		String valTxt = Item.Control->ValueText();
		int row = max(Label.length() + 2, 20-valTxt.length()-1);
		UI->LCD->setCursor(row,line);
		UI->LCD->print(valTxt);
	}
}

/* ListOptionEditor ********************************************************************/


void EZUI_ListOptionEditor::drawListItems(EZUI *UI){
	UI->LCD->clear();
	
	int currentIndex = ListOptRef->currentItem();
	if( (temp_index == 0)){
		//Starting at Item 0, Special Case
		
		//Print Item 0
		UI->LCD->setCursor(2,1);
		UI->LCD->print(">");
		if( currentIndex == 0 ){
			UI->LCD->print("*");
			}else{
			UI->LCD->print(" ");
		}
		UI->LCD->print( ListOptRef->itemText(0) );
		
		//Print Item 1
		UI->LCD->setCursor(2,2);
		UI->LCD->print(" ");
		if( currentIndex == 1 ){
			UI->LCD->print("*");
			}else{
			UI->LCD->print(" ");
		}
		UI->LCD->print( ListOptRef->itemText(1) );
	}else if( temp_index == (ListOptRef->itemCount() - 1)){
		//Starting at Item N - Last Item, Special Case
		
		//Print Item N-1
		UI->LCD->setCursor(2,0);
		UI->LCD->print(" ");
		if( currentIndex == temp_index - 1 ){
			UI->LCD->print("*");
		}else{
			UI->LCD->print(" ");
		}
		UI->LCD->print( ListOptRef->itemText(temp_index - 1) );
		
		//Print Item N
		UI->LCD->setCursor(2,1);
		UI->LCD->print(">");
		if( currentIndex == temp_index ){
			UI->LCD->print("*");
			}else{
			UI->LCD->print(" ");
		}
		UI->LCD->print( ListOptRef->itemText(temp_index) );
	}else{
		//Not Starting at Item 0;
		int firstIndex = temp_index - 1;
		for(int i=0; i<3; i++){
			UI->LCD->setCursor(2,i);
			if( i == 1){
				UI->LCD->print(">");
				}else{
				UI->LCD->print(" ");
			}
			
			if( (firstIndex + i) == currentIndex){
				UI->LCD->print("*");
				}else{
				UI->LCD->print(" ");
			}
			UI->LCD->print( ListOptRef->itemText(firstIndex + i));
		}
		
		
	}
	
	//Print Apply/Cancel Buttons
	UI->LCD->setCursor(1,3);
	UI->LCD->print("Cancel");
	UI->LCD->setCursor(15,3);
	UI->LCD->print("Apply");
}

void EZUI_ListOptionEditor::init(EZUI *UI){
	UI->LCD->clear();
	this->refresh = true;
	temp_index = ListOptRef->currentItem();
	
	
	//Handle all the cases
	if(ListOptRef->itemCount() == 0){
		// No Items In List
		Mode = ERR;
	}else if(ListOptRef->itemCount() == 1){
		//One Item In List
		Mode = ONITEM;
	}else{
		Mode = SEL;
	}
	
	drawListItems(UI);
}

void EZUI_ListOptionEditor::cleanup(EZUI *UI){
	//Nothing To Do Here
}

void EZUI_ListOptionEditor::display(EZUI *UI){
	//Nothing To Do Here
}

void EZUI_ListOptionEditor::prevItem(EZUI *UI){
	
	if(Mode == SEL){
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>2)
			Serial.print(F("  ListEditor - Previous Item - CurrentValue:"));
			Serial.print(temp_index);
			Serial.print(F(" - NextValue:"));
			Serial.print(temp_index-1);
			Serial.print(F(" - ItemCount:"));
			Serial.println(ListOptRef->itemCount()-1);
		#endif
		
		if(temp_index > 0){
			temp_index = temp_index-1;
		}
		drawListItems(UI);
	}else if(Mode == OKCANCEL){
		APPLY = !APPLY;
		if(!APPLY){
			UI->LCD->setCursor(0,3);
			UI->LCD->print(">");
			
			UI->LCD->setCursor(14,3);
			UI->LCD->print(" ");
		}else{
			UI->LCD->setCursor(0,3);
			UI->LCD->print(" ");
		
			UI->LCD->setCursor(14,3);
			UI->LCD->print(">");
		}
	}
}

void EZUI_ListOptionEditor::nextItem(EZUI *UI){
	
	if(Mode == SEL){
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>2)
			Serial.print(F("  ListEditor - Next Item - CurrentValue:"));
			Serial.print(temp_index);
			Serial.print(F(" - NextValue:"));
			Serial.print(temp_index+1);
			Serial.print(F(" - ItemCount:"));
			Serial.println(ListOptRef->itemCount());
		#endif
		
		if(temp_index < ListOptRef->itemCount()-1){
			temp_index = temp_index+1;
		}
		drawListItems(UI);
	}else if(Mode == OKCANCEL){
		APPLY = !APPLY;
		if(!APPLY){
			UI->LCD->setCursor(0,3);
			UI->LCD->print(">");
			
			UI->LCD->setCursor(14,3);
			UI->LCD->print(" ");
		}else{
			UI->LCD->setCursor(0,3);
			UI->LCD->print(" ");
			
			UI->LCD->setCursor(14,3);
			UI->LCD->print(">");
		}
	}
}

void EZUI_ListOptionEditor::selectItem(EZUI *UI){
	
	//See if theres a previously selectable item, if so set current item to that.
	if(Mode == ERR){
		UI->setDisplay(ParentDispRef);
	}else if(Mode == ONITEM){
		UI->setDisplay(ParentDispRef);
	}else if(Mode == SEL){
		//Clear the Select arrow
		UI->LCD->setCursor(2,0);
		UI->LCD->print("  ");
		UI->LCD->setCursor(2,1);
		UI->LCD->print(" *");
		UI->LCD->setCursor(2,2);
		UI->LCD->print("  ");
		
		Mode = OKCANCEL;
		if(!APPLY){
			UI->LCD->setCursor(0,3);
			UI->LCD->print(">");
			
			UI->LCD->setCursor(13,3);
			UI->LCD->print(" ");
		}else{
			UI->LCD->setCursor(0,3);
			UI->LCD->print(" ");
			
			UI->LCD->setCursor(14,3);
			UI->LCD->print(">");
		}
	}else if (Mode == OKCANCEL){
		if(APPLY){
			ListOptRef->setItem(temp_index);
		}
		UI->setDisplay(ParentDispRef);
	}
}


/* EZUI_AdjustParamEditor ********************************************************************/

void EZUI_AdjustParamEditor::init(EZUI *UI){
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>2)
		Serial.println(F("   Adjustment Editor"));
		Serial.print(F("    MIN:"));
		Serial.println(AdjParamRef->minValue);
		Serial.print(F("    MAX:"));
		Serial.println(AdjParamRef->maxValue);
		Serial.print(F("    VAL:"));
		Serial.println(AdjParamRef->value);
	#endif
			
	UI->LCD->clear();
	this->refresh = true;
	
	//Print Min Value Text
	UI->LCD->setCursor(10,0);
	UI->LCD->print("MIN:");
	UI->LCD->print(AdjParamRef->minVaueText());
		
	//Print Max Value Text
	UI->LCD->setCursor(10,1);
	UI->LCD->print("MAX:");
	UI->LCD->print(AdjParamRef->maxVaueText());
	
	//Print Current Value Text
	UI->LCD->setCursor(10,2);
	UI->LCD->print("VAL:");
	UI->LCD->print(AdjParamRef->valueText());
		
	//Print the Current Value
	_tempValue = AdjParamRef->getValue();
	UI->LCD->setCursor(1,1);
	UI->LCD->print(">");
	String CV = AdjParamRef->valueText();
	UI->LCD->print(CV.substring(0,min(CV.length()-1,7)));
		
	//Print Apply/Cancel Buttons
	UI->LCD->setCursor(1,3);
	UI->LCD->print("Cancel");
	UI->LCD->setCursor(15,3);
	UI->LCD->print("Apply");
	
}

void EZUI_AdjustParamEditor::cleanup(EZUI *UI){
	//Nothing To Do Here
}

void EZUI_AdjustParamEditor::display(EZUI *UI){
	//Nothing To Do Here
}

void EZUI_AdjustParamEditor::prevItem(EZUI *UI){
	if( Mode == ADJUST ){
		unsigned long diff = millis() - lastUpdate;
		if( diff < 50 ){
			
			#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
				Serial.print(F("     Decrement Adjustment Value - Big - "));
				Serial.println(diff);
			#endif
			
			_tempValue = max( AdjParamRef->minValue, _tempValue - 10*AdjParamRef->increment);
		}else{
			
			#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
				Serial.print(F("     Decrement Adjustment Value - Small - "));
				Serial.println(diff);
			#endif
			
			_tempValue = max( AdjParamRef->minValue, _tempValue - AdjParamRef->increment);
		}
		lastUpdate += diff;
		String strTempVal = String(_tempValue);
		
		UI->LCD->setCursor(2,1);
		UI->LCD->print("        ");
		UI->LCD->setCursor(2,1);
		UI->LCD->print( strTempVal.substring(0, min(7, strTempVal.length())));
	}else if(Mode == OKCANCEL){
		APPLY = !APPLY;
		if(APPLY){
			UI->LCD->setCursor(0,3);
			UI->LCD->print(" ");
			
			UI->LCD->setCursor(14,3);
			UI->LCD->print(">");
		}else{
			UI->LCD->setCursor(0,3);
			UI->LCD->print(">");
			
			UI->LCD->setCursor(14,3);
			UI->LCD->print(" ");
		}
	}
}

void EZUI_AdjustParamEditor::nextItem(EZUI *UI){
	
	if( Mode == ADJUST ){
		unsigned long diff = millis() - lastUpdate;
		if( diff < 50 ){
			#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
				Serial.print(F("     Increment Adjustment Value - Big - "));
				Serial.println(diff);
			#endif
			
			_tempValue = min( AdjParamRef->maxValue, _tempValue + 10*AdjParamRef->increment);
		}else{
			#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
				Serial.print(F("     Increment Adjustment Value - Small - "));
				Serial.println(diff);
			#endif
			
			_tempValue = min( AdjParamRef->maxValue, _tempValue + AdjParamRef->increment);
		}
		lastUpdate += diff;
		String strTempVal = String(_tempValue);
		
		UI->LCD->setCursor(2,1);
		UI->LCD->print("        ");
		UI->LCD->setCursor(2,1);
		UI->LCD->print( strTempVal.substring(0, min(7, strTempVal.length())));
	}else if(Mode == OKCANCEL){
		APPLY = !APPLY;
		if(APPLY){
			UI->LCD->setCursor(0,3);
			UI->LCD->print(" ");
			
			UI->LCD->setCursor(14,3);
			UI->LCD->print(">");
		}else{
			UI->LCD->setCursor(0,3);
			UI->LCD->print(">");
			
			UI->LCD->setCursor(14,3);
			UI->LCD->print(" ");
		}
	}
}

void EZUI_AdjustParamEditor::selectItem(EZUI *UI){
	if(Mode == ERR){
		UI->setDisplay(ParentDispRef);
	}else if(Mode == ADJUST){
		Mode = OKCANCEL;
		UI->LCD->setCursor(1,1);
		UI->LCD->print(" ");
		
		if(APPLY){
			UI->LCD->setCursor(0,3);
			UI->LCD->print(" ");
			
			UI->LCD->setCursor(14,3);
			UI->LCD->print(">");
		}else{
			UI->LCD->setCursor(0,3);
			UI->LCD->print(">");
			
			UI->LCD->setCursor(14,3);
			UI->LCD->print(" ");
		}
	}else if (Mode == OKCANCEL){
		if(APPLY){
			AdjParamRef->set(_tempValue);
		}
		UI->setDisplay(ParentDispRef);
	}
}