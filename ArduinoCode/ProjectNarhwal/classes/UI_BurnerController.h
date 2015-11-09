/*
 *        File: UI_BurnerController.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Class Code for high level class for a burner controller LCD
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "WheatstoneBridge.h"
#include "LCDMenu.h"
#include "LCDMenuItem.h"
#include "../include/ClickEncoder/ClickEncoder.h"
#include "../include/LiquidCrystal/LiquidCrystal_I2C.h"

#ifndef UI_BurnerController_H_
#define UI_BurnerController_H_

class UI_BurnerController{
	
	private:
		LCDMenu *MainMenu;
		
	public:
		//Properties
		String Name = "";
		
		//Temperature Probes
		WheatstoneBridge *FeedbackProbe1 = NULL;
		WheatstoneBridge *FeedbackProbe2 = NULL;
		
		//User Interaction
		LiquidCrystal_I2C *LCD;
		ClickEncoder *Encoder;
		void display();
		//void displayMenu();
		
		UI_BurnerController(String _Name, LiquidCrystal_I2C *_LCD, ClickEncoder *_Encoder);
		~UI_BurnerController();
		
	
};



#endif /* UI_BurnerController_H_ */