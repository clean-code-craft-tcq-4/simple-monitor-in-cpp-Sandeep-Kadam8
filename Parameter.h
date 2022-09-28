#ifndef PARAMETER_H_
#define PARAMETER_H_

#include <string>

namespace Battery {

template <typename T>
class Parameter {
 public:
    Parameter(const T& value, const T& minValue, const T& maxValue, const std::string& parameterName) {
        this->value = value;
        this->minValue = minValue;
        this->maxValue = maxValue;
        this->parameterName = parameterName;
    }
    virtual ~Parameter() {
    }

    T GetValue() const {
        return value;
    }
    T GetUpperLimit() const {
        return maxValue;
    }
    T GetLowerLimit() const {
        return minValue;
    }

    std::string GetParameterName() const {
        return parameterName;
    }

 private:
    T value;
    T minValue;
    T maxValue;
    std::string parameterName;
};

} // namespace Battery
#endif /* PARAMETER_H_ */
