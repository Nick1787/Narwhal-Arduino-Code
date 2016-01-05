/*
 *        File: UI_BurnerController.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Class Code for high level class for a burner controller LCD
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_

#include "../../include/LiquidCrystal/LiquidCrystal_I2C.h"
#include "../WheatstoneBridge.h"
#include "LCDMenu.h"
#include "LCDMenuItem.h"
#include "LCDPage.h"
#include "ClickEncoderWithEvents.h"

class LCDMenu;
class LCDPage;
class ClickEncoderWithEvents;
class UserInterface{
	
	private:
		LCDMenu *CurrentMenu = NULL;
		LCDPage *CurrentPage = NULL;
		
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
		
		void setDisplay(LCDPage *Page);
		void setDisplay(LCDMenu *Menu);
		
		UserInterface(String _Name);
		~UserInterface();
};



#endif /* USERINTERFACE_H_ */