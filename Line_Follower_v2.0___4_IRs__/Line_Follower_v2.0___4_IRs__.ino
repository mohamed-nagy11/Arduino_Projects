#include <LiquidCrystal.h>
const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// pins
int L2=10;
int L1=11;
int R1=12;
int R2=13;
int Morors_R1=3;
int Morors_R2=5;
int Morors_L2=6;
int Morors_L1=9;

//int T=500;    //delay time for prependicular turns

int PWM=80;     //speed

//functions
void forward(){
  lcd.setCursor(0,1);
  lcd.print("Forward     ");
  analogWrite(Morors_R1,PWM);
  analogWrite(Morors_R2,0);
  analogWrite(Morors_L2,0);
  analogWrite(Morors_L1,PWM);
}
void right(){
  lcd.setCursor(0,1);
  lcd.print("Right       ");
  analogWrite(Morors_R1,PWM);
  analogWrite(Morors_R2,0);
  analogWrite(Morors_L2,PWM);
  analogWrite(Morors_L1,0);
}
void left(){
  lcd.setCursor(0,1);
  lcd.print("Left        ");
  analogWrite(Morors_R1,0);
  analogWrite(Morors_R2,PWM);
  analogWrite(Morors_L2,0);
  analogWrite(Morors_L1,PWM);
}
/*
void right_90deg(){
  lcd.setCursor(0,1);
  lcd.print("Right_90deg");
  analogWrite(Morors_R1,0);
  analogWrite(Morors_R2,0);
  analogWrite(Morors_L2,120);
  analogWrite(Morors_L1,0);
}
void left_90deg(){
  lcd.setCursor(0,1);
  lcd.print("Left_90deg  ");
  analogWrite(Morors_R1,0);
  analogWrite(Morors_R2,120);
  analogWrite(Morors_L2,0);
  analogWrite(Morors_L1,0);
}
*/
void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Mohamed");

  pinMode(Morors_R1,OUTPUT);   //motors
  pinMode(Morors_R2,OUTPUT);
  pinMode(Morors_L2,OUTPUT);
  pinMode(Morors_L1,OUTPUT);
  pinMode(L2,INPUT);        //IRs
  pinMode(L1,INPUT);
  pinMode(R1,INPUT);
  pinMode(R2,INPUT);
}

void loop() {
  int IR_L2=digitalRead(L2);
  int IR_L1=digitalRead(L1);
  int IR_R1=digitalRead(R1);
  int IR_R2=digitalRead(R2);
  
  if (IR_L2==1 && IR_L1==1 && IR_R1==1 && IR_R2==1)        forward();
  else if (IR_L2==0 && IR_L1==0 && IR_R1==0 && IR_R2==0)   forward();
  /*
  else if (IR_L2==1 && IR_L1==1 && IR_R1==1 && IR_R2==0)   forward();     //unusual case
  else if (IR_L2==1 && IR_L1==0 && IR_R1==1 && IR_R2==1)   forward();     //unusual case
  else if (IR_L2==1 && IR_L1==0 && IR_R1==0 && IR_R2==1)   forward();     //unusual case
  else if (IR_L2==1 && IR_L1==0 && IR_R1==1 && IR_R2==0)   forward();     //unusual case
  else if (IR_L2==1 && IR_L1==1 && IR_R1==0 && IR_R2==1)   forward();     //unusual case
  else if (IR_L2==0 && IR_L1==1 && IR_R1==1 && IR_R2==0)   forward();     //unusual case
  else if (IR_L2==0 && IR_L1==1 && IR_R1==1 && IR_R2==1)   forward();     //unusual case
  else if (IR_L2==0 && IR_L1==1 && IR_R1==0 && IR_R2==1)   forward();     //unusual case
  */
  
  else if (IR_L2==0 && IR_L1==0 && IR_R1==1 && IR_R2==0)   right();
  else if (IR_L2==0 && IR_L1==0 && IR_R1==0 && IR_R2==1)   right();

  else if (IR_L2==0 && IR_L1==1 && IR_R1==0 && IR_R2==0)   left();
  else if (IR_L2==1 && IR_L1==0 && IR_R1==0 && IR_R2==0)   left();
/*
 else if (IR_L2==0 && IR_L1==0 && IR_R1==1 && IR_R2==1) {  
  right_90deg();        //right_prependicular
  delay(T);
 }
 else if (IR_L2==1 && IR_L1==0 && IR_R1==0 && IR_R2==0){
  left_90deg();         //left_prependicular
  delay(T);
 }
*/
  //else forward();
}
