/******************************
*    Mohamed Nagy El Kholy    *
*         Task1_Day2          *
* Mansoura Robotics Hackathon *
*          AVR Track          *
******************************/

/*The name of pins*/
#define Low_Button 2
#define Med_Button 3
#define High_Button 4
#define Buzzer 11
#define Pot A0
#define Motor A1

void setup() {
  /*Pins Configuration*/
  pinMode(Low_Button,INPUT_PULLUP);
  pinMode(Med_Button,INPUT_PULLUP);
  pinMode(High_Button,INPUT_PULLUP);
  pinMode(Buzzer,OUTPUT);
  pinMode(Pot,INPUT);
  pinMode(Motor,OUTPUT);

  Serial.begin(9600);     /*Initializing the serial communication*/
}

void loop() {
  /*Initializing the variables*/
  int Low_Speed = digitalRead(Low_Button);
  int Med_Speed = digitalRead(Med_Button);
  int High_Speed = digitalRead(High_Button);
  volatile int Res = digitalRead(Pot);

  Res*=1000/1023;        /*Calculating the value of the pot*/
  
  Serial.print("Res=");
  Serial.println(Res);
  
  
  /*Turn the buzzer on when the pot is lower than 2000 Ohm*/
  if(Res<2000)
    digitalWrite(Buzzer,1);
  else
    digitalWrite(Buzzer,0);

  /*Control the speed of the motor*/
  if(Low_Speed==0){
    analogWrite(Motor,85);
    Serial.println("Low");
    }
  else if(Med_Speed==0){
    analogWrite(Motor,170);
    Serial.println("Med");
    }
  else if(High_Speed==0){
    analogWrite(Motor,255);
    Serial.println("High");
    }
  else
    analogWrite(Motor,0);
}
