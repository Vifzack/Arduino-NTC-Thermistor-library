
#ifndef NTCTemperature
#define NTCTemperature

#include "Arduino.h"
#include <math.h>

class NTC
{
private:
    float Pin;
    float Resistor1;
    float ResistorNTC;
    float beta;
    float voltage = 5.00;

    const unsigned int ADCres = 1023;
    float T0 = 298.15;
    float Kelvin = 273.15;
    float DVolatge;
    float NTCvalue;

public:
    NTC(int NTCPin, float Resistor, float NTCResistor, float b); // Constuctor

    float getTemperatureC(); // Toggle Functions
    float getTemperatureF();
};

#endif //! NTCTemperature