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
		
		
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.print(F("Initializing SD Card..."));
	#endif

	if(!Logger().init()){
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
			Serial.println(F("Failed!!!"));
			Serial.println(F("Data Logging Disabled!!!"));
		#endif
	}else{
			
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
			Serial.println(F("Done."));
			Serial.print(F("Initializing DataLogger..."));
		#endif
		
		// --General--
		
		Logger().addParam(F("freeMemory"),&freeSramBytes);
		Logger().addParam(F("execHz"),&Exec.execHz);
		
		// --HLT Signals--
		
		/*Logger.addParam("HLT.Enabled",&HLT_Controller().ControlEnabled);
		Logger.addParam("HLT.SetTemp",&HLT_Controller().SetTemp->value);
		Logger.addParam("HLT.FeedbackTemp",&HLT_Controller().FeedbackTemp);
		Logger.addParam("HLT.Hysteresis",&HLT_Controller().Hysteresis->value);
		Logger.addParam("HLT.HighOffset",&HLT_Controller().HighOffset->value);
		Logger.addParam("HLT.MediumOffset",&HLT_Controller().MediumOffset->value);
		Logger.addParam("HLT.LowOffset",&HLT_Controller().LowOffset->value);
		Logger.addParam("HLT.GasValve_Low",&HLT_Controller().GasValve1_Low->value);
		Logger.addParam("HLT.GasValve_High",&HLT_Controller().GasValve2_High->value);
		
		// --MLT Signals--
		
		Logger.addParam("MLT.Enabled",&MLT_Controller().ControlEnabled);
		Logger.addParam("MLT.SetTemp",&MLT_Controller().SetTemp->value);
		Logger.addParam("MLT.FeedbackTemp",&MLT_Controller().FeedbackTemp);
		Logger.addParam("MLT.Hysteresis",&MLT_Controller().Hysteresis->value);
		Logger.addParam("MLT.HighOffset",&MLT_Controller().HighOffset->value);
		Logger.addParam("MLT.MediumOffset",&MLT_Controller().MediumOffset->value);
		Logger.addParam("MLT.LowOffset",&MLT_Controller().LowOffset->value);
		Logger.addParam("MLT.GasValve_Low",&MLT_Controller().GasValve1_Low->value);
		Logger.addParam("MLT.GasValve_High",&MLT_Controller().GasValve2_High->value);
		
		// --BK Signals--
		
		Logger.addParam("BK.Enabled",&BK_Controller().ControlEnabled);
		Logger.addParam("BK.SetTemp",&BK_Controller().SetTemp->value);
		Logger.addParam("BK.FeedbackTemp",&BK_Controller().FeedbackTemp);
		Logger.addParam("BK.Hysteresis",&BK_Controller().Hysteresis->value);
		Logger.addParam("BK.HighOffset",&BK_Controller().HighOffset->value);
		Logger.addParam("BK.MediumOffset",&BK_Controller().MediumOffset->value);
		Logger.addParam("BK.LowOffset",&BK_Controller().LowOffset->value);
		Logger.addParam("BK.GasValve_Low",&BK_Controller().GasValve1_Low->value);
		Logger.addParam("BK.GasValve_High",&BK_Controller().GasValve2_High->value);*/
		
		#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
			Serial.println(F("Done."));
		#endif
	}
		
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
		
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println(F("Done."));
		Serial.print(F("Initializing Burner Controllers..."));
	#endif
	
	//Setup HLT
	HLT_Controller().FeedbackProbe.setValue(EnumFeedbackProbes::HLTBP);
	MLT_Controller().FeedbackProbe.setValue(EnumFeedbackProbes::MLTBP);
	BK_Controller().FeedbackProbe.setValue(EnumFeedbackProbes::BKBP);
	
	//Burner Controllers
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println(F("Done."));
		Serial.print(F("Initializing Solenoids..."));
	#endif
	
	//Set all Solenoids to output high which is "off" mode
	RC1_OUT1.Write(1);
	RC1_OUT2.Write(1);
	RC1_OUT3.Write(1);
	RC1_OUT4.Write(1);
	RC1_OUT5.Write(1);
	RC1_OUT6.Write(1);
	RC1_OUT7.Write(1);
	RC1_OUT8.Write(1);
	RC2_OUT1.Write(1);
	RC2_OUT2.Write(1);
	RC2_OUT3.Write(1);
	RC2_OUT4.Write(1);
	RC2_OUT5.Write(1);
	RC2_OUT6.Write(1);
	RC2_OUT7.Write(1);
	RC2_OUT8.Write(1);
	
		
	#if defined(SERIAL_VERBOSE) && (SERIAL_VERBOSE>0)
		Serial.println(F("Done."));
		Serial.print(F("Initializing RealTimeClock..."));
	#endif
		
	RTC().init();
		
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
*	Executive
**************************/
Executive Exec;

/**************************
*	Real Time Clock
**************************/
String CurrentDateTime = "";
DS323RealTimeClock& RTC()
{
	static DS323RealTimeClock* ans = new DS323RealTimeClock(DS3231_I2C_ADDR, &RTC_Seconds, &RTC_Minutes, &RTC_Hour,&RTC_Days,&RTC_Months,&RTC_Years);
	return *ans;
}

/**************************
*	Data Logger
**************************/
DataLogger<LoggerSize>& Logger()
{
	static DataLogger<LoggerSize> * ans = new DataLogger<LoggerSize>(&LOG_logRateMs, &RTC());
	return *ans;
}




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
EZUI_ClickEncoder MAIN_ENC( MAIN_ENC_A, MAIN_ENC_B, MAIN_ENC_SW, MAIN_ENC_DEG_PER_NOTCH );

/**************************
*	Hot Liquor Tank
**************************/
LiquidCrystal_I2C HLT_LCD( HLT_LCD_I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);
EZUI_ClickEncoder HLT_ENC( HLT_ENC_A, HLT_ENC_B, HLT_ENC_SW, HLT_ENC_DEG_PER_NOTCH );
DigitalIO * HLT_SOL1 = &RC1_OUT1;
DigitalIO * HLT_SOL2 = &RC1_OUT2;
WheatstoneBridge HLT_RTD_BP(LUTREF, WB_R2, WB_R3, WB_R4, WB_OpAmpGn, WB_Rs);
WheatstoneBridge HLT_RTD_OP(LUTREF, WB_R2, WB_R3, WB_R4, WB_OpAmpGn, WB_Rs);
	
//Encapsulate to ensure properly initialized
BurnerController& HLT_Controller()
{
	static BurnerController* ans = new BurnerController(&HLT_TC_ON, &HLT_RTD_BP, &HLT_RTD_OP, HLT_SOL1, HLT_SOL2, &HLT_SetTemp, &HLT_HighOffset, &HLT_MedOffset, &HLT_LowOffset, &HLT_Hysteresis, &HLT_PWMPeriod, &HLT_PWMDuty);
	return *ans;
}

/**************************
*	Mash Lauter Tun
**************************/
LiquidCrystal_I2C MLT_LCD( MLT_LCD_I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);
EZUI_ClickEncoder MLT_ENC( MLT_ENC_A, MLT_ENC_B, MLT_ENC_SW, MLT_ENC_DEG_PER_NOTCH );
DigitalIO * MLT_SOL1 = &RC1_OUT3;
DigitalIO * MLT_SOL2 = &RC1_OUT4;
WheatstoneBridge MLT_RTD_BP(LUTREF, WB_R2, WB_R3, WB_R4, WB_OpAmpGn, WB_Rs);
WheatstoneBridge MLT_RTD_OP(LUTREF, WB_R2, WB_R3, WB_R4, WB_OpAmpGn, WB_Rs);

//Encapsulate to ensure properly initialized
BurnerController& MLT_Controller()
{
	static BurnerController* ans = new BurnerController(&MLT_TC_ON, &MLT_RTD_BP, &MLT_RTD_OP, MLT_SOL1, MLT_SOL2, &MLT_SetTemp, &MLT_HighOffset, &MLT_MedOffset, &MLT_LowOffset, &MLT_Hysteresis, &MLT_PWMPeriod, &MLT_PWMDuty);
	return *ans;
}

/**************************
*	Boil Kettle
**************************/
LiquidCrystal_I2C BK_LCD( BK_LCD_I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);
EZUI_ClickEncoder BK_ENC( BK_ENC_A, BK_ENC_B, BK_ENC_SW, BK_ENC_DEG_PER_NOTCH );
DigitalIO * BK_SOL1 = &RC1_OUT5;
DigitalIO * BK_SOL2 = &RC1_OUT6;
WheatstoneBridge BK_RTD_BP(LUTREF, WB_R2, WB_R3, WB_R4, WB_OpAmpGn, WB_Rs);
WheatstoneBridge BK_RTD_OP(LUTREF, WB_R2, WB_R3, WB_R4, WB_OpAmpGn, WB_Rs);

//Encapsulate to ensure properly initialized
BurnerController& BK_Controller()
{
	static BurnerController* ans = new BurnerController(&BK_TC_ON, &BK_RTD_BP, &BK_RTD_OP, BK_SOL1, BK_SOL2, &BK_SetTemp, &BK_HighOffset, &BK_MedOffset, &BK_LowOffset,  &BK_Hysteresis, &BK_PWMPeriod, &BK_PWMDuty);
	return *ans;
}