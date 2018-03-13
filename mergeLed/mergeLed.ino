#include <SoftwareSerial.h>
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(A3, A4); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

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
  // put your main code here, to run repeatedly:
  setLed();
  static unsigned long timer = millis();
  char val = Serial.read();
  if (val== '1') {
    myDFPlayer.play(3);
    //timer = millis();
    //myDFPlayer.next();  //Play next mp3 every 3 second.
  }
  if (val== '0') {
    myDFPlayer.play(2);
    //timer = millis();
    //myDFPlayer.next();  //Play next mp3 every 3 second.
  }
  
  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }
  //static unsigned long timer = millis();
  BT.begin(9600);
  if (BT.available()) {
    val = BT.read();
    Serial.println(val);
    timer = millis();
    myDFPlayer.play(3);
    if (val == '1') {
      Serial.println(val);
      BT.println("LED ON");
      myDFPlayer.play(3);
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
void playPlayer(){
  static unsigned long timer = millis();
  
  if (millis() - timer > 5000) {
    timer = millis();
    myDFPlayer.next();  //Play next mp3 every 3 second.
  }
  
  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
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
