#include <SoftwareSerial.h>  
SoftwareSerial BT(11,12);    
  
char val;  
String recieveData = "";   
bool startRecieve = false;  

const byte trigPin=5; //Output pin to trigger ultra sound
const byte echoPin=6; //Input pin to receive echo pulse

void setup()  
{ 
  pinMode(trigPin, OUTPUT); //Arduino pin default input 
  Serial.begin(9600);   
  BT.begin(9600); //HC-06 預設 baud  
}  
  
void loop()  
{
  unsigned long d=ping()/58; //calculate distance
  Serial.println(d);
  if(d>10 && d<100){
    Serial.println("cm");
    BT.print("Y");
  }
  
  delay(1000);  

  if (Serial.available()) {
    val = Serial.read();
    BT.print(val);
  }
  
  while(BT.available()) //如果有收到資料  
  {  
    startRecieve = true;  
    val=BT.read(); //每次接收一個字元  
    recieveData += val; //字元組成字串  
    BT.write(byte(val)); //把每次收到的字元轉成byte封包傳至手機端  
    delay(200);  //每次傳輸間隔，如果太短會造成資料遺失或亂碼  
  }

    
  if(startRecieve)  
  {  
    startRecieve = false;  
    Serial.println(recieveData); //呈現收到字串  
    recieveData = "";  
  }  
    delay(300);  
}  
unsigned long ping() { //send 10us pulse to HC-SR04 trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  //sustain at least 10us HIGH pulse
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH);
  }
