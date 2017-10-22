/*
 *        File: Executive.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Main executive 
 * ----------------------------------------------------------------
 *    Revision:
 *		09152015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */
 
#ifndef _EXECUTIVE_H
#define _EXECUTIVE_H

#include "../Main.h"
extern String CurrentDateTime;
extern bool HLT_LowOn;
extern bool HLT_HighOn;
extern bool MLT_LowOn;
extern bool MLT_HighOn;
extern bool BK_LowOn;
extern bool BK_HighOn;

class Executive{
  public:
	unsigned long time = 0;
	int frame_count;
	bool faultDetected = false;
	float execHz;
	
	void exec_frame1(void);
	void exec_frame2(void);
	void exec_frame3(void);
	void exec_frame4(void);
	void run(void);
  private:
	long temp_frame_count = 0;
	unsigned long temp_time = 0;
};

#endif