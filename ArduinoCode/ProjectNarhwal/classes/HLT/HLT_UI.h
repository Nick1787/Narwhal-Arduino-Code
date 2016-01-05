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

#include "../UserInterface/UserInterface.h"
#include "../Executive.h"
#include "../Hardware.h"
#include "../../config.h"
#include "../UserInterface/LCDMenu.h"
#include "../UserInterface/LCDMenuItem.h"
#include "../UserInterface/LCDPage.h"
#include "../UserInterface/LCDPageItem.h"

extern UserInterface *HLT_UI;
void HLT_UI_init();

#endif /* HLT_UI_H_ */