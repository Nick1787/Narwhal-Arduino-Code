/*
 *        File: EZUI_Control_Button.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - Button Control
 *			- Buttons have void(void) callback functions
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#ifndef __EZUI_CONTROL_Button_H__
#define __EZUI_CONTROL_Button_H__

//Includes
#include "EZUI_Control.h"

//Forward Declarations
class EZUI;
class EZUI_Display;

//Button Class
class EZUI_Control_Button : public EZUI_Control
{
//variables
public:	
protected:
private:
	char * _Label;
	
//functions
public:

	//Over-ridden base class functions
	boolean isSelectable() const  override {return true;};
	boolean hasValueText() const override { return false;};
	String LabelText(void) override{ return String(this->_Label); };
	void Select(EZUI *UI) const override {
		
	};
	
	//Default Destructor
	~EZUI_Control_Button() {};	
		
	//void FollowButton(EZUI *UI) const;
	EZUI_Control_Button(char Text[]): EZUI_Control(EZUI_ControlType::Button), _Label(Text){};

protected:
private:

}; //EZUI_Control_Button

#endif //__EZUI_CONTROL_Button_H__
