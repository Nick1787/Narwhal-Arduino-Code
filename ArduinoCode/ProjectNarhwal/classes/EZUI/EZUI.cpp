/*
 * EZUI.cpp
 *
 * Created: 8/12/2016 9:07:28 PM
 *  Author: Customer
 */ 

#include "EZUI.h"

void EZUI::attatchEncoder(ClickEncoderWithEvents* _Encoder){
	Encoder = _Encoder;
	//Encoder->ClearHandlers();
	Encoder->UI = this;
	Encoder->ClickHandler = &EZUI::EncoderClick;
	Encoder->DblClickHandler = &EZUI::EncoderDblClick;
	Encoder->IncrementHandler = &EZUI::EncoderIncrement;
	Encoder->DecrementHandler = &EZUI::EncoderDecrement;
};

void EZUI::EncoderClick(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
	Serial.println(F("Encoder Click"));
	#endif
	
	if ( CurrentDisplay != NULL){
		CurrentDisplay->selectItem(this);
	}
};

void EZUI::EncoderDblClick(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
	Serial.println(F("Encoder Double Click"));
	#endif
};

void EZUI::EncoderIncrement(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
	Serial.println(F("Encoder Increment"));
	#endif
	
	if ( CurrentDisplay != NULL){
		CurrentDisplay->nextItem(this);
	}
};

void EZUI::EncoderDecrement(){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
	Serial.println(F("Encoder Decrement"));
	#endif
	
	if ( CurrentDisplay != NULL){
		CurrentDisplay->prevItem(this);
	}
};

void EZUI::display(){
	//Attatch all event handlers
	if (CurrentDisplay != NULL){
		lastDisplayMillis = millis();
		CurrentDisplay->display(this);
		}else{
		//display nothing
		if((millis() - lastDisplayMillis) > 3000){
			lastDisplayMillis = millis();
			LCD->clear();
			LCD->println("ERROR!");
			LCD->println("  No Page or Menu");
		}
	}
};

void EZUI::refresh(){
	if(CurrentDisplay!=NULL){
		CurrentDisplay->cleanup(this);
		CurrentDisplay->init(this);
		CurrentDisplay->display(this);
	}
};

void EZUI::setDisplay(EZUI_Display *Disp){
	if(CurrentDisplay!=NULL){
		CurrentDisplay->cleanup(this);
	}
	CurrentDisplay = Disp;
	CurrentDisplay->init(this);
};

