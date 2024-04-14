#include <Servo.h>
Servo S;

int trig=2;
int echo=3;
int Spin=4;
int ledR=5;
int ledL=6;
int ledM=7;

int TimeM,DistanceM;
int TimeL,DistanceL;
int TimeR,DistanceR;
void setup() {
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
S.attach(Spin);
pinMode(ledR,OUTPUT);
pinMode(ledL,OUTPUT);
pinMode(ledM,OUTPUT);
Serial.begin(9600);
//S.write(90);
}

void ultraM(){
  digitalWrite(trig,0);
  delayMicroseconds(2);
  digitalWrite(trig,1);
  delayMicroseconds(10);
  digitalWrite(trig,0);

  TimeM=pulseIn(echo,1);
  DistanceM=0.034*TimeM/2;
  Serial.print("DM= ");
  Serial.println(DistanceM);

}
void ultraL(){
  digitalWrite(trig,0);
  delayMicroseconds(2);
  digitalWrite(trig,1);
  delayMicroseconds(10);
  digitalWrite(trig,0);

  TimeL=pulseIn(echo,1);
  DistanceL=0.034*TimeL/2;
  Serial.print("DL= ");
  Serial.println(DistanceL);

}
void ultraR(){
  digitalWrite(trig,0);
  delayMicroseconds(2);
  digitalWrite(trig,1);
  delayMicroseconds(10);
  digitalWrite(trig,0);

  TimeR=pulseIn(echo,1);
  DistanceR=0.034*TimeR/2;
  Serial.print("DR= ");
  Serial.println(DistanceR);

}
void loop() {
S.write(90);
ultraM();
if(DistanceM<20){
  S.write(0);
  delay(100);
  ultraR();
  S.write(180);
  delay(100);
  ultraL();
  if(DistanceL>DistanceR){
    digitalWrite(ledR,0);
    digitalWrite(ledL,1);
    digitalWrite(ledM,0);
  }
  else if(DistanceR>DistanceL){
    digitalWrite(ledR,1);
    digitalWrite(ledL,0);
    digitalWrite(ledM,0);
  }
}
else {
    digitalWrite(ledR,0);
    digitalWrite(ledL,0);
    digitalWrite(ledM,1);
    
}
}
