/*
 *        File: iodef.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Defines the hardware io pins for Project Narwhal on
 *				the arduino Mega
 * ----------------------------------------------------------------
 *    Revision:
 *		09152015 - NRD - Initial Version
 * ----------------------------------------------------------------
 */
 
#ifndef iodef_h
#define iodef_h

///////////////////////////////
// General
///////////////////////////////
#define AN_REF A0

//Relay Board1
#define RB1_1 49
#define RB1_2 48
#define RB1_3 47
#define RB1_4 46
#define RB1_5 45
#define RB1_6 44
#define RB1_7 43
#define RB1_8 42

//Relay Board2
#define RB2_1 41
#define RB2_2 40
#define RB2_3 39
#define RB2_4 38
#define RB2_5 36
#define RB2_6 37
#define RB2_7 35
#define RB2_8 34

#define TIMER_ALARM_PIN RB1_1
#define TEMP_ALARM_PIN RB1_2

//Wheatstone Bridgets
#define WB_R2 2000
#define WB_R3 2000
#define WB_R4 100
#define WB_Rs 5
#define WB_OpAmpGn 51

///////////////////////////////
// SD Card
///////////////////////////////
#define SD_PIN 53

///////////////////////////////
// Real Time Clock
///////////////////////////////
#define DS3231_I2C_ADDR 0x68

///////////////////////////////
// Thermocouple
///////////////////////////////
#define HLT_TC_VIN A12
#define MLT_TC_VIN A13
#define BK_TC_VIN A14

///////////////////////////////
// Pump
///////////////////////////////
#define PUMP1_VIN A10	
#define PUMP2_VIN A11


///////////////////////////////
// Main Screen
///////////////////////////////

//LCD - Product
#define MAIN_LCD_I2C_ADDR    0x27  // Define I2C Address where the PCF8574A is 0x27

//LCD - DevBoard
//#define MAIN_LCD_I2C_ADDR    0x30 //27  // Define I2C Address where the PCF8574A is 0x27

//Encoder - Product
#define MAIN_ENC_A 32
#define MAIN_ENC_B 31
#define MAIN_ENC_SW 33

//Encoder - DevBoard
/*#define MAIN_ENC_A 29
#define MAIN_ENC_B 28
#define MAIN_ENC_SW 30*/

#define MAIN_ENC_DEG_PER_NOTCH 4

///////////////////////////////
// Hot Liquor Tank
///////////////////////////////

//Control
#define HLT_SOLENOID_1 53			//Ctrl Digital out
#define HLT_SOLENOID_2 52			//Ctrl Digital out

//LCD - Product
#define HLT_LCD_I2C_ADDR    0x26 

//LCD - DevBoard
//#define HLT_LCD_I2C_ADDR    0x27 //26  // Define I2C Address where the PCF8574A is 0x27

//Encoder - Product
#define HLT_ENC_A 29
#define HLT_ENC_B 28
#define HLT_ENC_SW 30

//Encoder - DevBoard
/*#define HLT_ENC_A 32
#define HLT_ENC_B 31
#define HLT_ENC_SW 33*/

#define HLT_ENC_DEG_PER_NOTCH 4

//RTD
#define HLT_RTD_Vs_AN A0
#define HLT_RTD_BP_AN A1
#define HLT_RTD_OP_AN A2

///////////////////////////////
// Mash Lauter Tun
///////////////////////////////

//Control
#define MLT_SOLENOID_1 51			//Ctrl Digital out
#define MLT_SOLENOID_2 50			//Ctrl Digital out

//LCD
#define MLT_LCD_I2C_ADDR    0x25  // Define I2C Address where the PCF8574A is 0x27

//Encoder
#define MLT_ENC_A 26
#define MLT_ENC_B 25
#define MLT_ENC_SW 27

#define MLT_ENC_DEG_PER_NOTCH 4

//RTD
#define MLT_RTD_Vs_AN A0
#define MLT_RTD_BP_AN A3
#define MLT_RTD_OP_AN A4

///////////////////////////////
// Boil Kettle
///////////////////////////////

//Control
#define BK_SOLENOID_1 49			//Ctrl Digital out
#define BK_SOLENOID_2 48			//Ctrl Digital out

//LCD
#define BK_LCD_I2C_ADDR    0x23  // Define I2C Address where the PCF8574A is 0x27

//Encoder

#define BK_ENC_A 23
#define BK_ENC_B 22
#define BK_ENC_SW 24
#define BK_ENC_DEG_PER_NOTCH 4

//RTD
#define BK_RTD_Vs_AN A5
#define BK_RTD_BP_AN A6
#define BK_RTD_OP_AN A7

#endif
