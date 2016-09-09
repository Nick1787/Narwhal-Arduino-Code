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

//Forward Declarations
class EZUI;

class EZUI_Control_Label : public EZUI_Control
{
//variables
public:
	using EZUI_Control::Type;
	enum EZUI_Control_Label_Type {None, LblString, LblFloat, LblDouble, LblInt, LblUInt, LblLong, LblULong, LblBool, LblBoolWithText, LblDigitalIO};
	EZUI_Control_Label_Type Label_Type = None;	//Not initialized to any value
	
protected:
private:
	//When was this last printed.  Used to refresh page
	unsigned long timeLastPrinted = -1;
	void* ItemRef = NULL;
	String blnTrueTxt = "";
	String blnFalseTxt = "";
	
//functions
public:

	//Over-ridden base class functions
	String Text(void) const  override;
	boolean isSelectable() const override { return false; };
	void Select(EZUI *UI) const override { /* Do nothing */ };
		
	//Destructor
	~EZUI_Control_Label() override {};
	
	//Instantiate - Static Values
	EZUI_Control_Label(char val[]);
	//EZUI_Control_Label(const char val[]);
	
	//Instantiate - Dynamic Values
	EZUI_Control_Label(float *val);
	EZUI_Control_Label(double *val);
	EZUI_Control_Label(int *val);
	EZUI_Control_Label(unsigned int *val);
	EZUI_Control_Label(long *val);
	EZUI_Control_Label(unsigned long *val);
	EZUI_Control_Label(boolean *val, String TrueText, String FalseText);
	EZUI_Control_Label(DigitalIO *val);
	
	
protected:
private:
	//EZUI_Control_Label( const EZUI_Control_Label &c );
	//EZUI_Control_Label& operator=( const EZUI_Control_Label &c ) override;

}; //EZUI_Control_Lablel

#endif //__EZUI_CONTROL_LABLEL_H__
