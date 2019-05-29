int soundPin=A0;
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
int smallLedPin1=A1;
int smallLedPin2=A2;
int smallLedPin3=A3;
int smallLedPin4=A4;
bool storeLed=false;
char onLed=HIGH;
char offLed=LOW;

void setup(){
  
  pinMode(soundPin, INPUT);
  for(int i=1; i<=13 ;i++){
    pinMode(i, OUTPUT);
    }
  pinMode(ledPin14, OUTPUT);
  pinMode(smallLedPin1, OUTPUT);
  pinMode(smallLedPin2, OUTPUT);
  pinMode(smallLedPin3, OUTPUT);
  pinMode(smallLedPin4, OUTPUT);

  pinMode(7, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  twinkleLed();
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
    int val = analogRead(soundPin);
    Serial.println(val);
    if(val>48 && storeLed == true){
    totalSound+=val;
    //success add
    Serial.println(val);
  }
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
