#include <SoftwareSerial.h>
const byte trigPin1=3; //Output pin to trigger ultra sound
const byte echoPin1=4; //Input pin to receive echo pulse
const byte trigPin2=5; //Output pin to trigger ultra sound
const byte echoPin2=6; //Input pin to receive echo pulse
const byte trigPin3=7; //Output pin to trigger ultra sound
const byte echoPin3=8; //Input pin to receive echo pulse
const byte trigPin4=9; //Output pin to trigger ultra sound
const byte echoPin4=10; //Input pin to receive echo pulse
void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(3, HIGH);
  unsigned long d1=ping1()/58; //calculate distance
  Serial.print("d1:");
  Serial.println(d1);
  unsigned long d2=ping2()/58; //calculate distance
  Serial.print("d2:");
  Serial.println(d2);
  unsigned long d3=ping3()/58; //calculate distance
  Serial.print("d3:");
  Serial.println(d3);
  unsigned long d4=ping4()/58; //calculate distance
  Serial.print("d4:");
  Serial.println(d4);
  delay(1000);  
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

  unsigned long ping4() { //send 10us pulse to HC-SR04 trigger pin
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);  //sustain at least 10us HIGH pulse
  digitalWrite(trigPin4, LOW);
  return pulseIn(echoPin4, HIGH);
  }
