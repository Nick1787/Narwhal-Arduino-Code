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
#include "../EZUI.h"

//Forward Declarations
class EZUI;
class EZUI_Page;
class EZUI_Menu;
class DigitalIO;

//Generic Callback Function
template < class T() >
class BTNcallback
{
public:
	BTNcallback() :			object1(NULL), object2(NULL){}	// No Objects Used in Callback
	void execute() {(object.*F)();}	// launch callback function
private:
	T* Callback;
};

//Button Class
class EZUI_Control_Button : public EZUI_Control
{
//variables
public:	
protected:
private:
	char * _Label;
	BTNcallback * _Callback;
//functions
public:

	//Over-ridden base class functions
	boolean isSelectable() const  override {return true;};
	boolean hasValueText() const override { return false;};
	String LabelText(void) override{ return String(this->_Label); };
	void Select(EZUI *UI) const override {
		_Callback->execute();
	};
	
	//Default Destructor
	~EZUI_Control_Button() override {};	
		
	//void FollowButton(EZUI *UI) const;
	EZUI_Control_Button(char Text[]), BTNcallback * Callback): EZUI_Control(EZUI_ControlType::Button), _Label(Text), _Callback(Callback){};

protected:
private:

}; //EZUI_Control_Button

#endif //__EZUI_CONTROL_Button_H__
