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

//Standard
#include <Arduino.h>

//Hardware Includes
#include <LiquidCrystal_I2C.h>
#include "EZUI_Hardware_ClickEncoder.h"

//Types
#include "EZUI_Display.h"
#include "ListOption.h"
#include "AdjustableParam.h"
#include "DigitalIO.h"

//Controls
#include "EZUI_Control.h"
#include "EZUI_Control_AdjustParam.h"
#include "EZUI_Control_Button.h"
#include "EZUI_Control_Label.h"
#include "EZUI_Control_Link.h"
#include "EZUI_Control_ListOption.h"
#include "EZUI_Control_ToggleOption.h"

// number of items in an array
template< typename T, size_t N > size_t ArraySize (T (&) [N]){ return N; }
	
#ifndef A
	#define A(x)  x,ArraySize(x)
#endif

template <typename T> void PROGMEM_readAnything (const T * sce, T& dest)
{
	memcpy_P (&dest, sce, sizeof (T));
}

template <typename T> T PROGMEM_getAnything (const T * sce)
{
	static T temp;
	memcpy_P (&temp, sce, sizeof (T));
	return temp;
}

//Forward Declaration
class EZUI_Display;
class EZUI_ListOptionEditor;
class EZUI_ClickEncoder;
class EZUI_Control_ListOption;

class EZUI{
	
	private:
		unsigned long lastDisplayMillis;
		
	public:	
		EZUI_Display *CurrentDisplay = NULL;
		
		//User Interaction
		LiquidCrystal_I2C *LCD;
		EZUI_ClickEncoder *Encoder;
		
		void attatchEncoder(EZUI_ClickEncoder* _Encoder);
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