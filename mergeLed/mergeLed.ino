#include <SoftwareSerial.h>
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(A3, A4); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

SoftwareSerial BT(A1, A2); // 接收腳, 傳送腳
int val = 0;
int totalSound=0;
int ledPin1=1;
int ledPin2=2;
int ledPin3=3;
int ledPin4=4;
int ledPin5=5;
int ledPin6=6;
int ledPin7=7;
int ledPin8=8;
int ledPin9=9;
int ledPin10=10;
int ledPin11=11;
int ledPin12=12;
int ledPin13=13;
int ledPin14=A5;
int ledPin15=A0;


void setup() {
  for(int i=1; i<=13 ;i++){
    pinMode(i, OUTPUT);
    }
  pinMode(A5, OUTPUT);
  pinMode(A0, OUTPUT);
  
  Serial.begin(9600);
  
  mySoftwareSerial.begin(9600);
  
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
  //myDFPlayer.play(2);  //Play the first mp3

}

void loop() {
  // put your main code here, to run repeatedly
  static unsigned long timer = millis();

  
  char qq = Serial.read();
  if (qq== '0') {
    totalSound+=90;
    myDFPlayer.play(1);
  }
 
  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }
  //static unsigned long timer = millis();

  BT.begin(9600);
  if (BT.available()) {
    val = BT.read();
    Serial.print("val:");
    Serial.println(val);
    timer = millis();
    if (val > 49 && totalSound<3200) {
      //Serial.println(val);
      totalSound+=val;
      Serial.print("totalSound:");
      Serial.println(totalSound);
      myDFPlayer.play(1);
    } else if (val == '0') {
      BT.println("LED OFF");
    }
  }
  setLed(totalSound);
}

void setLed(int total){
  digitalWrite(ledPin2,HIGH);
  //Serial.print("Total");
  //Serial.println(total);
  if(total>50 && total<=200){
    for(int i=3; i<14; i++){
      digitalWrite(i, LOW);
    }
    digitalWrite(ledPin14, LOW);
    digitalWrite(ledPin15, LOW);
    Serial.print("SetTotalSound:");
    Serial.println(total);
  }
  else if(total>200 && total<=400){
    for(int i=1; i<3; i++){
      digitalWrite(i, HIGH);
    }
    for(int i=3; i<14; i++){
      digitalWrite(i, LOW);
    }
    digitalWrite(ledPin14, LOW);
    digitalWrite(ledPin15, LOW);
    Serial.print("SetTotalSound2:");
    Serial.println(total);
  }
  else if(total>400 && total<=600){
   for(int i=1; i<4; i++){
      digitalWrite(i, HIGH);
   }
   for(int i=4; i<14; i++){
    digitalWrite(i, LOW);
   }
   digitalWrite(ledPin14, LOW);
   Serial.println(totalSound);
  }
  else if(total>600 && total<=800){
    for(int i=1; i<5; i++){
      digitalWrite(i, HIGH);
    }
    for(int i=5; i<14; i++){
      digitalWrite(i, LOW);
    }
    digitalWrite(ledPin15, LOW);
    digitalWrite(ledPin14, LOW);
    Serial.println(totalSound);
  }
  else if(total>800 && total<=1000){
    for(int i=1; i<6; i++){
      digitalWrite(i, HIGH);
    }
    for(int i=6; i<14; i++){
      digitalWrite(i, LOW);
    }
    digitalWrite(ledPin14, LOW);
    digitalWrite(ledPin15, LOW);
    Serial.println(totalSound);
  }
  else if(total>1000 && total<=1200){
    for(int i=1; i<7; i++){
      digitalWrite(i, HIGH);
    }
    for(int i=7; i<14; i++){
     // digitalWrite(i, LOW);
    }
    digitalWrite(ledPin14, LOW);
    digitalWrite(ledPin15, LOW);
    Serial.println(totalSound);
  }
  else if(total>1200 && total<=1400){
    for(int i=1; i<8; i++){
      digitalWrite(i, HIGH);
    }
    for(int i=8; i<14; i++){
      digitalWrite(i, LOW);
    }
    digitalWrite(ledPin14, LOW);
    digitalWrite(ledPin15, LOW);
    Serial.println(totalSound);
  }
  else if(total>1400 && total<=1600){
    for(int i=1; i<9; i++){
      digitalWrite(i, HIGH);
    }
    for(int i=9; i<14; i++){
      digitalWrite(i, LOW);
    }
    digitalWrite(ledPin14, LOW);
    digitalWrite(ledPin15, LOW);
    Serial.println(totalSound);
  }
  else if(total>1600 && total<=1800){
    for(int i=1; i<10; i++){
      digitalWrite(i, HIGH);
    }
    for(int i=10; i<14; i++){
      //digitalWrite(i, LOW);
    }
    digitalWrite(ledPin14, LOW);
    digitalWrite(ledPin15, LOW);
    Serial.println(totalSound);
  }
  else if(total>1800 && total<=2000){
    for(int i=1; i<11; i++){
      digitalWrite(i, HIGH);
    }
    for(int i=11; i<14; i++){
      digitalWrite(i, LOW);
    }
    digitalWrite(ledPin14, LOW);
    digitalWrite(ledPin15, LOW);
    Serial.println(totalSound);
  }
  else if(total>2000 && total<=2200){
    for(int i=1; i<12; i++){
      digitalWrite(i, HIGH);
    }
    for(int i=12; i<14; i++){
      digitalWrite(i, LOW);
    }
    digitalWrite(ledPin15, LOW);
    digitalWrite(ledPin14, LOW);
    Serial.println(totalSound);
  }
  else if(total>2200 && total<=2400){
    for(int i=1; i<13; i++){
      digitalWrite(i, HIGH);
    }
    for(int i=13; i<14; i++){
      digitalWrite(i, LOW);
    }
    digitalWrite(ledPin14, LOW);
    digitalWrite(ledPin15, LOW);
    Serial.println(totalSound);
  }
  else if(total>2400 && total<=2600){
    for(int i=1; i<14; i++){
      digitalWrite(i, HIGH);
    }
    digitalWrite(ledPin14, LOW);
    digitalWrite(ledPin15, LOW);
    Serial.println(totalSound);
  }
  else if(total>2600 && total<=2800){
    for(int i=1; i<14; i++){
      digitalWrite(i, HIGH);
    }
    digitalWrite(A5, HIGH);
    digitalWrite(A0, LOW);
    Serial.println(totalSound);
  }
  else if(total>2800){
    for(int i=1; i<14; i++){
      digitalWrite(i, HIGH);
    }
    digitalWrite(A0, HIGH);
    digitalWrite(A5, HIGH);
    Serial.println(totalSound);
    myDFPlayer.play(2);
    delay(10000);
    }
  }
void printDetail(uint8_t type, int value){
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}
