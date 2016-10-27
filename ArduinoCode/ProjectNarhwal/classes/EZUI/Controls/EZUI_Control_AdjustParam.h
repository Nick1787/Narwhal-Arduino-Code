/* 
* EZUI_AdjustParam.h
*
* Created: 7/9/2016 9:37:19 AM
* Author: Customer
*/

#ifndef __EZUI_ADJUSTPARAM_H__
#define __EZUI_ADJUSTPARAM_H__

#include "../EZUI.h"
#include "EZUI_Control.h"

class EZUI_Control_AdjustParam : public EZUI_Control
{
//variables
public:
protected:
private:

//functions
public:
	boolean isSelectable() const  override {return true;};
		
	EZUI_Control_AdjustParam();
	~EZUI_Control_AdjustParam();
protected:
private:
	EZUI_Control_AdjustParam( const EZUI_Control_AdjustParam &c );
	EZUI_Control_AdjustParam& operator=( const EZUI_Control_AdjustParam &c );

}; //EZUI_AdjustParam

#endif //__EZUI_ADJUSTPARAM_H__
