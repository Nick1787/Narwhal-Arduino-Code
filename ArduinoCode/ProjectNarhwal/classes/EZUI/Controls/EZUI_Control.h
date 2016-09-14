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
	enum EZUI_ControlType { None, Label, Link, ToggleControl, ListControl, AdjParam, Button};
	const EZUI_ControlType Type;
	
protected:
private:

//functions
public:
	virtual boolean isSelectable()  const { return false; };
	virtual boolean hasValueText()  const { return false; };
	virtual void Select(EZUI *UI) const { };
	virtual String LabelText()  { return "LabelText!"; };
	virtual String ValueText()  { return "ValueText!"; };
		
	//Default constructors / destructor
	constexpr EZUI_Control() : Type(EZUI_ControlType::None) {};
	constexpr EZUI_Control(EZUI_ControlType _Type) : Type(_Type) {};
	virtual ~EZUI_Control() {};
	
protected:
private:
	//EZUI_Control( const EZUI_Control &c );
	//virtual EZUI_Control& operator=( const EZUI_Control &c );

}; //EZUI_Control

#endif //__EZUI_CONTROL_H__
