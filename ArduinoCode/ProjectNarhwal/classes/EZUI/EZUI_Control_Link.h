/*
 *        File: EZUI_Control_Link.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: EZ User Interface Class - Link Control
 */

#ifndef __EZUI_CONTROL_LINK_H__
#define __EZUI_CONTROL_LINK_H__

//Includes
#include "EZUI_Control.h"

//Forward Declarations
class EZUI;
class EZUI_UI;

class EZUI_Control_Link : public EZUI_Control
{
//variables
public:	
protected:
private:
	EZUI_UI * _LinkRef;
	const void * _Label;

//functions
public:
	boolean PROGMEM isFlash = false;
	
	//Over-ridden base class functions
	boolean isSelectable() const  override;
	boolean hasValueText() const override;
	const char* LabelText(void) override;
	const char* ValueText(void) override;
	void Select(EZUI *UI) const override;
	
	//Default Destructor
	~EZUI_Control_Link() {};	
		
	//void FollowLink(EZUI *UI) const;
	EZUI_Control_Link(const char Text[], EZUI_UI * Link): EZUI_Control(EZUI_ControlType::Link), _LinkRef(Link), _Label(Text){};
	EZUI_Control_Link(const __FlashStringHelper * Text, EZUI_UI * Link): EZUI_Control(EZUI_ControlType::Link), _LinkRef(Link), _Label(Text), isFlash(true){};

protected:
private:

}; //EZUI_Control_Link

#endif //__EZUI_CONTROL_LINK_H__
