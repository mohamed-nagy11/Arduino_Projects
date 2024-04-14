int IRR=12;
int IRL=11;
int R;
int L;
int PWM=80;
void setup() {
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
pinMode(IRR,INPUT);
pinMode(IRL,INPUT);

}

void loop() {
R=digitalRead(IRR);
L=digitalRead(IRL);
if(R==0&&L==0){
  analogWrite(3,PWM);
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(9,PWM);
}
else if(R==1&&L==1){
  analogWrite(3,PWM);
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(9,PWM);
}
else if(R==1&&L==0){
  analogWrite(3,PWM);
  analogWrite(5,0);
  analogWrite(6,PWM);
  analogWrite(9,0);
}
else if(R==0&&L==1){
  analogWrite(3,0);
  analogWrite(5,PWM);
  analogWrite(6,0);
  analogWrite(9,PWM);
}
}
