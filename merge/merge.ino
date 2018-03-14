#include <SoftwareSerial.h>   // 引用程式庫
int smallLedPin1=A1;
int smallLedPin2=A2;
int smallLedPin3=A3;
int smallLedPin4=A4;
byte soundPin=A0;
byte soundValue=0;
bool storeLed=false;
char onLed=HIGH;
char offLed=LOW;

// 定義連接藍牙模組的序列埠
SoftwareSerial BT(6, 7); // 接收腳, 傳送腳
char val;  // 儲存接收資料的變數

void setup() {
  Serial.begin(9600);   // 與電腦序列埠連線
  Serial.println("BT is ready!");
  //pinMode(soundPin, INPUT);
  pinMode(smallLedPin1, OUTPUT);
  pinMode(smallLedPin2, OUTPUT);
  pinMode(smallLedPin3, OUTPUT);
  pinMode(smallLedPin4, OUTPUT);
  

    
  // 藍牙透傳模式的預設連線速率。
  BT.begin(9600);
}

void loop() {
  twinkleLed();
 
  // 若收到「序列埠監控視窗」的資料，則送到藍牙模組
  


  /*
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  if (BT.available()) {
    val = BT.read();
    Serial.print(val);
  }
  */
  
}
  void twinkleLed(){
    int delaySec=200;
    digitalWrite(smallLedPin1, onLed);
    digitalWrite(smallLedPin2, offLed);
    digitalWrite(smallLedPin3, offLed);
    digitalWrite(smallLedPin4, offLed);
    delay(delaySec);
    digitalWrite(smallLedPin2, onLed);
    delay(delaySec);
    digitalWrite(smallLedPin3, onLed);
    storeLed=true;
    detectVoice();
    delay(delaySec);
    storeLed=false;
    digitalWrite(smallLedPin4, onLed);
    delay(delaySec);
    digitalWrite(smallLedPin4, offLed);
    storeLed=true;
    detectVoice(); 
    delay(delaySec);
    storeLed=false;
    digitalWrite(smallLedPin3, offLed);
    delay(delaySec);
    digitalWrite(smallLedPin2, offLed);
    delay(delaySec);
    digitalWrite(smallLedPin1, offLed);
    delay(delaySec);
  }
 void detectVoice()
  {
    soundValue = analogRead(soundPin);
    //Serial.println(val);
    if(soundValue>50 && storeLed == true){
    Serial.println(soundValue);
    BT.print(soundValue);
    }
  }

