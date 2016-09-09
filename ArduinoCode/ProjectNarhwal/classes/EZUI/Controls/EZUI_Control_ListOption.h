/* 
* EZUI_Control_ListOption.h
*
* Created: 1/10/2016 9:31:32 AM
* Author: Customer
*/


#ifndef __EZUI_CONTROL_LISTOPTION_H__
#define __EZUI_CONTROL_LISTOPTION_H__

#include "../EZUI.h"

//Includes
#include "EZUI_Control.h"
#include "../EZUI.h"

struct EZUI_ListOption{
	int value = 0;
	String Text = "";
};

class EZUI_Control_ListOption: public EZUI_Control
{
//variables
public:
protected:
private:
	EZUI_ListOption *items = NULL;
	unsigned int itemCount = 0;
	EZUI_Page * PageRef = NULL;
	EZUI_Menu * MenuRef = NULL;
	
//functions
public:
	//Menu Label
	String MenuLabel = "";
	
	//Over-ridden base class functions
	String Text(void) const  override;
	boolean isSelectable() const  override {return true;};

	//UI Stuff
	void Select(EZUI *UI) const override;
	
	EZUI_Control_ListOption(EZUI_ListOption[],  unsigned int size);
	EZUI_Control_ListOption(String Label, EZUI_ListOption[],  unsigned int size);
	~EZUI_Control_ListOption();
	
protected:
private:

}; //EZUI_Control_ListOption

#endif //__EZUI_CONTROL_LISTOPTION_H__
