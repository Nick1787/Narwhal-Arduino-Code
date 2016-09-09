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
	MAIN_ENC.service();
	HLT_ENC.service();
	MLT_ENC.service();
	BK_ENC.service();
}

void hardware_init(){
		
	//--Setup the LCDs-------
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.print(F("Initializing LCDs..."));
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
		Serial.println(F("Done."));
		Serial.print(F("Initializing Encoders..."));
	#endif
	
	//Attach the Timer
	Timer1.initialize(1000);
	Timer1.attachInterrupt(serviceEncoders);
		
	//--Attach Hardware-------
	UI_HLT::UI->attatchEncoder(&HLT_ENC);
	UI_HLT::UI->attatchLCD(&HLT_LCD);
		
	UI_MLT::UI->attatchEncoder(&MLT_ENC);
	UI_MLT::UI->attatchLCD(&MLT_LCD);
		
	UI_BK::UI->attatchEncoder(&BK_ENC);
	UI_BK::UI->attatchLCD(&BK_LCD);
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println(F("Done."));
		Serial.print(F("Initializing Solenoids..."));
	#endif
	
	//Set all Solenoids to output high which is "off" mode
	RC1_OUT1.Write(1);
	RC1_OUT2.Write(1);
	
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println(F("Done."));
	#endif
	
	freeSramBytes=freeMemory();
	freeSramPct=100.0*(8000.0-(float)freeSramBytes)/8000.0;
}

/**************************
*	Advanced Serial
**************************/
//AdvancedSerial AdvSerial(&Serial);
int freeSramBytes = 0;
float freeSramPct = 0;

/**************************
*	Digital IO
**************************/
DigitalIO RC1_OUT1 = DigitalIO(49, DigitalIO::OUT, "OFF", "ON");
DigitalIO RC1_OUT2 = DigitalIO(48 , DigitalIO::OUT, "OFF", "ON");
DigitalIO RC1_OUT3 = DigitalIO(47 , DigitalIO::OUT, "OFF", "ON");
DigitalIO RC1_OUT4 = DigitalIO(46 , DigitalIO::OUT, "OFF", "ON");
DigitalIO RC1_OUT5 = DigitalIO(45 , DigitalIO::OUT, "OFF", "ON");
DigitalIO RC1_OUT6 = DigitalIO(44 , DigitalIO::OUT, "OFF", "ON");
DigitalIO RC1_OUT7 = DigitalIO(43 , DigitalIO::OUT, "OFF", "ON");
DigitalIO RC1_OUT8 = DigitalIO(42 , DigitalIO::OUT, "OFF", "ON");

DigitalIO RC2_OUT1 = DigitalIO(40, DigitalIO::OUT, "OFF", "ON");
DigitalIO RC2_OUT2 = DigitalIO(41 , DigitalIO::OUT, "OFF", "ON");
DigitalIO RC2_OUT3 = DigitalIO(38 , DigitalIO::OUT, "OFF", "ON");
DigitalIO RC2_OUT4 = DigitalIO(39 , DigitalIO::OUT, "OFF", "ON");
DigitalIO RC2_OUT5 = DigitalIO(36 , DigitalIO::OUT, "OFF", "ON");
DigitalIO RC2_OUT6 = DigitalIO(37 , DigitalIO::OUT, "OFF", "ON");
DigitalIO RC2_OUT7 = DigitalIO(35 , DigitalIO::OUT, "OFF", "ON");
DigitalIO RC2_OUT8 = DigitalIO(34 , DigitalIO::OUT, "OFF", "ON");


/**************************
*	ThermoCouples
**************************/
float HLT_TC_V = 0;
bool HLT_TC_ON = false;

float MLT_TC_V = 0;
bool MLT_TC_ON = false;

float BK_TC_V = 0;
bool BK_TC_ON = false;


/**************************
*	Pump Monitor
**************************/
float Pump1_V = 0;
bool Pump1_On = false;
float Pump2_V = 0;
bool Pump2_On = false;


/**************************
*	Wheatstone Bridge
**************************/
const float WB_R2C_X[36] = {80.31, 84.27, 88.22, 92.16, 96.09, 100, 103.9, 107.79, 111.67, 115.54, 119.4, 123.24, 127.08, 130.9, 134.71, 138.51, 142.29, 146.07, 149.83, 153.58, 157.33, 161.05, 164.77, 168.48, 172.17, 175.86, 179.53, 183.19, 186.84, 190.47, 194.1, 197.71, 201.31, 204.9, 208.48, 212.05};
const float WB_R2C_Z[36] = {-50, -40, -30, -20, -10, 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300};
LUT1D<36> RTDLUT(WB_R2C_X, WB_R2C_Z);
LUT * LUTREF = &RTDLUT;

/**************************
*	Main Screen
**************************/
LiquidCrystal_I2C MAIN_LCD( MAIN_LCD_I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);
ClickEncoderWithEvents MAIN_ENC( MAIN_ENC_A, MAIN_ENC_B, MAIN_ENC_SW, MAIN_ENC_DEG_PER_NOTCH );

/**************************
*	Hot Liquor Tank
**************************/
LiquidCrystal_I2C HLT_LCD( HLT_LCD_I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);
ClickEncoderWithEvents HLT_ENC( HLT_ENC_A, HLT_ENC_B, HLT_ENC_SW, HLT_ENC_DEG_PER_NOTCH );
DigitalIO * HLT_SOL1 = &RC1_OUT1;
DigitalIO * HLT_SOL2 = &RC1_OUT2;
WheatstoneBridge HLT_RTD_BP(LUTREF, WB_R2, WB_R3, WB_R4, WB_OpAmpGn, WB_Rs);
WheatstoneBridge HLT_RTD_OP(LUTREF, WB_R2, WB_R3, WB_R4, WB_OpAmpGn, WB_Rs);
float HLT_RTD_Vs = 0.0;
float HLT_RTD_BP_V = 0.0;
float HLT_RTD_OP_V = 0.0;


/**************************
*	Mash Lauter Tun
**************************/
LiquidCrystal_I2C MLT_LCD( MLT_LCD_I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);
ClickEncoderWithEvents MLT_ENC( MLT_ENC_A, MLT_ENC_B, MLT_ENC_SW, MLT_ENC_DEG_PER_NOTCH );
DigitalIO * MLT_SOL1 = &RC1_OUT3;
DigitalIO * MLT_SOL2 = &RC1_OUT4;
WheatstoneBridge MLT_RTD_BP(LUTREF, WB_R2, WB_R3, WB_R4, WB_OpAmpGn, WB_Rs);
WheatstoneBridge MLT_RTD_OP(LUTREF, WB_R2, WB_R3, WB_R4, WB_OpAmpGn, WB_Rs);
float MLT_RTD_Vs = 0.0;
float MLT_RTD_BP_V = 0.0;
float MLT_RTD_OP_V = 0.0;

/**************************
*	Boil Kettle
**************************/
LiquidCrystal_I2C BK_LCD( BK_LCD_I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);
ClickEncoderWithEvents BK_ENC( BK_ENC_A, BK_ENC_B, BK_ENC_SW, BK_ENC_DEG_PER_NOTCH );
DigitalIO * BK_SOL1 = &RC1_OUT5;
DigitalIO * BK_SOL2 = &RC1_OUT6;
WheatstoneBridge BK_RTD_BP(LUTREF, WB_R2, WB_R3, WB_R4, WB_OpAmpGn, WB_Rs);
WheatstoneBridge BK_RTD_OP(LUTREF, WB_R2, WB_R3, WB_R4, WB_OpAmpGn, WB_Rs);
float BK_RTD_Vs = 0.0;
float BK_RTD_BP_V = 0.0;
float BK_RTD_OP_V = 0.0;

