#include "ChargeRate.h"

namespace Battery {

ChargeRate::ChargeRate(const float& value)
        :ChargeRate(value, CHARGERATE_MIN, CHARGERATE_MAX)
{

}

ChargeRate::ChargeRate(const float& value, const float& minValue, const float& maxValue)
        :Parameter(value, minValue, maxValue, "Charge rate")
{
}

ChargeRate::~ChargeRate() {
}

} /* namespace Battery */
