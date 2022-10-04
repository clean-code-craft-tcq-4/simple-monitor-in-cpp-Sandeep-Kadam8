#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

#include "Parameter.h"

namespace Battery {


class Temperature: public Parameter<float> {
 public:
    Temperature(const float& value);
    Temperature(const float& value, const float& minValue, const float& maxValue);
    virtual ~Temperature();
};

} // namespace Battery
#endif /* TEMPERATURE_H_ */
