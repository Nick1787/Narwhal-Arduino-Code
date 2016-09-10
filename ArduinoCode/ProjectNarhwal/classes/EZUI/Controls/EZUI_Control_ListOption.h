/*
 * EZUI_Control_ListOption.c
 *
 * Created: 8/13/2016 9:41:30 AM
 *  Author: Customer
 */ 

#ifndef __EZUI_CONTROL_LISTOPTION_H__
#define __EZUI_CONTROL_LISTOPTION_H__

class EZUI_Control_ListOption : public EZUI_Control
{
	//variables
	public:
	protected:
	private:
		const char* _Label;
		ListOption * _Ref = NULL;

	//functions
	public:

	//Over-ridden base classes
	boolean isSelectable() const  override {return true;};
	boolean hasValueText() const override {return true;};
	String LabelText() override {return _Label;};
	String ValueText() override { return _Ref->ItemText(_Ref->currentValue()); };
	void Select(EZUI *UI) const override {
		
	};
	
	~EZUI_Control_ListOption(){};
	
	//Constructors
	EZUI_Control_ToggleOption(char* _Label, ListOption * ObjRef): EZUI_Control(EZUI_ControlType::ListControl), _Label(_Label), _Ref(ObjRef){};
	
	protected:
	private:

}; 

#endif //_EZUI_CONTROL_LISTOPTION_H__
