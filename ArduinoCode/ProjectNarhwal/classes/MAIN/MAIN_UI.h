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

#include "../UserInterface/UserInterface.h"
#include "../Executive.h"
#include "../Hardware.h"
#include "../../config.h"
#include "../UserInterface/LCDMenu.h"
#include "../UserInterface/LCDMenuItem.h"
#include "../UserInterface/LCDPage.h"
#include "../UserInterface/LCDPageItem.h"

extern UserInterface *MAIN_UI;
void MAIN_UI_init();

#endif /* MAIN_UI_H_ */