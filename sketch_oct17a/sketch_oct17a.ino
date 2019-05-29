#include <Servo.h>

Servo myservo; // 建立Servo物件，控制伺服馬達

void setup() 
{ 
  myservo.attach(9); // 連接數位腳位9，伺服馬達的訊號線
  Serial.begin(9600);
} 

void loop() 
{
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    switch (inByte) {
      case '1':
        myservo.write(70);
        delay(1000);          // Wait 1 second
        break;
      case '2':
        myservo.write(150);
        delay(1000);          // Wait 1 second
        break;
      case '3':
        myservo.write(100);
        delay(1000);          // Wait 1 second
        break;
    }
  }
}


