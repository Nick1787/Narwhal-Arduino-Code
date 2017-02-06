/*
 *        File: EZUI_Control.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - Control Base Class
 */

#ifndef __EZUI_CONTROL_H__
#define __EZUI_CONTROL_H__

//Includes
#include <Arduino.h>
#include "AdjustableParam.h"
#include "DigitalIO.h"
#include "ListOption.h"

//Forward Declrartion
class EZUI;
class EZUI_Display;

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
	//Virtual Functions
	virtual boolean isSelectable()  const;
	virtual boolean hasValueText()  const;
	virtual void Select(EZUI *UI) const;
	virtual String LabelText();
	virtual String ValueText();
		
	//Default constructors / destructor
	EZUI_Control() : Type(EZUI_ControlType::None){};
	EZUI_Control(EZUI_ControlType _Type) : Type(_Type){};
	~EZUI_Control();
	
protected:
private:
	//EZUI_Control( const EZUI_Control &c );
	//virtual EZUI_Control& operator=( const EZUI_Control &c );

}; //EZUI_Control

#endif //__EZUI_CONTROL_H__
