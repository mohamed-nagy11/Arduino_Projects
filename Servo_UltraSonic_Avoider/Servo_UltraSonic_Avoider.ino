      //Pins
int Morors_R1=3;
int Morors_R2=5;
int Morors_L2=6;
int Morors_L1=9;
int trig=13 , echo=12;

int time_M , time_R , time_L , distance_M , distance_R , distance_L;

#include <Servo.h>
Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(Morors_R1,OUTPUT);   //motors
  pinMode(Morors_R2,OUTPUT);
  pinMode(Morors_L2,OUTPUT);
  pinMode(Morors_L1,OUTPUT);
  pinMode(echo,INPUT);         //ultra sonic
  pinMode(trig,OUTPUT);
  servo.attach(10);            //servo
}
     //functions
void forward(){
  analogWrite(Morors_R1,100);
  analogWrite(Morors_R2,0);
  analogWrite(Morors_L2,0);
  analogWrite(Morors_L1,100);
}
void back(){
  analogWrite(Morors_R1,0);
  analogWrite(Morors_R2,100);
  analogWrite(Morors_L2,100);
  analogWrite(Morors_L1,0);
}
void right(){
  analogWrite(Morors_R1,100);
  analogWrite(Morors_R2,0);
  analogWrite(Morors_L2,100);
  analogWrite(Morors_L1,0);
}
void left(){
  analogWrite(Morors_R1,0);
  analogWrite(Morors_R2,100);
  analogWrite(Morors_L2,0);
  analogWrite(Morors_L1,100);
}
void Stop(){
  analogWrite(Morors_R1,0);
  analogWrite(Morors_R2,0);
  analogWrite(Morors_L2,0);
  analogWrite(Morors_L1,0);
}
void ultraM(){
  digitalWrite(trig,0);
  delayMicroseconds(2);
  digitalWrite(trig,1);
  delayMicroseconds(10);
  digitalWrite(trig,0);

  time_M=pulseIn(echo,1);
  distance_M=0.034*time_M;
  Serial.print("dM=");
    Serial.println(distance_M);

}
void ultraR(){
  digitalWrite(trig,0);
  delayMicroseconds(2);
  digitalWrite(trig,1);
  delayMicroseconds(10);
  digitalWrite(trig,0);

  time_R=pulseIn(echo,1);
  distance_R=0.034*time_R;
  Serial.print("dR=");
    Serial.println(distance_R);
}
void ultraL(){
  digitalWrite(trig,0);
  delayMicroseconds(2);
  digitalWrite(trig,1);
  delayMicroseconds(10);
  digitalWrite(trig,0);

  time_L=pulseIn(echo,1);
  distance_L=0.034*time_L;
  Serial.print("dL=");
    Serial.println(distance_L);
}


void loop() {
  ultraM();
  
  if (distance_M < 60){
    Stop();
    servo.write(0);
    ultraL();
    delay(500);
    
    servo.write(180);
    ultraR();
    delay(500);
    servo.write(90);


    if(distance_R >= distance_L){
      right();
      delay(250);
      Serial.println("RIGHT");
      //delay(1000);
    }
    else if(distance_R < distance_L){
      left();
      delay(250);
      Serial.println("LEFT");
      //delay(1000);
    }
  }
else
  forward();
  
}
