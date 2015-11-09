/*
 *        File: UI_BurnerController.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Class code for high level class for a burner controller LCD
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "LCDMenu.h"
#include "LCDMenuItem.h"
#include "UI_BurnerController.h"

UI_BurnerController::UI_BurnerController(String _Name, LiquidCrystal_I2C *_LCD, ClickEncoder *_Encoder){
	Name = _Name;
	LCD = _LCD;
	Encoder = _Encoder;
	
	MainMenu = new LCDMenu("Main Menu");
	LCDMenuItem * MenuItem1 = new LCDMenuItem("Monitor");
	MainMenu->Items.add(*MenuItem1);
	LCDMenuItem * MenuItem2 = new LCDMenuItem("Settings");
	MainMenu->Items.add(*MenuItem2);
	LCDMenuItem * MenuItem3 = new LCDMenuItem("Diagnostics");
	MainMenu->Items.add(*MenuItem3);
	Serial.println("AddedMenu");
}

UI_BurnerController::~UI_BurnerController(){
}

void UI_BurnerController::display(){
	
	Serial.println("DisplayigMenu");
	MainMenu->display(LCD);
	Serial.println("MenuDisplayed");
}