/*
 *        File: EZUI.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "EZUI.h"

EZUI::EZUI(String _Name){
	Name = _Name;
}

EZUI::~EZUI(){
}

void EZUI::attatchEncoder(ClickEncoderWithEvents *_Encoder){
	Encoder = _Encoder;
	//Encoder->ClearHandlers();
	Encoder->UI = this;
	Encoder->ClickHandler = &EZUI::EncoderClick;
	Encoder->DblClickHandler = &EZUI::EncoderDblClick;
	Encoder->IncrementHandler = &EZUI::EncoderIncrement;
	Encoder->DecrementHandler = &EZUI::EncoderDecrement;
}

void EZUI::attatchLCD( LiquidCrystal_I2C *_LCD ){
	LCD = _LCD;
}


void EZUI::EncoderClick(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
		Serial.print(Name);
		Serial.println(" - Encoder Click");
	#endif
	
	if ( CurrentMenu != NULL){
		CurrentMenu->selectItem(this);
	}else{
		if ( CurrentPage != NULL){
			CurrentPage->selectItem(this);
		}
	}
}

void EZUI::EncoderDblClick(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
		Serial.print(Name);
		Serial.println(" - Encoder Click");
	#endif
	
}

void EZUI::EncoderIncrement(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
		Serial.print(Name);
		Serial.println(" - Encoder Increment");
	#endif
	
	if (!( CurrentMenu == NULL)){
		CurrentMenu->nextItem();
	}
	
	if (!( CurrentPage == NULL)){
		CurrentPage->nextItem();
	}
}

void EZUI::EncoderDecrement(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
		Serial.print(Name);
		Serial.println(" - Encoder Decrement");
	#endif
	
	if (!( CurrentMenu == NULL)){
		CurrentMenu->prevItem();
	}
}

void EZUI::display(){
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

void EZUI::setDisplay(EZUI_Menu *Menu){
	CurrentMenu = Menu;
	CurrentPage = NULL;
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println( "  " + Name + "-UI-" + "-DisplayMenu->" + CurrentMenu->Name);
	#endif
}

void EZUI::setDisplay(EZUI_Page *Page){
	CurrentMenu = NULL;
	CurrentPage = Page;
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println( "  " + Name + "-UI-" + "-DisplayPage->" + CurrentPage->Name);
	#endif
}