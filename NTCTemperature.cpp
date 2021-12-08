#include "NTCTemperature.h"

NTC::NTC(int NTCPin, float Resistor, float NTCResistor, float b)
{
    Pin = NTCPin;
    Resistor1 = Resistor;
    ResistorNTC = NTCResistor;
    beta = b;
}

float NTC::getTemperatureC()
{
    float Temperature;

    DVolatge = analogRead(Pin);
    DVolatge = (voltage / ADCres) * DVolatge;
    NTCvalue = (DVolatge * Resistor1) / (voltage - DVolatge);
    Temperature = (beta / (log(NTCvalue / ResistorNTC) + (beta / T0))) - Kelvin;
    return Temperature;
}

float NTC::getTemperatureF()
{
    float Temperature;

    DVolatge = analogRead(Pin);
    DVolatge = (voltage / ADCres) * DVolatge;
    NTCvalue = (DVolatge * Resistor1) / (voltage - DVolatge);
    Temperature = (beta / (log(NTCvalue / ResistorNTC) + (beta / T0))) - Kelvin;
    Temperature = Temperature * 1.80 + 32;
    return Temperature;
}
