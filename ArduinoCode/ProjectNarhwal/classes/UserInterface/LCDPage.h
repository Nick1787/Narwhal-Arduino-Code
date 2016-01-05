/* 
* LCDPage.h
*
* Created: 11/8/2015 9:05:23 PM
* Author: Customer
*/


#ifndef __LCDPAGE_H__
#define __LCDPAGE_H__

#include "../../include/LinkedList/LinkedList.h"
#include "../../include/LiquidCrystal/LiquidCrystal_I2C.h"
#include "LCDPageItem.h"
#include "LCDMenuItem.h"
#include "UserInterface.h"

class LCDPageItem;
class UserInterface;
class LCDPage
{
//variables
public:
	int refreshRate = 1000;	//refresh rate in ms (default 1000ms)
	String Name = "";
	LinkedList<LCDPageItem> Items = LinkedList<LCDPageItem>();
	
protected:
private:
	unsigned long lastUpdate = 0;

//functions
public:
	LCDPage();
	LCDPage(String _Name);
	~LCDPage();
	void display(UserInterface *UI);
	
protected:
private:
	//LCDPage( const LCDPage &c );
	//LCDPage& operator=( const LCDPage &c );

}; //LCDPage

#endif //__LCDPAGE_H__
