      //Pins
int Morors_R1=3;
int Morors_R2=5;
int Morors_L2=6;
int Morors_L1=9;
int buzz=11;

int data;

void setup() {
  pinMode(Morors_R1,OUTPUT);   //motors
  pinMode(Morors_R2,OUTPUT);
  pinMode(Morors_L2,OUTPUT);
  pinMode(Morors_L1,OUTPUT);
  pinMode(buzz,OUTPUT);          //buzzer
  Serial.begin(9600);
}

       //functions
void forward(){
  digitalWrite(Morors_R1,1);
  digitalWrite(Morors_R2,0);
  digitalWrite(Morors_L2,0);
  digitalWrite(Morors_L1,1);
}
void back(){
  digitalWrite(Morors_R1,0);
  digitalWrite(Morors_R2,1);
  digitalWrite(Morors_L2,1);
  digitalWrite(Morors_L1,0);
}
void right(){
  digitalWrite(Morors_R1,1);
  digitalWrite(Morors_R2,0);
  digitalWrite(Morors_L2,1);
  digitalWrite(Morors_L1,0);
}
void left(){
  digitalWrite(Morors_R1,0);
  digitalWrite(Morors_R2,1);
  digitalWrite(Morors_L2,0);
  digitalWrite(Morors_L1,1);
}
void Stop(){
  digitalWrite(Morors_R1,0);
  digitalWrite(Morors_R2,0);
  digitalWrite(Morors_L2,0);
  digitalWrite(Morors_L1,0);
}
       

void loop() {
  
data=Serial.read();

if(data=='F')       forward();
else if(data=='B')  back();
else if(data=='R')  right();
else if(data=='L')  left();
else if(data=='S')  Stop();

else if(data=='V')
  digitalWrite(buzz,1);

else if(data=='v')
  digitalWrite(buzz,0);

}
