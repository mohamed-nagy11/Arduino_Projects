int trig=3, echo=5, G_LED=13, R_LED=12, RLY_Motor=11, t, d;

void setup() {
  pinMode(trig,OUTPUT); 
  pinMode(echo,INPUT);
  pinMode(G_LED,OUTPUT);
  pinMode(R_LED,OUTPUT);
  pinMode(RLY_Motor,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig,0);
  delayMicroseconds(2);
  digitalWrite(trig,1);
  delayMicroseconds(10);
  digitalWrite(trig,0);

  t=pulseIn(echo,1);
  d=0.034*t/2;
  Serial.print("Distance =");
  Serial.println(d);
  delay(100);

  if (d<50){
    digitalWrite(R_LED,1);
    digitalWrite(G_LED,0);
    digitalWrite(RLY_Motor,0);}
  else{
    digitalWrite(G_LED,1);
    digitalWrite(R_LED,0);
    digitalWrite(RLY_Motor,1);}
}
