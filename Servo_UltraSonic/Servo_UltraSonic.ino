#include<Servo.h>
Servo servo;
int trig=5,echo=6;
void setup() {
servo.attach(3);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
} 
void loop() {
digitalWrite(trig,0);
delayMicroseconds(2);
digitalWrite(trig,1);
delayMicroseconds(10);
digitalWrite(trig,0);

int t=pulseIn(echo,1);
int d=0.034*t;
 servo.write(d);

if(d>180){
  Serial.println("up to 180");
  d=180;
}
 else{
  Serial.println(d);
  
 }
}
