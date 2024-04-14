int m11=3;
int m12=5;
int m21=6;
int m22=9;

int data;
void setup() {
pinMode(m11,OUTPUT);
pinMode(m12,OUTPUT);
pinMode(m21,OUTPUT);
pinMode(m22,OUTPUT);
pinMode(11,OUTPUT);
Serial.begin(9600);
}

void loop() {
data=Serial.read();

if(data=='F'){
  digitalWrite(m11,1);
  digitalWrite(m12,0);
  digitalWrite(m21,0);
  digitalWrite(m22,1);
}
else if(data=='B'){
  digitalWrite(m11,0);
  digitalWrite(m12,1);
  digitalWrite(m21,1);
  digitalWrite(m22,0);
}
else if(data=='R'){
  digitalWrite(m11,1);
  digitalWrite(m12,0);
  digitalWrite(m21,1);
  digitalWrite(m22,0);
}
else if(data=='L'){
  digitalWrite(m11,0);
  digitalWrite(m12,1);
  digitalWrite(m21,0);
  digitalWrite(m22,1);
}
else if(data=='S'){
  digitalWrite(m11,0);
  digitalWrite(m12,0);
  digitalWrite(m21,0);
  digitalWrite(m22,0);
}
else if(data=='V'){
  digitalWrite(11,1);
}
else if(data=='v'){
  digitalWrite(11,0);
}
}
