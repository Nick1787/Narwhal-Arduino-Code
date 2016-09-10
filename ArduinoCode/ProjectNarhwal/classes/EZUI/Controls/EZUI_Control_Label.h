/*
 *        File: EZUI_Control_Label.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - Label Control
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#ifndef __EZUI_CONTROL_LABEL_H__
#define __EZUI_CONTROL_LABEL_H__

//Includes
#include "EZUI_Control.h"
#include "../EZUI.h"
#include "../../EnhancedTypes/ListOption.h"

class EZUI_Control_Label : public EZUI_Control
{
//variables
public:	
protected:
private:
	//what type of variable are we displaying
	enum EZUI_Control_Label_Type {None, LblCharArr, LblCCharArr, LblFloat, LblDouble, LblInt, LblUInt, LblLong, LblULong, LblBoolWithText, LblDigitalIO, LblListOpt};
	const PROGMEM EZUI_Control_Label_Type _Label_Type;	//Not initialized to any value

	//Pointers to the items
	const PROGMEM void * _ItemRef;
	const PROGMEM char * _blnTrueTxt;
	const PROGMEM char * _blnFalseTxt;
	
//functions
public:

	//Over-ridden base class functions
	boolean isSelectable() const override { return false; };
	boolean hasValueText() const override { return false; };
	void Select(EZUI *UI) const override { /* Do nothing */ };
	String LabelText(void) override {
		String Str = "";
		switch(this->_Label_Type){
			case(LblCharArr):
				Str = String((char*)this->_ItemRef);
				break;
			case(LblCCharArr):
				Str = String((char*)this->_ItemRef);
				break;
			case(LblFloat):
				Str = String(*(float*)(this->_ItemRef));
				break;
			case(LblDouble):
				Str = String(*(double*)(this->_ItemRef));
				break;
			case(LblInt):
				Str = String(*(int*)(this->_ItemRef));
				break;
			case(LblUInt):
				Str = String(*(unsigned int*)(this->_ItemRef));
				break;
			case(LblLong):
				Str = String(*(long*)(this->_ItemRef));
				break;
			case(LblULong):
				Str = String(*(unsigned long*)(this->_ItemRef));
				break;
			case(LblBoolWithText):{
				boolean val = *(bool*)(this->_ItemRef);
				if(val){
					Str = _blnTrueTxt;
				}else{
					Str = _blnFalseTxt;
				}
				break;
			}
			case(LblDigitalIO):{
				DigitalIO val = *(DigitalIO*)(this->_ItemRef);
				if(val.Value()){
					Str= val.TrueLabel;
					}else{
					Str = val.FalseLabel;
				}
				break;
			}
			case(LblListOpt):{
				//ListOption lObj = *(ListOption*)(this->ItemRef);
				//int listval = lObj.currentValue();
				//Str = lObj.ItemText(listval);
				break;
			}
		}
		return Str;
	};
	
	//Destructor
	~EZUI_Control_Label() override {};
		
	//Constructors - Static Values
	EZUI_Control_Label(const char val[]):	EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblCCharArr), _ItemRef(val){};
	EZUI_Control_Label(char val[]):			EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblCharArr), _ItemRef(val){};
	
	//Constructors - Dynamic Values
	EZUI_Control_Label(float *val):			EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblFloat), _ItemRef(val){};
	EZUI_Control_Label(double *val):		EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblDouble), _ItemRef(val){};
	EZUI_Control_Label(int *val):			EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblInt), _ItemRef(val){};
	EZUI_Control_Label(unsigned int *val):	EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblUInt), _ItemRef(val){};
	EZUI_Control_Label(long *val):			EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblLong), _ItemRef(val){};
	EZUI_Control_Label(unsigned long *val): EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblULong), _ItemRef(val){};
	EZUI_Control_Label(boolean *val, String TrueText, String FalseText): EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblBoolWithText), _ItemRef(val), _blnTrueTxt(TrueText.c_str()), _blnFalseTxt(FalseText.c_str()){};
	EZUI_Control_Label(boolean *val, char TrueText[], char FalseText[]): EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblBoolWithText), _ItemRef(val), _blnTrueTxt(TrueText), _blnFalseTxt(FalseText){};
	EZUI_Control_Label(boolean *val):		EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblBoolWithText), _ItemRef(val), _blnTrueTxt("1"), _blnFalseTxt("0"){};
	EZUI_Control_Label(DigitalIO *val):		EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblDigitalIO), _ItemRef(val){};
	
	template<typename T>
	EZUI_Control_Label(ListOption<T> *val):	EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblListOpt), _ItemRef(val){};
	
protected:
private:

}; //EZUI_Control_Lablel

#endif //__EZUI_CONTROL_LABLEL_H__
