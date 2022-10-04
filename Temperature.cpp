#include "Temperature.h"

namespace Battery {

const float TEMPERATURE_MIN = 0;
const float TEMPERATURE_MAX = 45;

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
