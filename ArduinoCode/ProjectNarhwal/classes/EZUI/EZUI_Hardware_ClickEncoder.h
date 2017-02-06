/* 
* ClickEncoderWithEvents.h
*
* Created: 11/14/2015 5:06:22 PM
* Author: Customer
*/

#ifndef __EZUI_HARDWARE_CLICKENCODER_H__
#define __EZUI_HARDWARE_CLICKENCODER_H__

#include <EZUI.h>
#include <ClickEncoder.h>

//Forward Declaration
class EZUI;

class EZUI_ClickEncoder : public ClickEncoder
{
	//variables
	public:
		void Read(void);
		void ClearHandlers(void);
		EZUI *UI;
		
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
		typedef void (EZUI::*UIEventHandler)(void);
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
		EZUI_ClickEncoder(uint8_t A, uint8_t B, uint8_t SW) : ClickEncoder(A, B, SW ) {};
		EZUI_ClickEncoder(uint8_t A, uint8_t B, uint8_t SW, uint8_t DEGPERNOTCH) : ClickEncoder(A, B, SW, DEGPERNOTCH) {};
		EZUI_ClickEncoder(uint8_t A, uint8_t B, uint8_t SW, uint8_t DEGPERNOTCH, bool SWLOW ) : ClickEncoder(A, B, SW, DEGPERNOTCH, SWLOW) {};
		~EZUI_ClickEncoder();
	
	protected:
	private:
		//ClickEncoderWithEvents( const ClickEncoderWithEvents &c );
		//ClickEncoderWithEvents& operator=( const ClickEncoderWithEvents &c );

}; //ClickEncoderWithEvents

#endif //__EZUI_HARDWARE_CLICKENCODER_H__
