int soundPin=A0;
int totalSound=0;
int ledPin1=6;
int ledPin2=2;
int ledPin3=3;
int ledPin4=4;
int ledPin5=5;
int smallLedPin1=A1;
int smallLedPin2=A2;
int smallLedPin3=A3;
int smallLedPin4=A4;
bool storeLed=false;
char onLed=HIGH;
char offLed=LOW;

void setup(){
  pinMode(soundPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
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
    digitalWrite(7, HIGH);
    delay(500);
    digitalWrite(7, LOW);
    Serial.println(val);
  }
  if(totalSound>=100 && totalSound<200){
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=200 && totalSound<400){
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=400 && totalSound<600){
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=600 && totalSound<800){
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  digitalWrite(ledPin5, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=800){
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  digitalWrite(ledPin5, HIGH);
  Serial.println(totalSound);
  }
  }
