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
#include "EZUI_Menu.h"
#include "EZUI_Page.h"
#include "./Controls/EZUI_Control.h"
#include "./Controls/EZUI_Control_Button.h"
#include "./Controls/EZUI_Control_Link.h"
#include "./Controls/EZUI_Control_Label.h"
#include "./Controls/EZUI_Control_ListOption.h"
#include "./Controls/EZUI_Control_ToggleOption.h"
#include "ClickEncoderWithEvents.h"

#ifndef __EZUI_H_
#define __EZUI_H_

#ifndef A
	#define A(x)  x,((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
#endif

class EZUI_Menu;
class EZUI_Page;
class ClickEncoderWithEvents;
class EZUI{
	
	private:
		EZUI_Menu *CurrentMenu = NULL;
		EZUI_Page *CurrentPage = NULL;
		
	public:		
		//Temperature Probes
		WheatstoneBridge *FeedbackProbe1 = NULL;
		WheatstoneBridge *FeedbackProbe2 = NULL;
		
		//User Interaction
		LiquidCrystal_I2C *LCD;
		ClickEncoderWithEvents *Encoder;
		void attatchEncoder(ClickEncoderWithEvents*);
		void attatchLCD(LiquidCrystal_I2C*);
		
		//LCD Menu Interactions
		void EncoderClick();
		void EncoderDblClick();
		void EncoderPress();
		void EncoderHeld();
		void EncoderIncrement();
		void EncoderDecrement();
		
		void display();
		void refresh();
		unsigned long lastDisplayMillis;
		
		void setDisplay(EZUI_Page *Page);
		void setDisplay(EZUI_Menu *Menu);
		
		EZUI();
		~EZUI();
};



#endif /* USERINTERFACE_H_ */