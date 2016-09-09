/* 
* EZUI_Control_ListOption.cpp
*
* Created: 1/10/2016 9:31:32 AM
* Author: Customer
*/


#include "EZUI_Control_ListOption.h"

// Constructor with Menu Label
EZUI_Control_ListOption::EZUI_Control_ListOption(EZUI_ListOption items[], unsigned int size)
{
	this->itemCount = size;
	this->MenuLabel = "";
	this->items = items;
	
} //EZUI_Control_ListOption

// Constructor Without Menu Label
EZUI_Control_ListOption::EZUI_Control_ListOption(String Label, EZUI_ListOption[], unsigned int size)
{
	this->itemCount = size;
	this->MenuLabel = Label;
	this->items = items;
} //EZUI_Control_ListOption


// Destructor
EZUI_Control_ListOption::~EZUI_Control_ListOption()
{
} //~EZUI_Control_ListOption


// default destructor
String EZUI_Control_ListOption::Text() const
{
	return "";
} //~EZUI_Control_ListOption

