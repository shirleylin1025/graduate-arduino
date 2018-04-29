
bool LIGHT1 = false;
bool LIGHT2 = false;
int delayOpt1 = 0;
int delayOpt2 = 0;
bool RUN1=true;
bool RUN2=true;
bool RUN3=true;
bool RUN4=true;
bool RUN5=true;
bool RUN6=true;
bool RUN7=true;
bool RUN8=true;

int lightVal1, lightVal2, lightVal3, lightVal4, lightVal5, lightVal6;
int val1=0, val2=0, val3=0, val4=0, val5=0, val6=0, val7=0;
int LIGHTNUM1 = 113; //設定亮度
int LIGHTNUM2 = 200;
int LIGHTNUM3 = 30;
int LIGHTNUM4 = 70;
int LIGHTNUM5 = 40;
int LIGHTNUM6 = 20;
int LIGHTNUM7 = 40;
int sec = 500;
int delaySecOpt1 = 6000;
int delaySecOpt2 = 6000;
const byte trigPin=10; //Output pin to trigger ultra sound
const byte echoPin=11; //Input pin to receive echo pulse

void setup(){
  Serial.begin(9600);
  for(int i=2 ; i<10 ;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  //digitalWrite(3,LOW);
  //digitalWrite(4,LOW);
}

int pr_min = 400;

void loop(){
  int switchStatus1 = digitalRead(12);
  //Serial.print("switchStatus1:");
  //Serial.println(switchStatus1);
  int switchStatus2 = digitalRead(13);
  //Serial.print("switchStatus2:");
  //Serial.println(switchStatus2);
  if(switchStatus1==1){
    LIGHT1=true;
    }
  if(switchStatus2==1){
    LIGHT2=true;
    }
  if(LIGHT1){
    //val2=0; val3=0; val5=0; val6=0;
    opt1();
    Serial.println("do:opt1");
    //LIGHT1=false;
    }
  if(LIGHT2){
    opt2();
    Serial.println("do:opt2");
    }
  //opt2();
  //delay(10000);//10秒
}
 unsigned long ping() { //send 10us pulse to HC-SR04 trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  //sustain at least 10us HIGH pulse
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH);
  }

void opt1(){
  digitalWrite(3,HIGH);
  Serial.println("do");
  lightVal2 = analogRead(A1);
  Serial.print("lightVal2:");
  Serial.println(lightVal2);
  if(lightVal2 < LIGHTNUM2 && val2 == 0){
    digitalWrite(4,LOW);
    }
  if(lightVal2 > LIGHTNUM2 && val2 == 0){
   val2=1;
   Serial.println("val=1");
  }
  if(val2 == 1 && lightVal2<LIGHTNUM2){
    if(RUN2){
      for(int i=0; i<6; i++){
        digitalWrite(4,HIGH);
        delay(sec);
        digitalWrite(4,LOW);
        delay(sec);
        if(i=5){
          RUN2 = false;
          }
        delayOpt1 += 1;
        }
    digitalWrite(4,HIGH);
    Serial.println("digitalWrite(4,HIGH)");
    }
  }
    if(delayOpt1 == 1){
    delay(delaySecOpt1);
    for(int i=0; i<6; i++){
        digitalWrite(6,HIGH);
        delay(sec);
        digitalWrite(6,LOW);
        delay(sec);
        digitalWrite(6,HIGH);
        Serial.println("SHINE6(A4)");
        delayOpt1 = 2;
       }
    }
  lightVal5 = analogRead(A4);
  Serial.print("lightVal5:");
  Serial.println(lightVal5);
  if(lightVal5 < LIGHTNUM5 && val5 == 0){
    digitalWrite(8,LOW);
    }
  if(lightVal5 > LIGHTNUM5 && val5 == 0){
   val5=1;
   Serial.println("val=1");
  }
  if(val5 == 1 && lightVal5<LIGHTNUM5){
    if(RUN5){
      for(int i=0; i<6; i++){
        digitalWrite(8,HIGH);
        delay(sec);
        digitalWrite(8,LOW);
        delay(sec);
        }
    digitalWrite(8,HIGH);
    Serial.println("digitalWrite(8,HIGH)");
    }
    RUN5=false;
  }
  
 unsigned long d1=ping()/58; //calculate distance
  Serial.print("d1:");
  Serial.println(d1);
  if(d1 < 8 || d1>100 && val7 == 0){
    //digitalWrite(9,LOW);
    Serial.print("d12:");
    Serial.println(d1);
    Serial.println("digitalWrite(9,LOW)");
  }
  if(d1 > 8 && val7==0 && d1<100 && d1!=0){
    val7 = 1;
    Serial.println("val=1");
    Serial.print("d13:");
    Serial.println(d1);
    Serial.println("9,Opne");
    delay(500);
    }
  if(d1 < 8 && val7 == 1 ){
    if(RUN7){
      for(int i=0; i<6; i++){
        digitalWrite(9,HIGH);
        delay(sec);
        digitalWrite(9,LOW);
        delay(sec);
        }
    digitalWrite(9,HIGH);
    Serial.println("digitalWrite(9,HIGH)");
    }
    RUN7=false;
  }
    //LIGHT1=false;
  delay(500);
  
 }

void opt2(){
  digitalWrite(3,HIGH);
  lightVal2 = analogRead(A1);
  Serial.print("lightVal2:");
  Serial.println(lightVal2);
  if(lightVal2 < LIGHTNUM2 && val2 == 0){
    digitalWrite(5,LOW);
    }
  if(lightVal2 > LIGHTNUM2 && val2 == 0){
   val2=1;
   Serial.println("val=1");
  }
  if(val2 == 1 && lightVal2<LIGHTNUM2){
    if(RUN2){
    digitalWrite(5,HIGH);
    delay(sec);
    digitalWrite(5,LOW);
    delay(sec);
    digitalWrite(5,HIGH);
    delay(sec);
    digitalWrite(5,LOW);
    delay(sec);
    digitalWrite(5,HIGH);
    delay(sec);
    digitalWrite(5,LOW);
    delay(sec);
    digitalWrite(5,HIGH);
    delay(sec);
    digitalWrite(5,LOW);
    delay(sec);
    digitalWrite(5,HIGH);
    delay(sec);
    digitalWrite(5,LOW);
    delay(sec);
    digitalWrite(5,HIGH);
    delay(sec);
    Serial.println("digitalWrite(5,HIGH)");
    }
    RUN2=false;
  }

  lightVal4 = analogRead(A3);
  Serial.print("lightVal4:");
  Serial.println(lightVal4);
  if(lightVal4 < LIGHTNUM4 && val4 == 0){
    digitalWrite(6,LOW);
    }
  if(lightVal4 > LIGHTNUM4 && val4 == 0){
   val4=1;
   Serial.println("val=1");
  }
  if(val4 == 1 && lightVal4<LIGHTNUM4){
    if(RUN4){
      for(int i=0; i<6; i++){
        digitalWrite(6,HIGH);
        delay(sec);
        digitalWrite(6,LOW);
        delay(sec);
        }
    digitalWrite(6,HIGH);
    Serial.println("digitalWrite(6,HIGH)");
    }
    RUN4=false;
  }

  lightVal5 = analogRead(A4);
  Serial.print("lightVal5:");
  Serial.println(lightVal5);
  if(lightVal5 < LIGHTNUM5 && val5 == 0){
    digitalWrite(7,LOW);
    }
  if(lightVal5 > LIGHTNUM5 && val5 == 0){
   val5=1;
   Serial.println("val=1");
  }
  if(val5 == 1 && lightVal5<LIGHTNUM5){
    if(RUN5){
      for(int i=0; i<6; i++){
        digitalWrite(7,HIGH);
        delay(sec);
        digitalWrite(7,LOW);
        delay(sec);
        }
    digitalWrite(7,HIGH);
    Serial.println("digitalWrite(7,HIGH)");
    }
    RUN5=false;
    delayOpt2 += 1;
    if(delayOpt2 == 1){
    delay(delaySecOpt1);
    for(int i=0; i<6; i++){
        digitalWrite(9,HIGH);
        delay(sec);
        digitalWrite(9,LOW);
        delay(sec);
        digitalWrite(9,HIGH);
        Serial.println("SHINE4(A2)");
        delayOpt1 = 2;
       }
    }
  }

/*
  lightVal6 = analogRead(A5);
  Serial.print("lightVal6:");
  Serial.println(lightVal6);
  if(lightVal6 < LIGHTNUM6 && val6 == 0){
    digitalWrite(9,LOW);
    }
  if(lightVal6 > LIGHTNUM6 && val6 == 0){
   val6=1;
   Serial.println("val=1");
  }
  if(val6 == 1 && lightVal6<LIGHTNUM6){
    if(RUN6){
      for(int i=0; i<6; i++){
        digitalWrite(9,HIGH);
        delay(sec);
        digitalWrite(9,LOW);
        delay(sec);
        }
    digitalWrite(9,HIGH);
    Serial.println("digitalWrite(9,HIGH)");
    }
    RUN6=false;
   
  }
  */
  delay(500);
}

