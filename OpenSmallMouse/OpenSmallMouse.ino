
#include <SoftwareSerial.h>
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(7, 8); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void printDetail(uint8_t type, int value);

bool play=false;

const byte trigPin=5; //Output pin to trigger ultra sound
const byte echoPin=6; //Input pin to receive echo pulse

void setup() {
  pinMode(trigPin, OUTPUT);
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
}

void loop() {
  unsigned long d=ping()/58; //calculate distance
  Serial.print("d1:");
  Serial.println(d);
  
  if(d>4 && d<1000)
  {
   play = true;
   Serial.println("play");
  }
  if(play)
  {
    myDFPlayer.volume(30);
    myDFPlayer.play(2);
    play = false;
    delay(6000);
   }
   else{
    myDFPlayer.stop();
    }
  

    delay(1000);
}

unsigned long ping() { //send 10us pulse to HC-SR04 trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  //sustain at least 10us HIGH pulse
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH);
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



