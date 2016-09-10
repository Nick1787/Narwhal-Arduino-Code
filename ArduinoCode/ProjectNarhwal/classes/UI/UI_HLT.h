/*
 *        File: HLT_UI.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: HLT Display User Interface setup
 * ----------------------------------------------------------------
 *    Revision:
 *		01012016 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#ifndef HLT_UI_H_
#define HLT_UI_H_

//Includes
#include "../EZUI/EZUI.h"
#include "../Executive.h"
#include "../Hardware.h"
#include "../../config.h"
#include "../EZUI/EZUI_Display.h"
#include "UI_Shared.h"

namespace UI_HLT{
	extern EZUI *UI;
	void UI_init();
}

#endif /* HLT_UI_H_ */