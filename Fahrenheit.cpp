#include "Fahrenheit.h"

#include "TemperatureUnits.h"
#include <sstream>

namespace Battery {

Fahrenheit::Fahrenheit(const float &value)
        :Temperature(TemperatureUnits::FahrenheitToCelsius(value))
{

}

Fahrenheit::~Fahrenheit() {

}

float Fahrenheit::GetUnitValue() {
    return TemperatureUnits::CelsiusToFahrenheit(Parameter::GetValue());
}

std::string Fahrenheit::GetValueWithUnit() {
    std::stringstream string;
    string << GetUnitValue() << " Fahrenheit";
    return string.str();
}

} /* namespace Battery */
