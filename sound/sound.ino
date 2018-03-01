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
  Serial.begin(9600);
}
void loop(){
  twinkleLed();
  int val = analogRead(soundPin);
  if(val>50){
    totalSound+=val;
    Serial.println(val);
  }
  if(totalSound>=100 && totalSound<1100){
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=1100 && totalSound<2200){
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=2200 && totalSound<3300){
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=3300 && totalSound<4400){
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  digitalWrite(ledPin5, LOW);
  Serial.println(totalSound);
  }
  else if(totalSound>=4400){
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  digitalWrite(ledPin5, HIGH);
  Serial.println(totalSound);
  }
}
void twinkleLed(){
    int delaySec=100;
    digitalWrite(smallLedPin1, onLed);
    digitalWrite(smallLedPin2, offLed);
    digitalWrite(smallLedPin3, offLed);
    digitalWrite(smallLedPin4, offLed);
    delay(delaySec);
    digitalWrite(smallLedPin2, onLed);
    delay(delaySec);
    digitalWrite(smallLedPin3, onLed);
    delay(delaySec);
    digitalWrite(smallLedPin4, onLed);
    delay(delaySec);
    digitalWrite(smallLedPin4, offLed);
    delay(delaySec);
    digitalWrite(smallLedPin3, offLed);
    delay(delaySec);
    digitalWrite(smallLedPin2, offLed);
    delay(delaySec);
    digitalWrite(smallLedPin1, offLed);
    delay(delaySec);
  }
