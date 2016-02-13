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

#include "../EZUI/EZUI.h"
#include "../Executive.h"
#include "../Hardware.h"
#include "../../config.h"
#include "../EZUI/EZUI_Menu.h"
#include "../EZUI/EZUI_MenuItem.h"
#include "../EZUI/EZUI_Page.h"
#include "../EZUI/EZUI_PageItem.h"

extern EZUI *HLT_UI;
void HLT_UI_init();

#endif /* HLT_UI_H_ */