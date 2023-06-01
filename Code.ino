/*
The circuit:
**flex no.1 - pin A0
**flex no.2 - pin A1
**flex no.3 - pin A2
**flex no.4 - pin A3
** Audio Out - pin 9
**SD card attached to SPI bus as follows:
** MOSI - pin 11
** MISO - pin 12
** CLK - pin 13
** CS - pin 4
** Display attached pin follows
** LCD RS pin to digital pin 8
** LCD Enable pin to digital pin 7
** LCD D4 pin to digital pin 6
** LCD D5 pin to digital pin 5
** LCD D6 pin to digital pin 3
** LCD D7 pin to digital pin 2
** LCD R/W pin to ground
** LCD VSS pin to ground
** LCD VCC pin to 5V

** 10K resistor:
** ends to +5V and ground
*/

#include "SD.h" //Lib to read SD card
#include "TMRpcm.h" //Lib to play auido
#include "SPI.h" //SPI lib for SD card
//#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define SD_ChipSelectPin 4 //Chip select is pin number 4
TMRpcm music; //Lib object is named "music"

const int flexpin_1 = A0;
const int flexpin_2 = A1;
const int flexpin_3 = A2;
const int flexpin_4 = A3;
//const int rs =8, en =7, d4=6, d5=5, d6=3, d7=2;

//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float f1,f2,f3,f4;
void setup()
{
  //lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  music.speakerPin = 9; //Auido out on pin 9
  Serial.begin(9600); //Serial Com for debugging
  if (!SD.begin(SD_ChipSelectPin))
  {
    Serial.println("SD fail");
    lcd.print("SD fail");
    delay(1000);
    lcd.clear();
    return;
  }

  music.setVolume(5); // 0 to 7. Set volume level
  music.quality(1); // Set 1 for 2x oversampling Set 0 for normal
  lcd.print("Welcome !!!");
  delay(2000);
  //lcd.clear();
}

void loop()
{
  lcd.setCursor(0, 1);
  Serial.println("READING.....");
  lcd.print("READING.....");
  delay(1000);
  lcd.clear();
  f1=analogRead(flexpin_1);
  f2=analogRead(flexpin_2);
  f3=analogRead(flexpin_3);
  f4=analogRead(flexpin_4);
  Serial.print("f1 - ");
  Serial.println(f1);
  Serial.print("f2 - ");
  Serial.println(f2);
  Serial.print("f3 - ");
  Serial.println(f3);
  Serial.print("f4 - ");
  Serial.println(f4);
  
  
//1st finger UP
  while (f1 <935 && f2>745 && f3>920 && f4 >963 ) //music play 1
  {
    Serial.println("HELLO !!");
    lcd.print("HELLO !!");
    music.play("1.wav"); delay(4000);
    delay(4000);
    lcd.clear();
    f1=analogRead(flexpin_1);
    f2=analogRead(flexpin_2);
    f3=analogRead(flexpin_3);
    f4=analogRead(flexpin_4);
  }

//2nd finger UP
  while (f1 <935 && f2<745 && f3>920 && f4 >963 ) //music play 1
  {
    Serial.println("HOW ARE YOU?");
    lcd.print("HOW ARE YOU?");
    music.play("2.wav");delay(4000);
    delay(4000);
    lcd.clear();
    f1=analogRead(flexpin_1);
    f2=analogRead(flexpin_2);
    f3=analogRead(flexpin_3);
    f4=analogRead(flexpin_4);
  }

//3rd finger UP
  while (f1 <935 && f2<745 && f3<920 && f4 >963 ) //music play 3
  {
    Serial.println("I NEED HELP");
    lcd.print("I NEED HELP");
    music.play("3.wav");delay(4000);
    delay(4000);
    lcd.clear();
    f1=analogRead(flexpin_1);
    f2=analogRead(flexpin_2);
    f3=analogRead(flexpin_3);
    f4=analogRead(flexpin_4);
  }

//4th finger UP
  while (f1 <935 && f2<745 && f3<920 && f4 <963 ) //music play 4
  {
    Serial.println("I NEED WATER");
    lcd.print("I NEED WATER");
    music.play("4.wav");delay(4000);
    delay(4000);
    lcd.clear();
    f1=analogRead(flexpin_1);
    f2=analogRead(flexpin_2);
    f3=analogRead(flexpin_3);
    f4=analogRead(flexpin_4);
  }

//2nd and 3rd fingers UP
  while (f1 >935 && f2<745 && f3<920 && f4 >963 ) //music play 5
  {
    Serial.println("THANK YOU");
    lcd.print("THANK YOU");
    music.play("5.wav");delay(4000);
    delay(4000);
    lcd.clear();
    f1=analogRead(flexpin_1);
    f2=analogRead(flexpin_2);
    f3=analogRead(flexpin_3);
    f4=analogRead(flexpin_4);
  }

//3rd and 4th fingers UP
  while (f1 >935 && f2>745 && f3<920 && f4 <963 ) //music play 6
  {
    Serial.println("BYE !!");
    lcd.print("BYE !!"); 
    music.play("6.wav");delay(4000);
    delay(4000);
    lcd.clear();
    f1=analogRead(flexpin_1);
    f2=analogRead(flexpin_2);
    f3=analogRead(flexpin_3);
    f4=analogRead(flexpin_4);
  }

//2nd, 3rd, and 4th fingers UP
   while (f1 >935 && f2<745 && f3<920 && f4 <963 ) //music play 7
  {
    Serial.println("VINOD SIR TEACHES AMAZING!");
    lcd.print("VINOD SIR");
    lcd.setCursor(0, 1);
    lcd.print("TEACHES AMAZING!");
    music.play("7.wav");delay(4000);
    delay(4000);
    lcd.clear();
    f1=analogRead(flexpin_1);
    f2=analogRead(flexpin_2);
    f3=analogRead(flexpin_3);
    f4=analogRead(flexpin_4);
  }

//1st and 4th fingers UP
   while (f1 <935 && f2>745 && f3>920 && f4 <963 ) //music play 8
  {
    Serial.println("SANKET SIR IS THE BEST !!!");
    lcd.print("SANKET SIR IS");
    lcd.setCursor(0, 1);
    lcd.print("THE BEST !!!");
    music.play("8.wav");delay(4000);
    delay(4000);
    lcd.clear();
    f1=analogRead(flexpin_1);
    f2=analogRead(flexpin_2);
    f3=analogRead(flexpin_3);
    f4=analogRead(flexpin_4);
  }
}
