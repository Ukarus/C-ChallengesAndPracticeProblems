#include "FahrenheitConverter.h"

float FahrenheitConverter::ConvertToCelsius(float fahrenheit)
{
    return ((fahrenheit - 32) * 5) / 9;
}
