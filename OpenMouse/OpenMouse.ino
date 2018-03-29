#include <SoftwareSerial.h>
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(4, 5); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
DFRobotDFPlayerMini myDFPlayer2;
void printDetail(uint8_t type, int value);

const byte trigPin1=2; //Output pin to trigger ultra sound
const byte echoPin1=3; //Input pin to receive echo pulse
const byte trigPin2=6; //Output pin to trigger ultra sound
const byte echoPin2=7; //Input pin to receive echo pulse
const byte trigPin3=10; //Output pin to trigger ultra sound
const byte echoPin3=11; //Input pin to receive echo pulse
const byte ledPin1=A0;
const byte ledPin2=A1;
const byte ledPin3=A2;
bool LED1=false, LED2=false, LED3=false;



SoftwareSerial BT(A3, A4); // 接收腳, 傳送腳
char val;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  Serial.begin(9600); 
  mySoftwareSerial.begin(9600);
  //mySoftwareSerial2.begin(19200);
  
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }

/*
   

  */
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
  //myDFPlayer.play(2);  //Play the first mp3

}

void loop() {
  // put your main code here, to run repeatedly:
  static unsigned long timer = millis();
  timer = millis();
  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }
  /*
 
  */
  unsigned long d1=ping1()/58; //calculate distance
  Serial.print("d1:");
  Serial.println(d1);
  digitalWrite(ledPin1, HIGH);
  if(LED1 ==false && d1>10 && d1 < 3000){
    myDFPlayer.play(1);
    delay(5000);
    myDFPlayer.stop();
    SoftwareSerial mySoftwareSerial2(8, 9); // RX, TX
    mySoftwareSerial2.begin(9600);
    Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
    if (!myDFPlayer2.begin(mySoftwareSerial2)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
    }
    Serial.println(F("DFPlayer Mini online."));
    if (myDFPlayer2.available()) {
    printDetail(myDFPlayer2.readType(), myDFPlayer2.read()); //Print the detail message from DFPlayer to handle different errors and states
    myDFPlayer2.volume(30);
    myDFPlayer2.play(2);
  }
   
    LED1=true;
    }
    
  digitalWrite(ledPin2, HIGH);//笑聲1播完
    
  unsigned long d2=ping2()/58; //calculate distance
  Serial.print("d2:");
  Serial.println(d2);
  if(d2>10 && d2 < 3000 && LED1){
//    myDFPlayer2.play(2);
    delay(5000);
//    myDFPlayer2.stop();
    LED2=true;
    }
  digitalWrite(ledPin3, HIGH);//笑聲2播完
  unsigned long d3=ping3()/58; //calculate distance
  Serial.print("d3:");
  Serial.println(d3);
  if(d3>10 && d3 < 3000 && LED1 && LED2){
    //笑聲3
    LED3=true;
    }
    delay(1000);
    /*
  if(Serial.read()=="OK"){ //笑聲三播完
    BT.begin(9600);
    BT.print("all HIGH");BT.begin(9600);
    BT.print("all HIGH");
  }
  */
   
  if(LED1 && LED2 && LED3){
    
    }
  
}
  
  unsigned long ping1() { //send 10us pulse to HC-SR04 trigger pin
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);  //sustain at least 10us HIGH pulse
  digitalWrite(trigPin1, LOW);
  return pulseIn(echoPin1, HIGH);
  }
  
  unsigned long ping2() { //send 10us pulse to HC-SR04 trigger pin
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);  //sustain at least 10us HIGH pulse
  digitalWrite(trigPin2, LOW);
  return pulseIn(echoPin2, HIGH);
  }

  unsigned long ping3() { //send 10us pulse to HC-SR04 trigger pin
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);  //sustain at least 10us HIGH pulse
  digitalWrite(trigPin3, LOW);
  return pulseIn(echoPin3, HIGH);
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

