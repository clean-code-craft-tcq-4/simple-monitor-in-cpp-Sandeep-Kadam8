#ifndef STATEOFCHARGE_H_
#define STATEOFCHARGE_H_

#include "Parameter.h"

namespace Battery {


class StateOfCharge: public Parameter<float> {
 public:
    StateOfCharge(const float& value);
    StateOfCharge(const float& value, const float& minValue, const float& maxValue);
    virtual ~StateOfCharge();

 private:
    const float SOC_MIN = 20;
    const float SOC_MAX = 80;
};

} /* namespace Battery */

#endif /* STATEOFCHARGE_H_ */
