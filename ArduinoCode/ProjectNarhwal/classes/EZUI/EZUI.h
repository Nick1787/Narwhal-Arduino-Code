/*
 *        File: EZUI.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "../../include/LiquidCrystal/LiquidCrystal_I2C.h"
#include "../WheatstoneBridge.h"
#include "./EZUI_Display.h"
#include "./ClickEncoderWithEvents.h"
#include "./Controls/EZUI_Control.h"

#ifndef __EZUI_H_
#define __EZUI_H_

#ifndef A
	#define A(x)  x,((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
#endif

class ClickEncoderWithEvents;
class EZUI_Display;
class EZUI{
	
	private:
		unsigned long lastDisplayMillis;
		
	public:	
		EZUI_Display *CurrentDisplay = NULL;
		
		//User Interaction
		LiquidCrystal_I2C *LCD;
		ClickEncoderWithEvents *Encoder;
		
		void attatchEncoder(ClickEncoderWithEvents* _Encoder);
		void attatchLCD(LiquidCrystal_I2C* _LCD){LCD = _LCD;};
		
		//LCD Menu Interactions
		void EncoderClick();
		void EncoderDblClick();
		void EncoderPress();
		void EncoderHeld();
		void EncoderIncrement();
		void EncoderDecrement();
		void display();
		void refresh();
		void setDisplay(EZUI_Display *Disp);
			
		~EZUI(){};
};



#endif /* USERINTERFACE_H_ */