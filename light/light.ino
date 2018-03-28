
bool LIGHT1 = false;
bool LIGHT2 = false;
int lightVal1, lightVal2, lightVal3, lightVal4, lightVal5, lightVal6;
int val1=0, val2=0, val3=0, val4=0, val5=0, val6=0, val7=0;
int LIGHTNUM1 = 40; //設定亮度
int LIGHTNUM2 = 70;
int LIGHTNUM3 = 40;
int LIGHTNUM4 = 40;
int LIGHTNUM5 = 40;
int LIGHTNUM6 = 40;
int LIGHTNUM7 = 40;
const byte trigPin=10; //Output pin to trigger ultra sound
const byte echoPin=11; //Input pin to receive echo pulse

void setup(){
  Serial.begin(9600);
  for(int i=2 ; i<10 ;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  //pinMode(A0, INPUT);
  //digitalWrite(3,LOW);
  //digitalWrite(4,LOW);
}

int pr_min = 400;

void loop(){
  int switchStatus1 = digitalRead(12);
  Serial.print("switchStatus1:");
  Serial.println(switchStatus1);
  int switchStatus2 = digitalRead(13);
  Serial.print("switchStatus2:");
  Serial.println(switchStatus2);
  if(switchStatus1==1){
    LIGHT1=true;
    }
  if(switchStatus2==0){
    LIGHT2=true;
    }
  if(LIGHT1){
    val2=0; val3=0; val5=0; val6=0;
    opt1();
    //LIGHT1=false;
    }
  if(LIGHT2){
    opt2();
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
  digitalWrite(2,HIGH);
  Serial.println("do");
  lightVal2 = analogRead(A0);
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
    digitalWrite(4,HIGH);
    Serial.println("digitalWrite(4,HIGH)");
  }

  
  lightVal3 = analogRead(A2);
  Serial.print("lightVal3:");
  Serial.println(lightVal3);
  if(lightVal3 < LIGHTNUM3 && val3 == 0){
    digitalWrite(6,LOW);
    }
  if(lightVal3 > LIGHTNUM3 && val3 == 0){
   val3=1;
   Serial.println("val=1");
  }
  if(val3 == 1 && lightVal3<LIGHTNUM3){
    digitalWrite(6,HIGH);
    Serial.println("digitalWrite(5,HIGH)");
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
    digitalWrite(7,HIGH);
    Serial.println("digitalWrite(7,HIGH)");
  }
  
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
    digitalWrite(9,HIGH);
    Serial.println("digitalWrite(8,HIGH)");
    LIGHT1=false;
  }
  /*
  lightVal1 = analogRead(A0);
  Serial.print("lightVal1:");
  Serial.println(lightVal1);
  if(lightVal1 < LIGHTNUM1 && val1 == 0){
    digitalWrite(3,LOW);
    }
  if(lightVal1 > LIGHTNUM1 && val1 == 0){
   val1=1;
   Serial.println("val=1");
  }
  if(val1 == 1 && lightVal1<30){
    digitalWrite(3,HIGH);
    Serial.println("digitalWrite(3,HIGH)");
  }
  */

/*
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
    digitalWrite(6,HIGH);
    Serial.println("digitalWrite(6,HIGH)");
  }
*/

  
  /*
  unsigned long d1=ping()/58; //calculate distance
  Serial.print("d1:");
  Serial.println(d1);
  if(d1 < 10 || d1>3000 && val7==0){
    digitalWrite(9,LOW);
    Serial.print("d12:");
  Serial.println(d1);
  }
  if(d1 > 4 && val7==0 && d1<3000){
    val7 = 1;
    Serial.println("val=1");
    Serial.print("d13:");
  Serial.println(d1);
    }
  if(val7 == 1 && d1 < 10 || d1>3000){
    Serial.print("d14:");
  Serial.println(d1);
    digitalWrite(9,HIGH);
    Serial.println("digitalWrite(9,HIGH)");
  }
  
  unsigned long d1=ping()/58; //calculate distance
  Serial.print("d1:");
  Serial.println(d1);
  if(d1 < 4 || d1>2000 && val7==0){
    digitalWrite(9,LOW);
    Serial.print("d12:");
    Serial.println(d1);
  }
  if(d1 > 5 && val7==0 && d1<2000){
    val7 = 1;
    Serial.println("val=1");
    Serial.print("d13:");
    Serial.println(d1);
    delay(500);
    }
  if(d1 > 2000 && val7 == 1 ){
    Serial.print("d14:");
    Serial.println(d1);
    digitalWrite(9,HIGH);
    Serial.println("digitalWrite(9,HIGH)");
  }
  */
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
    digitalWrite(5,HIGH);
    Serial.println("digitalWrite(5,HIGH)");
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
    digitalWrite(6,HIGH);
    Serial.println("digitalWrite(6,HIGH)");
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
    digitalWrite(8,HIGH);
    Serial.println("digitalWrite(8,HIGH)");
    val5=0;
  }
  
  unsigned long d1=ping()/58; //calculate distance
  Serial.print("d1:");
  Serial.println(d1);
  if(d1 < 4 || d1>2000 && val7==0){
    digitalWrite(9,LOW);
    Serial.print("d12:");
    Serial.println(d1);
  }
  if(d1 > 5 && val7==0 && d1<2000){
    val7 = 1;
    Serial.println("val=1");
    Serial.print("d13:");
    Serial.println(d1);
    delay(500);
    }
  if(d1 > 2000 && val7 == 1 ){
    Serial.print("d14:");
    Serial.println(d1);
    digitalWrite(9,HIGH);
    Serial.println("digitalWrite(9,HIGH)");
  }
  delay(500);
  
  }


