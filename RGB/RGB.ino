void setup() {
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
Serial.begin(9600);
}

void loop() {
char x=Serial.read();

if (x=='r'){
    digitalWrite(13,1);
    digitalWrite(12,0);
    digitalWrite(11,0);
    Serial.println("Red");}
if (x=='g'){
    digitalWrite(12,1);
    digitalWrite(13,0);
    digitalWrite(11,0);
    Serial.println("Green");}
if (x=='b'){
    digitalWrite(11,1);
    digitalWrite(12,0);
    digitalWrite(13,0);
    Serial.println("Blue");}
if (x=='h'){
    digitalWrite(11,1);
    digitalWrite(12,0);
    digitalWrite(13,1);
    Serial.println("h");}
if (x=='y'){
    digitalWrite(11,1);
    digitalWrite(12,1);
    digitalWrite(13,0);
    Serial.println("h");}
}
