
/**Servo motor**/
/*Servo libirary*/
#include<Servo.h>
/*The name of the servo*/
Servo gate;

/**LCD**/
/*LCD libirary*/
#include <LiquidCrystal.h>
/*Pins of LCD*/
const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/*Number of full parking places*/
int full = 0;

/*Pins of IR sensors*/
int Gate_IR = 13;
int IR1 = 4;
int IR2 = 3;
int IR3 = 2;

/*The state of each parking place; full=0 and empty=1*/
int P1 = 0;
int P2 = 0;
int P3 = 0;

/**Lights**/
/*Light of the gate*/
int Gate_LED_R = 12;
/*Light of each parking placce; green and red*/
int P1_G = 9;
int P1_R = 10;
int P2_G = 7;
int P2_R = 8;
int P3_G = 5;
int P3_R = 6;

void setup() {

  /*Pin of the servo*/
  gate.attach(11);

  /*Defining IRS as inputs*/
  pinMode(Gate_IR,INPUT);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);

  /*Defining LEDs as outputs*/
  pinMode(Gate_LED_R,OUTPUT);
  pinMode(P1_G,OUTPUT);
  pinMode(P2_G,OUTPUT);
  pinMode(P3_G,OUTPUT);
  pinMode(P1_R,OUTPUT);
  pinMode(P2_R,OUTPUT);
  pinMode(P3_R,OUTPUT);

  /*Defining the size of LCD: (columns,rows)*/
  lcd.begin(16, 2);
}

void loop() {

  /*The gate is closed*/
  gate.write(90);

  /**Entering the parking**/
  /*If there is a car in front of the gate and places are available, open the gate*/
  /*If there is a car in front of the gate and places are full, turn on red light*/
  if (digitalRead(Gate_IR)==0 && full<3){
    digitalWrite(Gate_LED_R,0);
    gate.write(0);
    
  }
  else if(digitalRead(Gate_IR)==0 && full>=3){
    gate.write(90);
    digitalWrite(Gate_LED_R,1);
    /*
    lcd.setCursor(5,0);
    lcd.print("Sorry");
    lcd.setCursor(0,1);
    lcd.print("Places are full");
    lcd.clear();
    */
  }
  else{
    gate.write(90);
    digitalWrite(Gate_LED_R,0);
  }

  /*Intializing the number of parking places = 0*/
  full = 0;

  /*Reading the state of each parking place*/
  P1 = digitalRead(IR1);
  P2 = digitalRead(IR2);
  P3 = digitalRead(IR3);

  /**The conditions of the places**/
  /*If the place is full (0), turn on the red light and increase the number of full places*/
  /*If the plaace is empty (1), turn on the green light*/
  
  /*Parking place no.1*/
  if(P1==0){
    digitalWrite(P1_G,0);
    digitalWrite(P1_R,1);
    full++;
  }
  else{
    digitalWrite(P1_G,1);
    digitalWrite(P1_R,0);
  }

  /*Parking place no.2*/
  if(P2==0){
    digitalWrite(P2_G,0);
    digitalWrite(P2_R,1);
    full++;
  }
  else{
    digitalWrite(P2_G,1);
    digitalWrite(P2_R,0);
  }

  /*Parking place no.3*/
  if(P3==0){
    digitalWrite(P3_G,0);
    digitalWrite(P3_R,1);
    full++;
  }
  else{
    digitalWrite(P3_G,1);
    digitalWrite(P3_R,0);
  }

  /*Displaying the number of full and empty places*/
  lcd.setCursor(0,0);
  lcd.print("Empty : ");
  lcd.print(3-full);
  lcd.setCursor(1,1);
  lcd.print("Full : ");
  lcd.print(full);
  



}
