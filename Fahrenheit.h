#ifndef FAHRENHEIT_H_
#define FAHRENHEIT_H_

#include "Temperature.h"
#include "Unit.h"

namespace Battery {

class Fahrenheit final : public Temperature, public Unit {
 public:
    Fahrenheit(const float &value);
    virtual ~Fahrenheit();

    float GetUnitValue() override;
    std::string GetValueWithUnit() override;

};

} /* namespace Battery */

#endif /* FAHRENHEIT_H_ */
