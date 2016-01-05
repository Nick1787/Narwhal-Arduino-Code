/* 
* ClickEncoderWithEvents.h
*
* Created: 11/14/2015 5:06:22 PM
* Author: Customer
*/

#ifndef __CLICKENCODERWITHEVENTS_H__
#define __CLICKENCODERWITHEVENTS_H__

#include "../../include/ClickEncoder/ClickEncoder.h"
#include "LCDMenu.h"

class UserInterface; //Defines the class so it can be used.
class ClickEncoderWithEvents : public ClickEncoder
{
	//variables
	public:
		void Read(void);
		void ClearHandlers(void);
		UserInterface *UI;
		
		//Pulling in some ClickEncoder Methods to make them public scope
		using ClickEncoder::service;
		using ClickEncoder::Open;
		using ClickEncoder::Closed;
		using ClickEncoder::DoubleClicked;
		using ClickEncoder::Clicked;
		using ClickEncoder::Held;
		using ClickEncoder::Pressed;
		using ClickEncoder::getAccelerationEnabled;
		using ClickEncoder::setAccelerationEnabled;
		using ClickEncoder::getButton;
		using ClickEncoder::getDoubleClickEnabled;
		using ClickEncoder::setDoubleClickEnabled;
		using ClickEncoder::getValue;
		

		//Delegates
		typedef void (UserInterface::*UIEventHandler)(void);
		UIEventHandler ClickHandler = NULL;
		UIEventHandler DblClickHandler = NULL;
		UIEventHandler IncrementHandler = NULL;
		UIEventHandler DecrementHandler = NULL;
	
	protected:
	private:
		unsigned long persistance = 0;
		unsigned long prev_time = 0;
		int16_t t_prev_value = 0;
		int16_t t_value = 0;

	//functions
	public:
		ClickEncoderWithEvents(uint8_t A, uint8_t B, uint8_t SW) : ClickEncoder(A, B, SW ) {};
		ClickEncoderWithEvents(uint8_t A, uint8_t B, uint8_t SW, uint8_t DEGPERNOTCH) : ClickEncoder(A, B, SW, DEGPERNOTCH) {};
		ClickEncoderWithEvents(uint8_t A, uint8_t B, uint8_t SW, uint8_t DEGPERNOTCH, bool SWLOW ) : ClickEncoder(A, B, SW, DEGPERNOTCH, SWLOW) {};
		~ClickEncoderWithEvents();
	
	protected:
	private:
		//ClickEncoderWithEvents( const ClickEncoderWithEvents &c );
		//ClickEncoderWithEvents& operator=( const ClickEncoderWithEvents &c );

}; //ClickEncoderWithEvents

#endif //__CLICKENCODERWITHEVENTS_H__
