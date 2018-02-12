int soundPin=A0;

void setup(){
  pinMode(soundPin, INPUT);
  Serial.begin(9600);
}
void loop(){
  int val = analogRead(soundPin);  
  if(val>50){
    Serial.println(val);
  }
}
