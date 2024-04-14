/*
 * Closed-loop Irrigation Control System
 *   Control(1) Project | Spring 2023
 *
 * Mohamed Nagy Elkholy
 * Hazem Mohamed Shaker
 * Ibrahim Yasser Elsiedy
 * Khaled Waleed Attia
 * Hassan Mohamed Hassn
 * 
 * Supervised By:
 *  Prof. Mohamed Moawad
 *  Eng. Laila Hamid
 */


/* Values Calibration */
#define soilWet 50   /* Define max value we consider soil 'wet' */
#define soilDry 150   /* Define min value we consider soil 'dry' */
/*NOTE: The more water, lower the resistance (reading) */

/* Pins Definition */
#define sensorPin A0
#define pumpPin 12

void setup() {
  /*Inputs and Outputs Definition*/
  pinMode(sensorPin,INPUT);
  pinMode(pumpPin,OUTPUT);
  digitalWrite(pumpPin, LOW); /* Initialize The Pump as Turned off */

  /*Serial Monitor to Show Moisture Values*/
  Serial.begin(9600);
}

void loop() {
  /* Get The Sensor Readings and Print It */
  int moisture = readSensor();
  Serial.print("Analog Output: ");
  Serial.println(moisture);

  /* Determine The Soil Status  */
  if (moisture < soilWet) {
    Serial.println("Status: Soil is too wet");
    digitalWrite(pumpPin, LOW); /*Turn off The Pump*/
  }
  else if (moisture >= soilWet && moisture < soilDry) {
    Serial.println("Status: Soil moisture is perfect");
    digitalWrite(pumpPin, LOW); /*Turn off The Pump*/
  }
  else {
    Serial.println("Status: Soil is too dry - time to water");
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
