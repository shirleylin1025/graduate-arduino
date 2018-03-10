#include <SoftwareSerial.h>

SoftwareSerial BT(A1, A2); // 接收腳, 傳送腳
char val;  // 儲存接收資料的變數

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
int ledPin13=10;
int ledPin14=A5;


void setup() {
  for(int i=1; i<=13 ;i++){
    pinMode(i, OUTPUT);
    }
  pinMode(ledPin14, OUTPUT);
  pinMode(A3,OUTPUT);
  BT.begin(9600);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  setLed();

  if (BT.available()) {
    val = BT.read();
    if (val == '1') {
      digitalWrite(A3, HIGH);
      // 回應命令發送端，告知「已開燈」
      BT.println("LED ON");
    } else if (val == '0') {
      digitalWrite(A3, LOW);
      // 回應命令發送端，告知「已關燈」
      BT.println("LED OFF");
    }
  }
  
}

void setLed(){
  int sound=100;
  if(totalSound>=sound && totalSound<sound+200){
  for(int i=1; i<2; i++){
  digitalWrite(i, HIGH);
  }
  for(int i=2; i<13; i++){
  digitalWrite(i, LOW);
  }
  digitalWrite(ledPin14, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=sound+200 && totalSound<sound+400){
  for(int i=1; i<3; i++){
  digitalWrite(i, HIGH);
  }
  for(int i=3; i<13; i++){
  digitalWrite(i, LOW);
  }
  digitalWrite(ledPin14, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=sound+400 && totalSound<sound+600){
 for(int i=1; i<4; i++){
  digitalWrite(i, HIGH);
  }
  for(int i=4; i<13; i++){
  digitalWrite(i, LOW);
  }
  digitalWrite(ledPin14, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=sound+600 && totalSound<sound+800){
  for(int i=1; i<5; i++){
  digitalWrite(i, HIGH);
  }
  for(int i=5; i<13; i++){
  digitalWrite(i, LOW);
  }
  digitalWrite(ledPin14, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=sound+800 && totalSound<sound+1000){
  for(int i=1; i<6; i++){
  digitalWrite(i, HIGH);
  }
  for(int i=6; i<13; i++){
  digitalWrite(i, LOW);
  }
  digitalWrite(ledPin14, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=sound+1000 && totalSound<sound+1200){
  for(int i=1; i<7; i++){
  digitalWrite(i, HIGH);
  }
  for(int i=7; i<13; i++){
  digitalWrite(i, LOW);
  }
  digitalWrite(ledPin14, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=sound+1200 && totalSound<sound+1400){
  for(int i=1; i<8; i++){
  digitalWrite(i, HIGH);
  }
  for(int i=8; i<13; i++){
  digitalWrite(i, LOW);
  }
  digitalWrite(ledPin14, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=sound+1400 && totalSound<sound+1600){
  for(int i=1; i<9; i++){
  digitalWrite(i, HIGH);
  }
  for(int i=9; i<13; i++){
  digitalWrite(i, LOW);
  }
  digitalWrite(ledPin14, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=sound+1600 && totalSound<sound+1800){
  for(int i=1; i<10; i++){
  digitalWrite(i, HIGH);
  }
  for(int i=10; i<13; i++){
  digitalWrite(i, LOW);
  }
  digitalWrite(ledPin14, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=sound+1800 && totalSound<sound+2000){
  for(int i=1; i<11; i++){
  digitalWrite(i, HIGH);
  }
  for(int i=11; i<13; i++){
  digitalWrite(i, LOW);
  }
  digitalWrite(ledPin14, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=sound+2000 && totalSound<sound+2200){
  for(int i=1; i<12; i++){
  digitalWrite(i, HIGH);
  }
  for(int i=12; i<13; i++){
  digitalWrite(i, LOW);
  }
  digitalWrite(ledPin14, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=2200){
  for(int i=1; i<14; i++){
  digitalWrite(i, HIGH);
  }
  digitalWrite(ledPin14, HIGH);
  Serial.println(totalSound);
  }
  }
