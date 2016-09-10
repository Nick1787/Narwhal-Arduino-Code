/*
 *        File: MAIN_UI.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Main Display User Interface setup
 * ----------------------------------------------------------------
 *    Revision:
 *		01012016 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#ifndef MAIN_UI_H_
#define MAIN_UI_H_

#include "../EZUI/EZUI.h"
#include "../EZUI/EZUI_Display.h"
#include "../Executive.h"
#include "../Hardware.h"
#include "../../config.h"

namespace UI_MAIN{
	extern EZUI *UI;
	void UI_init();
}

#endif /* MAIN_UI_H_ */