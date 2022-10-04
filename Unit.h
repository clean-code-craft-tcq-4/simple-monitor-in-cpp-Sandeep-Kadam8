#ifndef UNIT_H_
#define UNIT_H_

#include <string>

namespace Battery {

class Unit {
 public:
    Unit() = default;
    virtual ~Unit() = default;

    virtual float GetUnitValue() = 0;
    virtual std::string GetValueWithUnit() = 0;
};

} /* namespace Battery */

#endif /* UNIT_H_ */
