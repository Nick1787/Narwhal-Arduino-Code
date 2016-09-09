/* 
* EZUI_Control.h
*
* Created: 5/20/2016 6:24:34 PM
* Author: Customer
*/

#ifndef __EZUI_CONTROL_H__
#define __EZUI_CONTROL_H__

//Includes
#include <Arduino.h>

//Forward Declarations
class EZUI;

	
class EZUI_Control
{
//variables
public:
	enum ControlType { None, Label, Link, ToggleOpt};
	ControlType Type = None;
	
protected:
private:

//functions
public:
	virtual boolean isSelectable()  const { return false; };
	virtual void Select(EZUI *UI) const { };
	virtual String Text() const  { return "ControlText!"; };
	EZUI_Control();
	virtual ~EZUI_Control();
	
protected:
private:
	//EZUI_Control( const EZUI_Control &c );
	//virtual EZUI_Control& operator=( const EZUI_Control &c );

}; //EZUI_Control

#endif //__EZUI_CONTROL_H__
