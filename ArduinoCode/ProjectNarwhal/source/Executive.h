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

class Executive{
  public:
	int frame_count;
	void exec_frame1(void);
	void exec_frame2(void);
	void exec_frame3(void);
	void exec_frame4(void);
	void run(void);
  private:

};

#endif