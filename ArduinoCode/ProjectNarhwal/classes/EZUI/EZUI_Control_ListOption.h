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
class EZUI_Display;

class EZUI_Control_ListOption : public EZUI_Control
{
	//variables
	public:
	protected:
	private:
		const char* _Label;
		GenericListOption *_Ref;

	//functions
	public:

	//Over-ridden base classes
	boolean isSelectable() const  override;
	boolean hasValueText() const override;
	String LabelText() override;
	String ValueText() override;
	void Select(EZUI *UI) const override;
	
	~EZUI_Control_ListOption();
	
	//Constructors
	EZUI_Control_ListOption(char* Label, GenericListOption *ListRef): EZUI_Control(EZUI_ControlType::ListControl), _Label(Label), _Ref(ListRef){};
	
	protected:
	private:

}; 

#endif //_EZUI_CONTROL_LISTOPTION_H__
