/*
 *        File: EZUI.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */


#ifndef __EZUI_H_
#define __EZUI_H_

//Hardware Includes
#include "../../include/LiquidCrystal/LiquidCrystal_I2C.h"
#include "./ClickEncoderWithEvents.h"

//Type Includes
#include "../EnhancedTypes/ListOption.h"
#include "../EnhancedTypes/AdjustableParam.h"

#ifndef A
	#define A(x)  x,((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
#endif

//Forward Declaration
class EZUI_Display;
class EZUI_ListOptionEditor;
class ClickEncoderWithEvents;
class EZUI_Control_ListOption;

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
			
		//Functions
		void EditListOption(GenericListOption * ListOptRef);
		void EditAdjustParam(AdjustableParam * ParamRef);
		
		~EZUI(){};
};



#endif /* USERINTERFACE_H_ */