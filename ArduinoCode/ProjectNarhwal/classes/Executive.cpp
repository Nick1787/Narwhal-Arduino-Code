/*
 *        File: Executive.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Main executive 
 * ----------------------------------------------------------------
 *    Revision:
 *		09152015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */
 
#include "Executive.h"

void Executive::run(){
	frame_count++;
	time = millis();
	exec_frame1();
	exec_frame2();
	exec_frame3();
	exec_frame4();
	
	//Execution rate
	temp_frame_count++;
	if((time - temp_time)>3000){
		float Hz = (((float)temp_frame_count) / ((float)(time-temp_time)/1000));
		Serial.print("Running at ");
		Serial.print(Hz);
		Serial.print(" Hertz (");
		Serial.print(temp_frame_count);
		Serial.print(" frames / ");
		Serial.print(time-temp_time);
		Serial.println(" ms )");
		
		//reset counters
		temp_time = time;
		temp_frame_count=0;
	}
	
	//global::timems = time;
	//global::timsec = (float)(time/1000);
}

void Executive::exec_frame1(){
	MAIN_ENC->Read();
	MLT_ENC->Read();
	HLT_ENC->Read();
	BK_ENC->Read();
}

void Executive::exec_frame2(){
}

void Executive::exec_frame3(){
	MAIN_UI->display();
	MLT_UI->display();
	HLT_UI->display();
	BK_UI->display();
}

void Executive::exec_frame4(){
}
