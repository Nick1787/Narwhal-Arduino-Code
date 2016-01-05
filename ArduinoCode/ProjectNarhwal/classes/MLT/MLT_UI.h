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

#include "../UserInterface/UserInterface.h"
#include "../Executive.h"
#include "../Hardware.h"
#include "../../config.h"
#include "../UserInterface/LCDMenu.h"
#include "../UserInterface/LCDMenuItem.h"
#include "../UserInterface/LCDPage.h"
#include "../UserInterface/LCDPageItem.h"

extern UserInterface *MLT_UI;
void MLT_UI_init();

#endif /* MLT_UI_H_ */