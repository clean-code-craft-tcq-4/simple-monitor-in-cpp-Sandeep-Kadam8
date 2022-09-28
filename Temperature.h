#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

#include "Parameter.h"

namespace Battery {


class Temperature: public Parameter<float> {
 public:
    Temperature(const float& value);
    Temperature(const float& value, const float& minValue, const float& maxValue);
    virtual ~Temperature();

 private:
    const float TEMPERATURE_MIN = 0;
    const float TEMPERATURE_MAX = 45;
};

} // namespace Battery
#endif /* TEMPERATURE_H_ */
