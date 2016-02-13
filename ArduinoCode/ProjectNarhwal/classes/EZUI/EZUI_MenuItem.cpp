/*
 *        File: EZUI_MenuItem.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Menu Class
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#include "EZUI_MenuItem.h"

//Constructor - LCD Page
EZUI_MenuItem::EZUI_MenuItem(EZUI_Control_Link * Link)
{
	this->LinkRef = Link;
	this->Type = LinkControl;
}

//Constructor - LCD Page
EZUI_MenuItem::EZUI_MenuItem(EZUI_Control_ToggleOption * ToggleOpt)
{
	this->ToggleOptRef = ToggleOpt;
	this->Type = ToggleOptionControl;
}

// default constructor
EZUI_MenuItem::EZUI_MenuItem()
{
}

// default destructor
EZUI_MenuItem::~EZUI_MenuItem()
{
}

//Print
void EZUI_MenuItem::Print(int col, int row, EZUI *UI){
	LiquidCrystal_I2C * LCD = UI->LCD;
	switch(this->Type){
		//Print Toggle Option
		case(ToggleOptionControl):
			if (!(ToggleOptRef == NULL)){
				EZUI_Control_ToggleOption TglOpt = *ToggleOptRef;
				LCD->setCursor(col,row);
				LCD->print(TglOpt.Label);
			
				String TrueLabel = TglOpt.TrueLabel();
				int TrueTextLen = TrueLabel.length();
				String FalseLabel = TglOpt.FalseLabel();
				int FalseTextLen = FalseLabel.length();
			
				//Set Cursor Position
				int display_width = 20;
				if(TrueTextLen>FalseTextLen){
					int StartPos = display_width-TrueTextLen - 1;
					LCD->setCursor(StartPos,row);
					
					//Print spaces to clear the label
					int i=0;
					for(i=StartPos; i<=display_width; i++){
						LCD->print(" ");
					}
					LCD->setCursor(StartPos,row);
				}else{
					int StartPos = display_width-FalseTextLen - 1;
					LCD->setCursor(StartPos,row);
				
					//Print spaces to clear the label
					int i=0;
					for(i=StartPos; i<=display_width; i++){
						LCD->print(" ");
					}
					LCD->setCursor(StartPos,row);
				}
			
				//Print current value
				if(TglOpt.Value() == 1){
					LCD->print(TrueLabel);
				}else{
					LCD->print(FalseLabel);
				}
			}
			break;
			
		//Print Link Control
		case(LinkControl):
			if(!(LinkRef == NULL)){
				LCD->setCursor(col,row);
				LCD->print((*LinkRef).Label);
			}
			break;
	}
}

//Item Select
void EZUI_MenuItem::ItemSelect(EZUI *UI){
	 switch (Type) {
		case(LinkControl):
			if (LinkRef == NULL){
				UI->LCD->clear();
				UI->LCD->println("Error!");
				UI->LCD->println("Selected Menu item null");
				delay(3000);
				UI->display();
			}else{
				LinkRef->FollowLink(UI);
			}
			break;
		case(ToggleOptionControl):
			(*ToggleOptRef).Toggle();
			UI->display();
			break;
		default:
			UI->LCD->clear();
			UI->LCD->println("ERROR!:");
			UI->LCD->println("Menu Type not yet Supported");
			delay(3000);
			UI->display();
			break;
	}
}
