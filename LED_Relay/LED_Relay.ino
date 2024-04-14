void setup() {
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
Serial.begin(9600);
}

void loop() {
  
int x=Serial.read();

if(x=='A'){
  digitalWrite(13,1);
  Serial.println("13 is ON");
}

if(x=='a'){
  digitalWrite(13,0);
  Serial.println("13 is OFF");
}

if(x=='B'){
  digitalWrite(12,1);
  Serial.println("12 is ON");
}

if(x=='b'){
  digitalWrite(12,0);
  Serial.println("12 is OFF");
}

if(x=='C'){
  digitalWrite(11,1);
  Serial.println("11 is ON");
}

if(x=='c'){
  digitalWrite(11,0);
  Serial.println("11 is OFF");
}

if(x=='D'){
  digitalWrite(10,1);
  Serial.println("10 is ON");
}

if(x=='d'){
  digitalWrite(10,0);
  Serial.println("10 is OFF");
}


}
