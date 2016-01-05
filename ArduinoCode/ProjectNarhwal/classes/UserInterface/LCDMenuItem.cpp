/* 
* LCDMenuItem.cpp
*
* Created: 11/8/2015 11:05:00 AM
* Author: Customer
*/

#include "LCDMenuItem.h"

//Constructor - No Action
LCDMenuItem::LCDMenuItem(String _Name)
{
	Name = _Name;
	Type = None;
}

//Constructor - LCD Menu
LCDMenuItem::LCDMenuItem(String _Name, LCDMenu * _Menu)
{
	Name = _Name;
	MenuRef = _Menu;
	Type = SubMenu;
} 

//Constructor - LCD Page
LCDMenuItem::LCDMenuItem(String _Name, LCDPage * _Page)
{
	Name = _Name;
	PageRef = _Page;
	Type = SubPage;
}

//Constructor - LCD Page
LCDMenuItem::LCDMenuItem(String _Name, LCDToggleOption * _ToggleOpt)
{
	Name = _Name;
	ToggleOptRef = _ToggleOpt;
	Type = ToggleOption;
}

// default constructor
LCDMenuItem::LCDMenuItem()
{
}

// default destructor
LCDMenuItem::~LCDMenuItem()
{
}

//Print
void LCDMenuItem::Print(int _col, int _rw, UserInterface *UI ){
	
	LiquidCrystal_I2C *LCD = UI->LCD;
	LCD->setCursor(_col, _rw);
	LCD->print(Name);
	
	if(Type == ToggleOption){
		LCDToggleOption TglOpt = *ToggleOptRef;
		
		String TrueLabel = TglOpt.TrueLabel();
		int TrueTextLen = TrueLabel.length();
		String FalseLabel = TglOpt.FalseLabel();
		int FalseTextLen = FalseLabel.length();
		
		//Set Cursor Position
		if(TrueTextLen>FalseTextLen){
			LCD->setCursor(20-TrueTextLen-1,_rw);
		}else{
			LCD->setCursor(20-FalseTextLen-1,_rw);	
		}
		
		//Print current value
		if(TglOpt.Value() == 1){
			LCD->print(TrueLabel);
		}else{
			LCD->print(FalseLabel);
		}
	}
}

//Item Select
void LCDMenuItem::ItemSelect(UserInterface *UI){
	 switch (Type) {
		case(SubMenu):
			if (MenuRef == NULL){
				UI->LCD->clear();
				UI->LCD->println("Error!");
				UI->LCD->println("Selected Menu item null");
				delay(3000);
				UI->display();
			}else{
				UI->setDisplay(MenuRef);
			}
			break;
		case(SubPage):
			if (PageRef == NULL){
				UI->LCD->clear();
				UI->LCD->println("Error!");
				UI->LCD->println("Selected Menu item null");
				delay(3000);
				UI->display();
			}else{
				UI->setDisplay(PageRef);
			}
			break;
		case(ToggleOption):
			(*ToggleOptRef).Toggle();
			UI->display();
			break;
		default:
			UI->LCD->clear();
			UI->LCD->println("ERROR!:");
			UI->LCD->println("  Menu Type not yet Supported");
			delay(3000);
			UI->display();
			break;
	}
}
