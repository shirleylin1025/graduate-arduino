#include <SoftwareSerial.h>  
SoftwareSerial BT(11,12);
int LIGHTVAL = 200;    
  
char val;  
String recieveData = "";   
bool startRecieve = false;  


void setup()  
{ 
  pinMode(A1, INPUT);
  Serial.begin(9600);   
  BT.begin(9600); //HC-06 預設 baud  
}  
  
void loop()  
{
  int lightNum = analogRead(A1);
  Serial.print("light:");
  Serial.println(lightNum);
  if(lightNum>LIGHTVAL){
    Serial.println("PASS");
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
