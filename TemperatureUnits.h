#ifndef TEMPERATUREUNITS_H_
#define TEMPERATUREUNITS_H_

namespace Battery {

class TemperatureUnits final {
 public:
    TemperatureUnits() = default;
    virtual ~TemperatureUnits() = default;

    static float FahrenheitToCelsius(const float& value);
    static float CelsiusToFahrenheit(const float& value);
};

} /* namespace Battery */

#endif /* TEMPERATUREUNITS_H_ */
