// Call the labriray
#include "Adafruit_CCS811.h"
Adafruit_CCS811 ccs;

// Setup loop starts serial com on port: 9600
void setup() {
  Serial.begin(9600);
  Serial.println("CCS811 test");
  // Starts css listening via i2c
  if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
  }
  //calibrate temperature sensor
  while(!ccs.available());
    float temp = ccs.calculateTemperature();
    ccs.setTempOffset(temp - 25.0);
}

void loop() {
  if(ccs.available()){
    float temp = ccs.calculateTemperature();
  if(!ccs.readData()){
    // This is left as seperate, may be combined for performance
    Serial.print("CO2: ");
    Serial.print(ccs.geteCO2());
    Serial.print("ppm.\n TVOC: ");
    Serial.print(ccs.getTVOC());
    Serial.print("ppb,\n Temp:");
    Serial.println(temp);
    Serial.print("degree\n");
}
else{
  Serial.println("ERROR!");
while(1);
}
}
  delay(500);
}
