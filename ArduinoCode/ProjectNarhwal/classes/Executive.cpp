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
	//IO
	
	//Encoders
	MAIN_ENC->Read();
	MLT_ENC->Read();
	HLT_ENC->Read();
	BK_ENC->Read();
	
	//Analog Ins
	ANIN_A0.update();
	ANIN_A1.update();
	ANIN_A2.update();
	ANIN_A3.update();
	ANIN_A4.update();
	ANIN_A5.update();
	ANIN_A6.update();
	ANIN_A7.update();
	ANIN_A8.update();
	ANIN_A9.update();
	ANIN_A10.update();
	ANIN_A11.update();
	ANIN_A12.update();
	ANIN_A13.update();
	ANIN_A14.update();

}

void Executive::exec_frame2(){
	//Calculate Parameters
	
	//Update the RTD values
	HLT_RTD_BP->Update();
	//HLT_RTD_OP->Update();
	//MLT_RTD_BP->Update();
	//MLT_RTD_OP->Update();
	//BK_RTD_BP->Update();
	//BK_RTD_OP->Update();
	
	//Controllers
	
}

void Executive::exec_frame3(){
	//Update the UI
	MAIN_UI->display();
	MLT_UI->display();
	HLT_UI->display();
	BK_UI->display();
}

void Executive::exec_frame4(){
	//Do logging + PHM
}
