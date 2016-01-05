/* 
* ClickEncoderWithEvents.cpp
*
* Created: 11/14/2015 5:06:21 PM
* Author: Customer
*/


#include "ClickEncoderWithEvents.h"

// default destructor
ClickEncoderWithEvents::~ClickEncoderWithEvents()
{
} //~ClickEncoderWithEvents

void ClickEncoderWithEvents::Read(){
	//service();

	//value += this->getValue();
	
	//if (value != last) {
	//	last = value;
	//	Serial.print("Encoder Value: ");
	//	Serial.println(value);
	//}
	
			//See if Incremented or not
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
						break;
					 case(ClickEncoder::Held):
						break;
					 case(ClickEncoder::Released):
						break;
					 case(ClickEncoder::Clicked):
						if (!(ClickHandler == NULL)){
							(UI->*ClickHandler)();
					}
					break;
					 case (ClickEncoder::DoubleClicked):
						if (!(DblClickHandler == NULL)){
							(UI->*DblClickHandler)();
						}
						break;
				 }
			}
}

//void ClickEncoderWithEvents::ClearHandlers(){
	//ClickHandler = NULL;
	//DblClickHandler = NULL;
	//IncrementHandler = NULL;
	//DecrementHandler = NULL;
//}
