#include <LiquidCrystal_I2C.h>

#include <Wire.h>

#include <core_build_options.h>

#include <swRTC.h>

swRTC rtc;  //클래스 개체 선언

LiquidCrystal_I2C lcd(0x27,16,2);

 int state=0;

 int value=50;

 int sound;

 int count=0;

 

const int swC=1;

const int swD=7;

const int swE=5;

 

void setup() {

   pinMode(8,OUTPUT);

   pinMode(9,OUTPUT);

   pinMode(10,OUTPUT);

   pinMode(swC,INPUT_PULLUP);

   pinMode(swD,INPUT_PULLUP);

   pinMode(swE,INPUT_PULLUP);

   Serial.begin(9600);

  rtc.stopRTC();            //정지

  rtc.setTime(18, 42, 40);  //시, 분, 초

  rtc.setDate(11,12, 2019); //일, 월, 년

  rtc.startRTC();           //시작

 

  lcd.init(); // LCD 설정

  lcd.clear();      // LCD를 모두 지운다.

  lcd.backlight();

}

 

 

 

void loop() {

   sound=analogRead(A0);

 if(sound>value){

  state=1-state;

  digitalWrite(8,state);

  delay(1000);

  digitalWrite(9,state);

  delay(1000);

  digitalWrite(10,state);

 }

 if(digitalRead(swC)==LOW)

 {

    state=1-state;

  digitalWrite(8,state);

  delay(1000);

  digitalWrite(9,state);

  delay(1000);

  digitalWrite(10,state);

 }

 if(digitalRead(swD)==LOW)

 {

   digitalWrite(8,HIGH);

   digitalWrite(9,HIGH);

   digitalWrite(10,LOW);

   delay(10000);

   digitalWrite(8,LOW);

   digitalWrite(9,LOW);

   digitalWrite(10,LOW);

 }

 

 

  if(digitalRead(swE)==LOW)

 {

   if(count==0)

   {

        

    lcd.noBacklight();

    count++;

    delay(1000);

   }

   else if(count==1)

   {

    lcd.backlight();

    count=0;

    delay(1000);

   }

 }

 

  

 

 

 

  lcd.setCursor(0,0);

  lcd.print(rtc.getHours());

  lcd.setCursor(2,0);

  lcd.print("h");

  lcd.setCursor(3,0);

  lcd.print(":");

  lcd.setCursor(4,0);

  lcd.print(rtc.getMinutes());

  lcd.setCursor(6,0);

  lcd.print("m");

  lcd.setCursor(9,0);

  lcd.print(rtc.getYear());

  lcd.setCursor(13,0);

  lcd.print("y");

  lcd.setCursor(0,1);

  lcd.print(rtc.getMonth());

  lcd.print("/");

  lcd.setCursor(2,1);

  lcd.setCursor(3,1);

  lcd.print(rtc.getDay());

  lcd.setCursor(5,1);

  lcd.print("day");

}
