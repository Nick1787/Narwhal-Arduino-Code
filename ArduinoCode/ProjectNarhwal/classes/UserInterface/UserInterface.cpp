/*
 *        File: UserInterface.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Class code for high level class for a burner controller LCD
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "UserInterface.h"

UserInterface::UserInterface(String _Name){
	Name = _Name;
}

UserInterface::~UserInterface(){
}

void UserInterface::attatchEncoder(ClickEncoderWithEvents *_Encoder){
	Encoder = _Encoder;
	//Encoder->ClearHandlers();
	Encoder->UI = this;
	Encoder->ClickHandler = &UserInterface::EncoderClick;
	Encoder->DblClickHandler = &UserInterface::EncoderDblClick;
	Encoder->IncrementHandler = &UserInterface::EncoderIncrement;
	Encoder->DecrementHandler = &UserInterface::EncoderDecrement;
}

void UserInterface::attatchLCD( LiquidCrystal_I2C *_LCD ){
	LCD = _LCD;
}


void UserInterface::EncoderClick(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
		Serial.println(Name + " - Encoder Click");
	#endif
	
	if ( CurrentMenu != NULL){
		CurrentMenu->selectItem(this);
	}
}

void UserInterface::EncoderDblClick(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
		Serial.println(Name + " - Encoder Double Click");
	#endif
	
}

void UserInterface::EncoderIncrement(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
		Serial.println( "  " + Name + " - Encoder Increment");
	#endif
	
	if (!( CurrentMenu == NULL)){
		CurrentMenu->nextItem();
	}
	
}

void UserInterface::EncoderDecrement(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
		Serial.println("  " + Name + " - Encoder Decrement");
	#endif
	
	if (!( CurrentMenu == NULL)){
		CurrentMenu->prevItem();
	}
}

void UserInterface::display(){
	//Attatch all event handlers
	if (CurrentPage != NULL){
		lastDisplayMillis = millis();
		CurrentPage->display(this);
	}else if (CurrentMenu != NULL){
		lastDisplayMillis = millis();
		CurrentMenu->display(this);
	}else{
		//display nothing
		if((millis() - lastDisplayMillis) > 3000){
			lastDisplayMillis = millis();
			LCD->clear();
			LCD->println("ERROR!");
			LCD->println("  No Page or Menu");
		}
	}
}

void UserInterface::setDisplay(LCDMenu *Menu){
	CurrentMenu = Menu;
	CurrentPage = NULL;
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println( "  " + Name + "-UI-" + "-DisplayMenu->" + CurrentMenu->Name);
	#endif
}

void UserInterface::setDisplay(LCDPage *Page){
	CurrentMenu = NULL;
	CurrentPage = Page;
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println( "  " + Name + "-UI-" + "-DisplayPage->" + CurrentPage->Name);
	#endif
}