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

EZUI::EZUI(){
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
		Serial.println(F("Encoder Click"));
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
		Serial.println(F("Encoder Click"));
	#endif
	
}

void EZUI::EncoderIncrement(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
		Serial.println(F("Encoder Increment"));
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
		Serial.println(F("Encoder Decrement"));
	#endif
	
	if (!( CurrentMenu == NULL)){
		CurrentMenu->prevItem();
	}
	
	if (!( CurrentPage == NULL)){
		CurrentPage->prevItem();
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

void EZUI::refresh(){
	if(CurrentMenu!=NULL){
		CurrentMenu->cleanup(this);
		CurrentMenu->init(this);
		CurrentMenu->display(this);
	}
	if(CurrentPage != NULL){
		CurrentPage->cleanup(this);
		CurrentPage->init(this);
		CurrentPage->display(this);
	}
}
void EZUI::setDisplay(EZUI_Menu *Menu){
	if(CurrentMenu!=NULL){
		CurrentMenu->cleanup(this);
	}
	if(CurrentPage != NULL){
		CurrentPage->cleanup(this);
	}
	CurrentMenu = Menu;
	CurrentMenu->init(this);
	CurrentPage = NULL;
}

void EZUI::setDisplay(EZUI_Page *Page){
	if(CurrentMenu!=NULL){
		CurrentMenu->cleanup(this);
	}
	if(CurrentPage != NULL){
		CurrentPage->cleanup(this);
	}
	CurrentMenu = NULL;
	CurrentPage = Page;
	CurrentPage->init(this);
}