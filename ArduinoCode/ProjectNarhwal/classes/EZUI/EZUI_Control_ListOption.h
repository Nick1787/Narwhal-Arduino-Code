/*
 *        File: EZUI_Control_ListOption.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - List Option
 *			- Control for interacting with a Toggle Option
 */

#ifndef __EZUI_CONTROL_LISTOPTION_H__
#define __EZUI_CONTROL_LISTOPTION_H__

//Includes
#include "EZUI_Control.h"

//Forward Declarations
class EZUI;
class EZUI_UI;

class EZUI_Control_ListOption : public EZUI_Control
{
	//variables
	public:
	protected:
	private:
		boolean isFlash;
		const PROGMEM void * _Label;
		GenericListOption PROGMEM *_Ref;

	//functions
	public:

	//Over-ridden base classes
	boolean isSelectable() const  override;
	boolean hasValueText() const override;
	const char* LabelText() override;
	const char* ValueText() override;
	void Select(EZUI *UI) const override;
	
	~EZUI_Control_ListOption();
	
	//Constructors
	EZUI_Control_ListOption(const char* Label, GenericListOption ListRef[]): EZUI_Control(EZUI_ControlType::ListControl), _Label(Label), isFlash(false), _Ref(ListRef){};
	EZUI_Control_ListOption(const __FlashStringHelper * Label, GenericListOption ListRef[]): EZUI_Control(EZUI_ControlType::ListControl), isFlash(true), _Label(Label), _Ref(ListRef){};
	
	protected:
	private:

}; 

#endif //_EZUI_CONTROL_LISTOPTION_H__
