#include <Arduino.h>
#include "NTCTemperature.h"               //include the library


NTC myNTC(A0, 10000, 4700, 3505);   //initialite an object myNTC(Pin, R form voltage divider, R of NTC@25°C, beta constant of NTC)
                                    //all of the parameters, despite pin number, are float variables
void setup()
{
  Serial.begin(9600);               //start serial port
}

void loop()
{
  float TempC = myNTC.getTemperatureC();    //get temperaturereading in °C
  float TempF = myNTC.getTemperatureF();    //get temperaturereading in °F

  Serial.print("°C: ");                     //print temperatur on serial monitor
  Serial.println(TempC);
  Serial.print("°F: ");
  Serial.println(TempF);
  
  delay(1000);
}
