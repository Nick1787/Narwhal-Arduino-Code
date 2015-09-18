/*
 *        File: ClickEnc.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Extends ClickEncoder class to have more functionality
 * ----------------------------------------------------------------
 *    Revision:
 *		09152015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */
 
#ifndef _CENCODER_H
#define _CENCODER_H

#include <ClickEncoder.h>

class CEncoder : public ClickEncoder{
	public:
		CEncoder(uint8_t A, uint8_t B, uint8_t BTN, uint8_t stepsPerNotch);
  
  private:
};

#endif