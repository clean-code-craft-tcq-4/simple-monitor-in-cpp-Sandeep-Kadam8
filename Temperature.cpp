#include "Temperature.h"

namespace Battery {

Temperature::Temperature(const float &value)
        :Temperature(value, TEMPERATURE_MIN, TEMPERATURE_MAX)
{
}

Temperature::Temperature(const float &value, const float &minValue, const float &maxValue)
        :Parameter(value, minValue, maxValue, "Temperature")
{
}

Temperature::~Temperature() {
}

} // namespace Battery
