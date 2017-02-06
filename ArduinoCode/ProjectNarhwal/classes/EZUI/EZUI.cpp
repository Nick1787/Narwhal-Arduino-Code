/*
 * EZUI.cpp
 *
 * Created: 8/12/2016 9:07:28 PM
 *  Author: Customer
 */ 

#include "EZUI.h"
#include "EZUI_Display.h"

void EZUI::attatchEncoder(EZUI_ClickEncoder* _Encoder){
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
	//Read the Encoder
	Encoder->Read();     //Read Encoder
  
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
	
	//If the current display is a List Option Editor, Delete it!
	if( CurrentDisplay->Type == EZUI_Display::EZUI_DisplayType::ListOpt){
		EZUI_ListOptionEditor* Editor = (EZUI_ListOptionEditor*)CurrentDisplay;
		delete Editor;
	}
	
	//If the current display is a List Option Editor, Delete it!
	else if( CurrentDisplay->Type == EZUI_Display::EZUI_DisplayType::AdjOpt){
		EZUI_AdjustParamEditor* Editor = (EZUI_AdjustParamEditor*)CurrentDisplay;
		delete Editor;
	}
		
	//Set the Current Display
	CurrentDisplay = Disp;
	CurrentDisplay->init(this);
};

void EZUI::EditListOption(GenericListOption * ListOptRef){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>2)
		Serial.println(F("  Open List Editor."));
	#endif
		
	EZUI_ListOptionEditor * editor = new EZUI_ListOptionEditor(ListOptRef,this->CurrentDisplay);
	this->setDisplay(editor);
}

void EZUI::EditAdjustParam(AdjustableParam * AdjRef){
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>2)
		Serial.println(F("  Open Adjustment Editor."));
	#endif
		
	EZUI_AdjustParamEditor* editor = new EZUI_AdjustParamEditor(AdjRef,this->CurrentDisplay);
	this->setDisplay(editor);
}