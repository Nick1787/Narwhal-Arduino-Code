/*
 *        File: EZUI_Control_Label.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - Label Control
 */

#ifndef __EZUI_CONTROL_LABEL_H__
#define __EZUI_CONTROL_LABEL_H__

//Includes
#include "EZUI_Control.h"

//Forward Declarations
class EZUI;
class EZUI_UI;

class EZUI_Control_Label : public EZUI_Control
{
//variables
public:	
protected:
private:
	boolean _isFlash;
	const void * _Label;
	
	//what type of variable are we displaying
	enum EZUI_Control_Label_Type {None, LblCharArr, LblCCharArr, LblFloat, LblDouble, LblInt, LblUInt, LblLong, LblULong, LblBoolWithText, LblDigitalIO, LblListOpt, LblListOptRef, LblAdjParam, LblStr};
	const PROGMEM EZUI_Control_Label_Type _Label_Type;	//Not initialized to any value

	//Pointers to the items
	const PROGMEM void * _ItemRef;
	const PROGMEM void * _blnTrueTxt;
	const PROGMEM void * _blnFalseTxt;
	
//functions
public:

	//Over-ridden base class functions
	boolean isSelectable() const override;
	boolean hasValueText() const override;
	void Select(EZUI *UI) const override;
	const char* LabelText(void) override;
	const char* ValueText(void) override;
	
	//Destructor
	~EZUI_Control_Label() {};
		
	//Constructors - No Labels
	EZUI_Control_Label(const char * val):	_Label(""), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblCCharArr), _ItemRef(val){};
	EZUI_Control_Label(char * val):			_Label(""), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblCharArr), _ItemRef(val){};
	EZUI_Control_Label(float *val):			_Label(""), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblFloat), _ItemRef(val){};
	EZUI_Control_Label(double *val):		_Label(""), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblDouble), _ItemRef(val){};
	EZUI_Control_Label(int *val):			_Label(""), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblInt), _ItemRef(val){};
	EZUI_Control_Label(unsigned int *val):	_Label(""), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblUInt), _ItemRef(val){};
	EZUI_Control_Label(long *val):			_Label(""), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblLong), _ItemRef(val){};
	EZUI_Control_Label(unsigned long *val): _Label(""), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblULong), _ItemRef(val){};
	EZUI_Control_Label(String *val): _Label(""), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblStr), _ItemRef(val){};
	EZUI_Control_Label(boolean *val, String TrueText, String FalseText): _Label(""), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblBoolWithText), _ItemRef(val), _blnTrueTxt(TrueText.c_str()), _blnFalseTxt(FalseText.c_str()){};
	EZUI_Control_Label(boolean *val, char TrueText[], char FalseText[]): _Label(""), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblBoolWithText), _ItemRef(val), _blnTrueTxt(TrueText), _blnFalseTxt(FalseText){};
	EZUI_Control_Label(boolean *val):		_Label(""), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblBoolWithText), _ItemRef(val), _blnTrueTxt("1"), _blnFalseTxt("0"){};
	EZUI_Control_Label(DigitalIO *val):		_Label(""), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblDigitalIO), _ItemRef(val){};
	EZUI_Control_Label(GenericListOption *val):	_Label(""), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblListOpt), _ItemRef(val){};
	EZUI_Control_Label(AdjustableParam *val):	_Label(""), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblAdjParam), _ItemRef(val){};
	
	//Constructors - With Labels
	EZUI_Control_Label(const char* Label, const char * val):	_Label(Label), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblCCharArr), _ItemRef(val){};
	EZUI_Control_Label(const char* Label, char * val):			_Label(Label), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblCharArr), _ItemRef(val){};
	EZUI_Control_Label(const char* Label, float *val):			_Label(Label), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblFloat), _ItemRef(val){};
	EZUI_Control_Label(const char* Label, double *val):			_Label(Label), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblDouble), _ItemRef(val){};
	EZUI_Control_Label(const char* Label, int *val):			_Label(Label), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblInt), _ItemRef(val){};
	EZUI_Control_Label(const char* Label, unsigned int *val):	_Label(Label), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblUInt), _ItemRef(val){};
	EZUI_Control_Label(const char* Label, long *val):			_Label(Label), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblLong), _ItemRef(val){};
	EZUI_Control_Label(const char* Label, unsigned long *val): 	_Label(Label), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblULong), _ItemRef(val){};
	EZUI_Control_Label(const char* Label, String *val): 	_Label(Label), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblStr), _ItemRef(val){};
	EZUI_Control_Label(const char* Label, boolean *val, String TrueText, String FalseText): _Label(Label), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblBoolWithText), _ItemRef(val), _blnTrueTxt(TrueText.c_str()), _blnFalseTxt(FalseText.c_str()){};
	EZUI_Control_Label(const char* Label, boolean *val, char TrueText[], char FalseText[]): _Label(Label), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblBoolWithText), _ItemRef(val), _blnTrueTxt(TrueText), _blnFalseTxt(FalseText){};
	EZUI_Control_Label(const char* Label, boolean *val):		_Label(Label), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblBoolWithText), _ItemRef(val), _blnTrueTxt("1"), _blnFalseTxt("0"){};
	EZUI_Control_Label(const char* Label, DigitalIO *val):		_Label(Label), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblDigitalIO), _ItemRef(val){};
	EZUI_Control_Label(const char* Label, GenericListOption *val):	_Label(Label), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblListOpt), _ItemRef(val){};
	EZUI_Control_Label(const char* Label, AdjustableParam *val):	_Label(Label), _isFlash(false), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblAdjParam), _ItemRef(val){};
	
	//Constructors - No Labels - Flash memory
	EZUI_Control_Label(boolean *val, __FlashStringHelper* TrueText, __FlashStringHelper* FalseText): _Label(F("")), _isFlash(true), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblBoolWithText), _ItemRef(val), _blnTrueTxt(TrueText), _blnFalseTxt(FalseText){};
	
	//Constructors - With Labels - Flash Memory
	EZUI_Control_Label(const __FlashStringHelper* val):	_Label(val), _isFlash(true), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblCCharArr), _ItemRef(F("")){};
	EZUI_Control_Label(const __FlashStringHelper* Label, boolean *val, const __FlashStringHelper* TrueText, const __FlashStringHelper* FalseText): _Label(Label), _isFlash(true), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblBoolWithText), _ItemRef(val), _blnTrueTxt(TrueText), _blnFalseTxt(FalseText){};
	EZUI_Control_Label(const __FlashStringHelper* Label, const __FlashStringHelper* val):	_Label(Label), _isFlash(true), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblCCharArr), _ItemRef(val){};
	EZUI_Control_Label(const __FlashStringHelper* Label, char val[]):			_Label(Label), _isFlash(true), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblCharArr), _ItemRef(val){};
	EZUI_Control_Label(const __FlashStringHelper* Label, float *val):			_Label(Label), _isFlash(true), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblFloat), _ItemRef(val){};
	EZUI_Control_Label(const __FlashStringHelper* Label, double *val):			_Label(Label), _isFlash(true), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblDouble), _ItemRef(val){};
	EZUI_Control_Label(const __FlashStringHelper* Label, int *val):			_Label(Label), _isFlash(true), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblInt), _ItemRef(val){};
	EZUI_Control_Label(const __FlashStringHelper* Label, unsigned int *val):	_Label(Label), _isFlash(true), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblUInt), _ItemRef(val){};
	EZUI_Control_Label(const __FlashStringHelper* Label, long *val):			_Label(Label), _isFlash(true), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblLong), _ItemRef(val){};
	EZUI_Control_Label(const __FlashStringHelper* Label, unsigned long *val): 	_Label(Label), _isFlash(true), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblULong), _ItemRef(val){};
	EZUI_Control_Label(const __FlashStringHelper* Label, String *val): 	_Label(Label), _isFlash(true), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblStr), _ItemRef(val){};
	EZUI_Control_Label(const __FlashStringHelper* Label, boolean *val, __FlashStringHelper* TrueText, __FlashStringHelper* FalseText): _Label(Label), _isFlash(true), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblBoolWithText), _ItemRef(val), _blnTrueTxt(TrueText), _blnFalseTxt(FalseText){};
	EZUI_Control_Label(const __FlashStringHelper* Label, boolean *val, char TrueText[], char FalseText[]): _Label(Label), _isFlash(true), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblBoolWithText), _ItemRef(val), _blnTrueTxt(TrueText), _blnFalseTxt(FalseText){};
	EZUI_Control_Label(const __FlashStringHelper* Label, boolean *val):		_Label(Label), _isFlash(true), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblBoolWithText), _ItemRef(val), _blnTrueTxt("1"), _blnFalseTxt("0"){};
	EZUI_Control_Label(const __FlashStringHelper* Label, DigitalIO *val):		_Label(Label), _isFlash(true), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblDigitalIO), _ItemRef(val){};
	EZUI_Control_Label(const __FlashStringHelper* Label, GenericListOption *val):	_Label(Label), _isFlash(true), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblListOpt), _ItemRef(val){};
	EZUI_Control_Label(const __FlashStringHelper* Label, AdjustableParam *val):	_Label(Label), _isFlash(true), EZUI_Control(EZUI_ControlType::Label), _Label_Type(EZUI_Control_Label_Type::LblAdjParam), _ItemRef(val){};
	
protected:
private:

}; //EZUI_Control_Lablel

#endif //__EZUI_CONTROL_LABLEL_H__
