/* 
* LCDMenuItem.cpp
*
* Created: 11/8/2015 11:05:00 AM
* Author: Customer
*/


#include "../include/LiquidCrystal/LiquidCrystal_I2C.h"
#include "LCDMenuItem.h"

// default constructor
LCDMenuItem::LCDMenuItem()
{
	Name = "XXX";
}

LCDMenuItem::LCDMenuItem(String _Name)
{
	Name = _Name;
} 

// default destructor
LCDMenuItem::~LCDMenuItem()
{
}

//Print
void LCDMenuItem::LCDprint( LiquidCrystal_I2C *LCD){
	LCD->print("  " + Name);
}
