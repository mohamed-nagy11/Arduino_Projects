int LED=0 ;



void setup() {
  pinMode(13,OUTPUT);
  pinMode(2,INPUT_PULLUP);
}

void Turn_ON(){
  digitalWrite(13,1);
  delay(1000);
  LED=1;
}

void Turn_OFF (){
  digitalWrite(13,0);
  delay(1000);
  LED=0;
}

void loop() {
  int Button=digitalRead(2);
  
  if (Button==0&&LED==0){
    Turn_ON();
    LED=1;
  }
  else if (Button==0&&LED==1){
    Turn_OFF();
    LED=0;
  }

}
