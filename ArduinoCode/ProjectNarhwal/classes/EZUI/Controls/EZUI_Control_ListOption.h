/*
 * EZUI_Control_ListOption.c
 *
 * Created: 8/13/2016 9:41:30 AM
 *  Author: Customer
 */ 

#ifndef __EZUI_CONTROL_LISTOPTION_H__
#define __EZUI_CONTROL_LISTOPTION_H__

#include "../EZUI.h"
#include "../../EnhancedTypes/ListOption.h"
#include "EZUI_Control.h"

//Forward Declarations
class EZUI;

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
	//EZUI_Control_ToggleOption(char* _Label, ListOption * ObjRef): EZUI_Control(EZUI_ControlType::ListControl), _Label(_Label), _Ref(ObjRef){};
	EZUI_Control_ListOption(char* Label, GenericListOption *ListRef): EZUI_Control(EZUI_ControlType::ListControl), _Label(Label), _Ref(ListRef){};
	
	protected:
	private:

}; 

#endif //_EZUI_CONTROL_LISTOPTION_H__
