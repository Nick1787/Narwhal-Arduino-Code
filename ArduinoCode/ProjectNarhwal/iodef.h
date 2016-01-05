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
#define RB2_5 37
#define RB2_6 36
#define RB2_7 35
#define RB2_8 34

#define TIMER_ALARM_PIN RB1_1
#define TEMP_ALARM_PIN RB1_2

///////////////////////////////
// Main Screen
///////////////////////////////

//LCD
#define MAIN_LCD_I2C_ADDR    0x27  // Define I2C Address where the PCF8574A is 0x27

//Encoder
#define MAIN_ENC_A 22
#define MAIN_ENC_B 23
#define MAIN_ENC_SW 24
#define MAIN_ENC_DEG_PER_NOTCH 4

///////////////////////////////
// Hot Liquor Tank
///////////////////////////////

//Control
#define HLT_SOLENOID_1 53			//Ctrl Digital out
#define HLT_SOLENOID_2 52			//Ctrl Digital out

//LCD
#define HLT_LCD_I2C_ADDR    0x26  // Define I2C Address where the PCF8574A is 0x27

//Encoder
#define HLT_ENC_A 31
#define HLT_ENC_B 32
#define HLT_ENC_SW 33
#define HLT_ENC_DEG_PER_NOTCH 4

///////////////////////////////
// Mash Lauter Tun
///////////////////////////////

//Control
#define MLT_SOLENOID_1 51			//Ctrl Digital out
#define MLT_SOLENOID_2 50			//Ctrl Digital out

//LCD
#define MLT_LCD_I2C_ADDR    0x25  // Define I2C Address where the PCF8574A is 0x27

//Encoder
#define MLT_ENC_A 25
#define MLT_ENC_B 26
#define MLT_ENC_SW 27
#define MLT_ENC_DEG_PER_NOTCH 4

//RTD
#define MLT_RTD_R2C_X[36] = {80.31, 84.27, 88.22, 92.16, 96.09, 100, 103.9, 107.79, 111.67, 115.54, 119.4, 123.24, 127.08, 130.9, 134.71, 138.51, 142.29, 146.07, 149.83, 153.58, 157.33, 161.05, 164.77, 168.48, 172.17, 175.86, 179.53, 183.19, 186.84, 190.47, 194.1, 197.71, 201.31, 204.9, 208.48, 212.05}
#define MLT_RTD_R2C_Z[36] ={-50, -40, -30, -20, -10, 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300}

///////////////////////////////
// Boil Kettle
///////////////////////////////

//Control
#define BK_SOLENOID_1 49			//Ctrl Digital out
#define BK_SOLENOID_2 48			//Ctrl Digital out

//LCD
#define BK_LCD_I2C_ADDR    0x23  // Define I2C Address where the PCF8574A is 0x27

//Encoder
#define BK_ENC_A 28
#define BK_ENC_B 29
#define BK_ENC_SW 30
#define BK_ENC_DEG_PER_NOTCH 4


#endif
