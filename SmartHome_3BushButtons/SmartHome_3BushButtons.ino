int LED1=0, LED2=0, LED3=0 ;

void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
}

void Turn_ON(int n){
  if(n==1){
    digitalWrite(11,1);
    delay(1000);
    LED1=1;
  }
  else if(n==2){
    digitalWrite(12,1);
    delay(1000);
    LED2=1;
  }
  else if(n==3){
    digitalWrite(13,1);
    delay(1000);
    LED3=1;
  }
}

void Turn_OFF(int n){
  if(n==1){
    digitalWrite(11,0);
    delay(1000);
    LED1=0;
  }
  else if(n==2){
    digitalWrite(12,0);
    delay(1000);
    LED2=0;
  }
  else if(n==3){
    digitalWrite(13,0);
    delay(1000);
    LED3=0;
  }
}

void loop() {
  int Button1=digitalRead(2);
  int Button2=digitalRead(3);
  int Button3=digitalRead(4);
  
  if (Button1==0&&LED1==0){
    Turn_ON(1);
    LED1=1;
  }
  else if (Button1==0&&LED1==1){
    Turn_OFF(1);
    LED1=0;
  }

  if (Button2==0&&LED2==0){
    Turn_ON(2);
    LED2=1;
  }
  else if (Button2==0&&LED2==1){
    Turn_OFF(2);
    LED2=0;
  }

  if (Button3==0&&LED3==0){
    Turn_ON(3);
    LED3=1;
  }
  else if (Button3==0&&LED3==1){
    Turn_OFF(3);
    LED3=0;
  }
}
