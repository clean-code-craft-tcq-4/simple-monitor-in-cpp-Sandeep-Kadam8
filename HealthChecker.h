#ifndef HEALTHCHECKER_H_
#define HEALTHCHECKER_H_

#include "Parameter.h"
#include <string>
#include <vector>
#include <functional>

namespace Battery {
 
#define SOC_WARNING_TOLERANCE_PERCENT 5

enum MessageState {
    Warning,
    Alarm
};

class HealthChecker final {
 public:
    HealthChecker();
    virtual ~HealthChecker();

    bool IsOk(float temperature, float soc, float chargeRate);

    template <typename T>
    bool IsParameterOutOfRange(const Parameter<T>& parameter) {
        return (parameter.GetValue() < parameter.GetLowerLimit() || parameter.GetValue() > parameter.GetUpperLimit());
    }
 
    float GetScaledParameterValue(const float &value, const float &min, const float &max);
    void CheckForEarlyWarning(const Parameter<float> &parameter, int warningTolerancePercent);
    void WarningAlert(const std::string & parameterName, const std::string &status, std::function<void(const std::string&)> function);
    void AlarmOutOfRange(const std::string & parameterName, std::function<void(const std::string&)> function);
    std::string PrepareParameterMessage(const std::string& parameterName, MessageState state, const std::string& status);
    static void printOnConsole(const std::string& data);
 private:
    const std::string OUTOFRANGE = "out of range!";
};

} /* namespace Battery */

#endif /* HEALTHCHECKER_H_ */
