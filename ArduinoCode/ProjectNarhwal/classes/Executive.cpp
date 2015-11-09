/*
 *        File: Executive.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Main executive 
 * ----------------------------------------------------------------
 *    Revision:
 *		09152015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */
 
#include "Hardware.h"
#include "Executive.h"

void Executive::run(){
	frame_count++;
	exec_frame1();
	exec_frame2();
	exec_frame3();
	exec_frame4();
}

void Executive::exec_frame1(){
}

void Executive::exec_frame2(){
}

void Executive::exec_frame3(){
	Serial.println("Running...");
	HLT_UI->display();
}

void Executive::exec_frame4(){
}
