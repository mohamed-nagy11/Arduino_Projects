/*
 * Closed-loop Irrigation Control System
 *   Control(1) Project | Spring 2023
 *
 * Mohamed Nagy Elkholy
 * Hazem Mohamed Shaker
 * 
 * Ibrahim Yasser Elsiedy
 * Khaled Waleed Attia
 * Hassan Mohamed Hassn
 * 
 * Supervised By:
 *  Prof. Mohamed Moawad
 *  Eng. Laila Hamid
 */

#include <LiquidCrystal.h>

/* Values Calibration */
#define soilWet 500   /* Define max value we consider soil 'wet' */
#define soilDry 750   /* Define min value we consider soil 'dry' */
/*NOTE: The more water, lower the resistance (reading) */

/* Pins Definition */
#define sensorPin A0
#define pumpPin 12

/* LCD Pins Definition */
#define RS 9
#define EN A1
#define D4 A2
#define D5 A3
#define D6 A4
#define D7 A5
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);


void setup() {
  /*Inputs and Outputs Definition*/
  pinMode(sensorPin,INPUT);
  pinMode(pumpPin,OUTPUT);
  digitalWrite(pumpPin, LOW); /* Initialize The Pump as Turned off */

  /*Define 16*2 LCD*/
  lcd.begin(16, 2);
}

void loop() {
  /* Get The Sensor Readings and Print It */
  int moisture = readSensor();
  lcd.setCursor(0, 0);
  lcd.print("Output: ");
  lcd.print(moisture);

  /* Determine The Soil Status  */
  if (moisture < soilWet) {
    lcd.setCursor(1, 1);
    lcd.print("too wet");
    digitalWrite(pumpPin, LOW); /*Turn off The Pump*/
  }
  else if (moisture >= soilWet && moisture < soilDry) {
    lcd.setCursor(1, 1);
    lcd.print("perfect");
    digitalWrite(pumpPin, LOW); /*Turn off The Pump*/
  }
  else {
    lcd.setCursor(1, 1);
    lcd.print("too dry");
    digitalWrite(pumpPin, HIGH); /*Pump Water into Soil*/
  }
  
  delay(1000);  /* Take a Reading Every Second */
  Serial.println();
}

/* Function to Return Sensor Readings */
int readSensor() {
  int value = analogRead(sensorPin);  /* Read The Analog Value form The Sensor */
  return value;             /* Return Analog Moisture Value */
}
