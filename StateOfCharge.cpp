#include "StateOfCharge.h"

namespace Battery {


const float SOC_MIN = 20;
const float SOC_MAX = 80;

StateOfCharge::StateOfCharge(const float &value)
        :StateOfCharge(value, SOC_MIN, SOC_MAX)
{
}

StateOfCharge::StateOfCharge(const float &value, const float &minValue, const float &maxValue)
        :Parameter(value, minValue, maxValue, "State of chanrge")
{
}

StateOfCharge::~StateOfCharge() {
}

} /* namespace Battery */
