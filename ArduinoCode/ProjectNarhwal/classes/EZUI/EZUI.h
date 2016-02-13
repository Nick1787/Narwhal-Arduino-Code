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

#include "../../include/LiquidCrystal/LiquidCrystal_I2C.h"
#include "../WheatstoneBridge.h"
#include "EZUI_Menu.h"
#include "EZUI_MenuItem.h"
#include "EZUI_Page.h"
#include "ClickEncoderWithEvents.h"

class EZUI_Menu;
class EZUI_Page;
class ClickEncoderWithEvents;
class EZUI{
	
	private:
		EZUI_Menu *CurrentMenu = NULL;
		EZUI_Page *CurrentPage = NULL;
		
	public:
		//Properties
		String Name = "";
		
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
		unsigned long lastDisplayMillis;
		
		void setDisplay(EZUI_Page *Page);
		void setDisplay(EZUI_Menu *Menu);
		
		EZUI(String _Name);
		~EZUI();
};



#endif /* USERINTERFACE_H_ */