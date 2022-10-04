#ifndef CELSIUS_H_
#define CELSIUS_H_

#include "Temperature.h"
#include "Unit.h"

namespace Battery {

class Celsius final: public Temperature, public Unit {
 public:
    Celsius(const float &value);
    virtual ~Celsius();

    float GetUnitValue() override;
    std::string GetValueWithUnit() override;
};

} /* namespace Battery */

#endif /* CELSIUS_H_ */
