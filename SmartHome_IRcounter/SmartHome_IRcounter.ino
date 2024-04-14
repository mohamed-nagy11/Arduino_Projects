int LED = 13;
int IR_IN = 2;
int IR_OUT = 3;
int c=0;
void setup() {
  pinMode(LED,OUTPUT);
  pinMode(IR_IN,INPUT);
  pinMode(IR_OUT,INPUT);
  Serial.begin(9600);
}

void loop() {
  int in = digitalRead(IR_IN);
  int out = digitalRead(IR_OUT);
  
  
  if(in==0&&out==1)
  {
    c=c+1;
    delay(1000);
    Serial.print("counter=");
  Serial.println(c);
  }
 else if(out==0&&in==1)
  {
    c=c-1;
    delay(1000);
    Serial.print("counter=");
  Serial.println(c);
  }

  if(c>0)
    digitalWrite(LED,1);
  else if(c==0)
    digitalWrite(LED,0);

}
