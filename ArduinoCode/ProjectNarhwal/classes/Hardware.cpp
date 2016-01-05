/*
 * Hardware.cpp
 *
 * Created: 11/8/2015 5:18:14 PM
 *  Author: Customer
 */ 

#include "Hardware.h"

/**************************
*	Generic defines for LiquidCrystal (not sure if these are actuall needed)
**************************/
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7
#define LCD_BACKLIGHT_PIN     3

/**************************
*	Functions
**************************/
void serviceEncoders(){
	MAIN_ENC->service();
	HLT_ENC->service();
	MLT_ENC->service();
	BK_ENC->service();
}

void hardware_init(){
	
	//--Setup the LCDs-------
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.print("Initializing LCDs...");
	#endif
	
	MAIN_LCD.setBacklightPin(LCD_BACKLIGHT_PIN,POSITIVE);
	MAIN_LCD.setBacklight(HIGH);
	MAIN_LCD.begin (20,4);
	
	HLT_LCD.setBacklightPin(LCD_BACKLIGHT_PIN,POSITIVE);
	HLT_LCD.setBacklight(HIGH);
	HLT_LCD.begin (20,4);
	
	MLT_LCD.setBacklightPin(LCD_BACKLIGHT_PIN,POSITIVE);
	MLT_LCD.setBacklight(HIGH);
	MLT_LCD.begin (20,4);
	
	BK_LCD.setBacklightPin(LCD_BACKLIGHT_PIN,POSITIVE);
	BK_LCD.setBacklight(HIGH);
	BK_LCD.begin (20,4);
	
	//--Initialize the Encoders-------
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println("Done.");
		Serial.print("Initializing Encoders...");
	#endif
	
	//Attach the Timer
	Timer1.initialize(1000);
	Timer1.attachInterrupt(serviceEncoders);
	
	//--Attatch Hardware-------
	HLT_UI->attatchEncoder(HLT_ENC);
	HLT_UI->attatchLCD(&HLT_LCD);
	
	MLT_UI->attatchEncoder(MLT_ENC);
	MLT_UI->attatchLCD(&MLT_LCD);
	
	BK_UI->attatchEncoder(MLT_ENC);
	BK_UI->attatchLCD(&MLT_LCD);
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println("Done.");
	#endif
	
}

/**************************
*	Alarms
**************************/
DigIO * TimerAlarmDIO = new DigIO(TIMER_ALARM_PIN,DigIO::OUT, "ON", "OFF");
DigIO * TempAlarmDIO = new DigIO(TEMP_ALARM_PIN,DigIO::OUT, "ON", "OFF");

/**************************
*	Main Screen
**************************/
LiquidCrystal_I2C MAIN_LCD( MAIN_LCD_I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);
ClickEncoderWithEvents *MAIN_ENC = new ClickEncoderWithEvents( MAIN_ENC_A, MAIN_ENC_B, MAIN_ENC_SW, MAIN_ENC_DEG_PER_NOTCH );

/**************************
*	Hot Liquor Tank
**************************/
LiquidCrystal_I2C HLT_LCD( HLT_LCD_I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);
ClickEncoderWithEvents *HLT_ENC = new ClickEncoderWithEvents( HLT_ENC_A, HLT_ENC_B, HLT_ENC_SW, HLT_ENC_DEG_PER_NOTCH );

/**************************
*	Mash Lauter Tun
**************************/
LiquidCrystal_I2C MLT_LCD( MLT_LCD_I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);
ClickEncoderWithEvents *MLT_ENC = new ClickEncoderWithEvents( MLT_ENC_A, MLT_ENC_B, MLT_ENC_SW, MLT_ENC_DEG_PER_NOTCH );

/**************************
*	Boil Kettle
**************************/
LiquidCrystal_I2C BK_LCD( BK_LCD_I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);
ClickEncoderWithEvents *BK_ENC = new ClickEncoderWithEvents( BK_ENC_A, BK_ENC_B, BK_ENC_SW, BK_ENC_DEG_PER_NOTCH );
UserInterface *BK_UI = new UserInterface("BK");