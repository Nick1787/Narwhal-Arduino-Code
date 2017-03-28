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

unsigned long lastms = 0;

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
		execHz = (((float)temp_frame_count) / ((float)(time-temp_time)/1000));
		
		Serial.print(F("Running at "));
		Serial.print(execHz);
		Serial.print(F(" Hertz ("));
		Serial.print(temp_frame_count);
		Serial.print(F(" frames / "));
		Serial.print(time-temp_time);
		Serial.print(F(" ms ) - "));
		Serial.print(freeMemory());
		Serial.println(F(" bytes free."));
		Serial.flush();
				
		//reset counters
		temp_time = time;
		temp_frame_count=0;
		
		CurrentDateTime = RTC().getDateStamp(DS323RealTimeClock::DATETIME);
	}
	
}

void Executive::exec_frame1(){	
		
	//Pump Monitor #1
	Pump1_V = 5.0 * ((float)analogRead(PUMP1_VIN) / 1023.0);
	if(Pump1_V > 2.5){
		Pump1_On = true;
	}else{
		Pump1_On = false;
	}
	
	//Pump Monitor #2
	Pump2_V = 5.0 * ((float)analogRead(PUMP2_VIN) / 1023.0);
	if(Pump2_V > 2.5){
		Pump2_On = true;
	}else{
		Pump2_On = false;
	}
	
	//HLT Thermocouple
	HLT_TC_V = 5.0 * ((float)analogRead(HLT_TC_VIN) / 1023.0);
	if(HLT_TC_V > 0.25){
		HLT_TC_ON = true;
	}else{
		HLT_TC_ON = false;
	}
	
	//MLT Thermocouple
	MLT_TC_V = 5.0 * ((float)analogRead(MLT_TC_VIN) / 1023.0);
	if(MLT_TC_V > 0.25){
		MLT_TC_ON = true;
	}else{
		MLT_TC_ON = false;
	}
	
	//BK Thermocouple
	BK_TC_V = 5.0 * ((float)analogRead(BK_TC_VIN) / 1023.0);
	if(BK_TC_V > 0.25){
		BK_TC_ON = true;
	}else{
		BK_TC_ON = false;
	}
	
	//Encoders
	MAIN_ENC.Read();
	MLT_ENC.Read();
	HLT_ENC.Read();
	BK_ENC.Read();
	
	//Real Time Clock
	RTC().exec();
	Logger().log();
}

void Executive::exec_frame2(){
	
	//Update the RTD values
	HLT_RTD_BP.Calculate( (float)analogRead(HLT_RTD_Vs_AN) / 1023.0, (float)analogRead(HLT_RTD_BP_AN) / 1023.0 );
	HLT_RTD_OP.Calculate( (float)analogRead(HLT_RTD_Vs_AN) / 1023.0, (float)analogRead(HLT_RTD_OP_AN) / 1023.0 );
	MLT_RTD_BP.Calculate( (float)analogRead(MLT_RTD_Vs_AN) / 1023.0, (float)analogRead(MLT_RTD_BP_AN) / 1023.0 );
	MLT_RTD_OP.Calculate( (float)analogRead(MLT_RTD_Vs_AN) / 1023.0, (float)analogRead(MLT_RTD_OP_AN) / 1023.0 );
	BK_RTD_BP.Calculate(  (float)analogRead(BK_RTD_Vs_AN)  / 1023.0, (float)analogRead(BK_RTD_BP_AN)  / 1023.0 );
	BK_RTD_OP.Calculate(  (float)analogRead(BK_RTD_Vs_AN)  / 1023.0, (float)analogRead(BK_RTD_OP_AN)  / 1023.0 );
	
	//Controllers
	//HLT_Controller().Exec();
	//MLT_Controller().Exec();
	//BK_Controller().Exec();
}

void Executive::exec_frame3(){
	
	//Update the UI
	UI_MAIN::UI->display();
	UI_HLT::UI->display();
	UI_MLT::UI->display();
	UI_BK::UI->display();
}

void Executive::exec_frame4(){
	
	//Update Free Memory Calculations
	freeSramBytes=freeMemory();
	freeSramPct=100.0*(float)(freeSramBytes/8000);
	
	//Transmit Serial DAta
	//	AdvSerial.exec();
	
	//Do logging + PHM
}
