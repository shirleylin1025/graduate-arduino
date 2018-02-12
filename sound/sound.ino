int soundPin=A0;
int totalSound=0;
int ledPin1=6;
int ledPin2=2;
int ledPin3=3;
int ledPin4=4;
int ledPin5=5;

void setup(){
  pinMode(soundPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);
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
