# NTC-temperatur-library

This simple library is made for easy use of an NTC Resistor as a temperature sensor.

Can be used with Arduino, ESP and co and is written in C++

Just take look at KEYWORD.txt for more informations on code and circuit.

## Schematic:

![image](https://user-images.githubusercontent.com/61111586/145259225-563ad0d8-308a-4d89-a64f-2f65b0e055a6.png)

## Arduino example sketch:

```

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

  Serial.print("°C: ");                     //print temperature on serial monitor
  Serial.println(TempC);
  Serial.print("°F: ");
  Serial.println(TempF);
  
  delay(1000);
}
```

## Calculations:

![image](https://user-images.githubusercontent.com/61111586/145262516-f7226d3b-d326-46cb-b967-853cda5bf94d.png)
