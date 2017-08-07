/*
 *        File: EZUI_Control_AdjustParam.cpp
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - Adjustable Param
 */

#ifndef __EZUI_ADJUSTPARAM_H__
#define __EZUI_ADJUSTPARAM_H__

//Includes
#include "EZUI_Control.h"

class EZUI_Control_AdjustParam : public EZUI_Control
{
//variables
public:
protected:
private:
	boolean isFlash;
	const void * _Label;
	AdjustableParam *_Ref;

//functions
public:
	boolean isSelectable() const  override;
	boolean hasValueText() const override;
	const char* LabelText() override;
	const char* ValueText() override;
	void Select(EZUI *UI) const override;
		
	EZUI_Control_AdjustParam(char * Label, AdjustableParam *ParamRef): EZUI_Control(EZUI_ControlType::ListControl), _Label(Label), _Ref(ParamRef), isFlash(false){};
	EZUI_Control_AdjustParam(const __FlashStringHelper * Label, AdjustableParam *ParamRef): EZUI_Control(EZUI_ControlType::ListControl), _Label(Label), _Ref(ParamRef), isFlash(true){};
	~EZUI_Control_AdjustParam();
protected:
private:
	//EZUI_Control_AdjustParam( const EZUI_Control_AdjustParam &c );
	//EZUI_Control_AdjustParam& operator=( const EZUI_Control_AdjustParam &c );

}; //EZUI_AdjustParam

#endif //__EZUI_ADJUSTPARAM_H__
