#include "Celsius.h"
#include <sstream>

namespace Battery {

Celsius::Celsius(const float &value)
        :Temperature(value)
{

}

Celsius::~Celsius() {
}

std::string Celsius::GetValueWithUnit() {
    std::stringstream string;
    string << GetUnitValue() << " Celsius";
    return string.str();
}

float Celsius::GetUnitValue() {
    return Parameter::GetValue();
}

} /* namespace Battery */
