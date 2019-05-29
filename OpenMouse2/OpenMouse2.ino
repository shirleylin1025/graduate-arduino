#include <SoftwareSerial.h>
const byte trigPin1=2; //Output pin to trigger ultra sound
const byte echoPin1=3; //Input pin to receive echo pulse
const byte trigPin2=6; //Output pin to trigger ultra sound
const byte echoPin2=7; //Input pin to receive echo pulse
const byte trigPin3=8; //Output pin to trigger ultra sound
const byte echoPin3=9; //Input pin to receive echo pulse
const byte ledPin1=A0;
const byte ledPin2=A1;
const byte ledPin3=A2;
bool LED1=false, LED2=false, LED3=false;

SoftwareSerial BT(A3, A4); // 接收腳, 傳送腳
SoftwareSerial BT2(4, 5); // 接收腳, 傳送腳
char val;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  if(LED1==false){
    BT.begin(9600);
  }
  if (BT.available()) {
    val = BT.read();
    Serial.print(val);
    LED1 = true;
  }
  // put your main code here, to run repeatedly:
  unsigned long d1=ping1()/58; //calculate distance
  Serial.print("d1:");
  Serial.println(d1);
  if(d1>10 && d1 < 3000){
    digitalWrite(ledPin1, HIGH);
    LED1=true;
    }
  unsigned long d2=ping2()/58; //calculate distance
  Serial.print("d2:");
  Serial.println(d2);
  if(d2>10 && d2 < 3000 && LED1){
    digitalWrite(ledPin2, HIGH);
    LED2=true;
    }
  unsigned long d3=ping3()/58; //calculate distance
  Serial.print("d3:");
  Serial.println(d3);
  if(d3>10 && d3 < 3000 && LED1 && LED2){
    digitalWrite(ledPin3, HIGH);
    LED3=true;
    }
    
  if(LED1 && LED2 && LED3){
    BT.begin(9600);
    BT.print("all HIGH");
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

