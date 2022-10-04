#ifndef CHARGERATE_H_
#define CHARGERATE_H_

#include "Parameter.h"

namespace Battery {


class ChargeRate: public Parameter<float> {
 public:
    ChargeRate(const float& value);
    ChargeRate(const float& value, const float& minValue, const float& maxValue);
    virtual ~ChargeRate();
};

} /* namespace Battery */

#endif /* CHARGERATE_H_ */
