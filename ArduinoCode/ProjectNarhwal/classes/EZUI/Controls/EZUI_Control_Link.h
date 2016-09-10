/*
 *        File: EZUI_Control_Link.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - Link Control
 *			- Links can be created to other pages or menus
 * ----------------------------------------------------------------
 *    Revision:
 *		11062015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#ifndef __EZUI_CONTROL_LINK_H__
#define __EZUI_CONTROL_LINK_H__

//Includes
#include "EZUI_Control.h"
#include "../EZUI.h"

//Forward Declarations
class EZUI;
class EZUI_Page;
class EZUI_Menu;
class DigitalIO;

class EZUI_Control_Link : public EZUI_Control
{
//variables
public:	
protected:
private:
	EZUI_Display * _LinkRef;
	char * _Label;

//functions
public:

	//Over-ridden base class functions
	boolean isSelectable() const  override {return true;};
	boolean hasValueText() const override { return false;};
	String LabelText(void) override{ return String(this->_Label); };
	void Select(EZUI *UI) const override {
		UI->setDisplay(_LinkRef);
	};
	
	//Default Destructor
	~EZUI_Control_Link() override {};	
		
	//void FollowLink(EZUI *UI) const;
	EZUI_Control_Link(char Text[], EZUI_Display * Link): EZUI_Control(EZUI_ControlType::Link), _LinkRef(Link), _Label(Text){};

protected:
private:

}; //EZUI_Control_Link

#endif //__EZUI_CONTROL_LINK_H__
