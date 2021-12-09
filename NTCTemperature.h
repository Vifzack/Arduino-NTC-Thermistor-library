
#ifndef NTCTemperature
#define NTCTemperature

#include "Arduino.h"
#include <math.h>

class NTC                                                                               //define a class named NTC
{
private:                                                                                //private section of the class
    float Pin;                                                                          //variables for calculation are declared here
    float Resistor1;
    float ResistorNTC;
    float beta;
    float voltage = 5.00;

    const unsigned int ADCres = 1023;
    float T0 = 298.15;
    float Kelvin = 273.15;
    float DVolatge;
    float NTCvalue;

public:                                                                                 //public section oft the class
    NTC(int NTCPin, float Resistor, float NTCResistor, float b);                        //here are all the functions from this library defined
                                                                                        
    float getTemperatureC(); 
    float getTemperatureF();
};

#endif 