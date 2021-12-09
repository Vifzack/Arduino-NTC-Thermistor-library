#include "NTCTemperature.h"                                                             //include header file

NTC::NTC(int NTCPin, float Resistor, float NTCResistor, float b)                        //define function of class NTC to initialize the NTC
{                                                                                       //function is used for initializing the object
    Pin = NTCPin;                                                                       //all the elements in brackets in the function get written to private variables
    Resistor1 = Resistor;
    ResistorNTC = NTCResistor;
    beta = b;
}

float NTC::getTemperatureC()                                                            //define function of class NTC to get Temperature Reading in °C
{
    float Temperature;

    DVolatge = analogRead(Pin);                                                         //take measurement of analog Pin
    DVolatge = (voltage / ADCres) * DVolatge;                                           //convert bit value into voltage value
    NTCvalue = (DVolatge * Resistor1) / (voltage - DVolatge);                           //claculate NTC resistance value with voltage divider
    Temperature = (beta / (log(NTCvalue / ResistorNTC) + (beta / T0))) - Kelvin;        //calculate temperature with formula for NTCs
    return Temperature;                                                                 //return temperaturevalue
}

float NTC::getTemperatureF()                                                            //define function of class NTC to get Temperature Reading in °F
{
    float Temperature;

    DVolatge = analogRead(Pin);                                                         //take measurement of analog Pin
    DVolatge = (voltage / ADCres) * DVolatge;                                           //convert bit value into voltage value
    NTCvalue = (DVolatge * Resistor1) / (voltage - DVolatge);                           //claculate NTC resistance value with voltage divider
    Temperature = (beta / (log(NTCvalue / ResistorNTC) + (beta / T0))) - Kelvin;        //calculate temperature with formula for NTCs
    Temperature = Temperature * 1.80 + 32;                                              //convert degree celsius in degree fahrenheit
    return Temperature;                                                                 //return temperaturevalue 
}
