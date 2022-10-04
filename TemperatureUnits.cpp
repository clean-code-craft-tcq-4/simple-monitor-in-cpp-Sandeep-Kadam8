#include "TemperatureUnits.h"

namespace Battery {

float TemperatureUnits::FahrenheitToCelsius(const float &value) {
        return ((value - 32) * 5 / 9);
}

float TemperatureUnits::CelsiusToFahrenheit(const float &value) {
    return ((value * 9 / 5) + 32);
}

} /* namespace Battery */
