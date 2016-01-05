/* 
* LCDPage.cpp
*
* Created: 11/8/2015 9:05:22 PM
* Author: Customer
*/


#include "LCDPage.h"

// default constructor
LCDPage::LCDPage()
{
} //LCDPage

// constructor with name passed
LCDPage::LCDPage(String _Name)
{
	Name = _Name;
}

// default destructor
LCDPage::~LCDPage()
{
} //~LCDPage

void LCDPage::display(UserInterface *UI){
	if((millis() - lastUpdate)>refreshRate){
		lastUpdate = millis();
		
		LiquidCrystal_I2C *LCD = UI->LCD;
		LCD->clear();
		for(int i=0; i<Items.size(); i++){
			Items.get(i).print(LCD);
		}
	}
}