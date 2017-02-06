/* 
* EZUI_ClickEncoder.cpp
*
* Created: 11/14/2015 5:06:21 PM
* Author: Customer
*/


#include "EZUI_Hardware_ClickEncoder.h"

// default destructor
EZUI_ClickEncoder::~EZUI_ClickEncoder()
{
} //~EZUI_ClickEncoder

void EZUI_ClickEncoder::Read(){
			t_value += this->getValue();
			if(t_value > t_prev_value){
				if( !(IncrementHandler == NULL)){
				
					t_prev_value = t_value;
					(UI->*IncrementHandler)();
				}
			}else if(t_value < t_prev_value){
				if( !(DecrementHandler == NULL)){
				
					t_prev_value = t_value;
					(UI->*DecrementHandler)();
				}
			}
	
			//See if Buttons Clicked
			ClickEncoder::Button b = this->getButton();
			if (b != ClickEncoder::Open) {
				 switch (b) {
					 case(ClickEncoder::Pressed):
						 #if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
							 Serial.println(F("Encoder Pressed. No Action"));
							 Serial.flush();
						 #endif
						break;
					 case(ClickEncoder::Held):
						 #if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
							 Serial.println(F("Encoder Held. No Action"));
							 Serial.flush();
						 #endif
						break;
					 case(ClickEncoder::Released):
						#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
							 Serial.println(F("Encoder Released. No Action"));
							 Serial.flush();
						#endif
						break;
					 case(ClickEncoder::Clicked):
						#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>1)
							Serial.println(F("Encoder Click."));
							Serial.flush();
						#endif
						(UI->*ClickHandler)();
						break;
					 case (ClickEncoder::DoubleClicked):
							(UI->*DblClickHandler)();
						break;
				 }
			}
}
