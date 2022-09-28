#ifndef CHARGERATE_H_
#define CHARGERATE_H_

#include "Parameter.h"

namespace Battery {


class ChargeRate: public Parameter<float> {
 public:
    ChargeRate(const float& value);
    ChargeRate(const float& value, const float& minValue, const float& maxValue);
    virtual ~ChargeRate();

 private:
    const float CHARGERATE_MIN = 0;
    const float CHARGERATE_MAX = 0.8;
};

} /* namespace Battery */

#endif /* CHARGERATE_H_ */
