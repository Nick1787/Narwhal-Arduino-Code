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
	
	//Update the RTD values
	HLT_RTD_BP->Update();
	//HLT_RTD_OP->Update();
	//MLT_RTD_BP->Update();
	//MLT_RTD_OP->Update();
	//BK_RTD_BP->Update();
	//BK_RTD_OP->Update();
	
	analog0 = (5.0*(float)analogRead(A0))/1023.0;
	analog1 = (5.0*(float)analogRead(A1))/1023.0;
	analog2 = (5.0*(float)analogRead(A2))/1023.0;
	analog3 = (5.0*(float)analogRead(A3))/1023.0;
	analog4 = (5.0*(float)analogRead(A4))/1023.0;
	analog5 = (5.0*(float)analogRead(A5))/1023.0;
	analog6 = (5.0*(float)analogRead(A6))/1023.0;
	analog7 = (5.0*(float)analogRead(A7))/1023.0;
	analog8 = (5.0*(float)analogRead(A8))/1023.0;
	analog9 = (5.0*(float)analogRead(A9))/1023.0;
	analog10 = (5.0*(float)analogRead(A10))/1023.0;
	analog11 = (5.0*(float)analogRead(A11))/1023.0;
	analog12 = (5.0*(float)analogRead(A12))/1023.0;
	analog13 = (5.0*(float)analogRead(A13))/1023.0;
	analog14 = (5.0*(float)analogRead(A14))/1023.0;
	analog15 = (5.0*(float)analogRead(A15))/1023.0;
}

void Executive::exec_frame2(){
	//Run the Controllers
	
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
