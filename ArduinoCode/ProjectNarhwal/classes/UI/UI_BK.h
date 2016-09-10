/*
 *        File: BK_UI.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: BK Display User Interface setup
 * ----------------------------------------------------------------
 *    Revision:
 *		01012016 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#ifndef BK_UI_H_
#define BK_UI_H_

//Includes
#include "../EZUI/EZUI.h"
#include "../Executive.h"
#include "../Hardware.h"
#include "../../config.h"
#include "../EZUI/EZUI_Display.h"
#include "../EZUI/Controls/EZUI_Control_Label.h"
#include "UI_Shared.h"

namespace UI_BK{
	extern EZUI *UI;
	void UI_init();
}

#endif /* BK_UI_H_ */