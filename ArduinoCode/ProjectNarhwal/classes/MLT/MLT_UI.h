/*
 *        File: MLT_UI.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: MLT Display User Interface setup
 * ----------------------------------------------------------------
 *    Revision:
 *		01012016 - NRD - Initial Version
 * ----------------------------------------------------------------
 */

#ifndef MLT_UI_H_
#define MLT_UI_H_

#include "../EZUI/EZUI.h"
#include "../Executive.h"
#include "../Hardware.h"
#include "../../config.h"
#include "../EZUI/EZUI_Menu.h"
#include "../EZUI/EZUI_MenuItem.h"
#include "../EZUI/EZUI_Page.h"
#include "../EZUI/EZUI_PageItem.h"

extern EZUI *MLT_UI;
void MLT_UI_init();

#endif /* MLT_UI_H_ */