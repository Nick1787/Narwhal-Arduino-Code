#include <LiquidCrystal.h>

#include <ClickEncoder.h>



// include the library code:
#include <Arduino.h>
#include <TimerOne.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#define LCD_1_BACKLIGHT_PIN     3
#define LCD_1_En_pin  2
#define LCD_1_Rw_pin  1
#define LCD_1_Rs_pin  0
#define LCD_1_D4_pin  4
#define LCD_1_D5_pin  5
#define LCD_1_D6_pin  6
#define LCD_1_D7_pin  7

#define HLT_ENC_A 22
#define HLT_ENC_B 23
#define HLT_ENC_SW 24
#define HLT_ENC_DEG_PER_NOTCH 4

#define MAIN_ENC_A 31
#define MAIN_ENC_B 32
#define MAIN_ENC_SW 33
#define MAIN_ENC_DEG_PER_NOTCH 1

// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd( 0x27, LCD_1_En_pin , LCD_1_Rw_pin, LCD_1_Rs_pin, LCD_1_D4_pin, LCD_1_D5_pin, LCD_1_D6_pin, LCD_1_D7_pin );
LiquidCrystal_I2C lcd2( 0x26, LCD_1_En_pin , LCD_1_Rw_pin, LCD_1_Rs_pin, LCD_1_D4_pin, LCD_1_D5_pin, LCD_1_D6_pin, LCD_1_D7_pin );

ClickEncoder *ENC1;
int16_t last1, value1;
//ClickEncoder *ENC2;
int16_t last2, value2;

void timerIsr() {
  ENC1->service();
  //ENC2->service();
}

void setup() { 
  
  ENC1 = new ClickEncoder(HLT_ENC_A, HLT_ENC_B, HLT_ENC_SW, HLT_ENC_DEG_PER_NOTCH);
  //ENC2 = new ClickEncoder(MAIN_ENC_A, MAIN_ENC_B, MAIN_ENC_SW, MAIN_ENC_DEG_PER_NOTCH);
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr); 
  last1 = -1;
  last2 = -1;
  
  pinMode(22,OUTPUT);
  digitalWrite(22, HIGH);       // turn on pullup resistors
  
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  //analogReference(INTERNAL1V1);
  
  Serial.begin(9600);
  //Setup the LCD
  lcd.setBacklightPin(LCD_1_BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.begin (20,4);
  
  lcd2.setBacklightPin(LCD_1_BACKLIGHT_PIN,POSITIVE);
  lcd2.setBacklight(HIGH);
  lcd2.begin (20,4);

  lcd.setCursor(4,1);
  lcd.print("Narwhal vX.Y");
  lcd.setCursor(2,2);
  lcd.print("Established 2015");
    
  lcd2.setCursor(4,1);
  lcd2.print("Narwhal vX.Y");
  lcd2.setCursor(2,2);
  lcd2.print("Established 2015");  
  delay(3000);
  lcd.clear();
  lcd2.clear();
}

unsigned long lastdisplayUpdate = 0;
unsigned long displayUpdateFrequencyMillis = 500;

void loop() {
  
  value1 += ENC1->getValue();
  //value2 += ENC2->getValue();
  if (value1 != last1) {
    last1 = value1;
  }
  if (value2 != last2) {
    last2 = value2;
  }
  
  //uPDATE dISPAY
  unsigned long currentMillis = millis();

  if (currentMillis > (lastdisplayUpdate + displayUpdateFrequencyMillis))
  {
    lastdisplayUpdate = currentMillis;
    float time_s = (float)currentMillis/1000;
    
    lcd.setCursor(0,0);
    lcd.print("Time (s):");
    lcd.setCursor(10,0);
    lcd.print(time_s);
    lcd.setCursor(0,2);
    lcd.print("ENC:");
    lcd.setCursor(10,2);
    lcd.print(value1);
    
    lcd2.setCursor(0,0);
    lcd2.print("Time (ms):");
    lcd2.setCursor(10,0);
    lcd2.print(currentMillis);
    lcd2.setCursor(0,2);
    lcd2.print("ENC:");
    lcd2.setCursor(10,2);
    lcd2.print(value2);
  }
  
  
  

        
}


