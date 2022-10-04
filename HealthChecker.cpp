#include "HealthChecker.h"
#include "Temperature.h"
#include "StateOfCharge.h"
#include "ChargeRate.h"
#include <iostream>
#include <sstream>
#include <map>
#include "Fahrenheit.h"
#include "ToleranceChecker.h"

namespace Battery {
    
enum HealthCheckParameter {
    TEMPERATURE,
    STATEOFCHARGE,
    CHARGERATE
};

std::map<MessageState, std::string> MessageStateMap{
    {Warning, "Warning"},
    {Alarm, "Alarm"}
};

HealthChecker::HealthChecker() {

}

HealthChecker::~HealthChecker() {
}

bool HealthChecker::IsOk(float temperature, float soc, float chargeRate) {
    std::vector<Parameter<float>> parameters = {Fahrenheit(temperature), StateOfCharge(soc), ChargeRate(chargeRate)};

    CheckForEarlyWarning(parameters[STATEOFCHARGE], SOC_WARNING_TOLERANCE_PERCENT);
    
    bool result = true;
    for(const auto& parameter:parameters) {
        if(IsParameterOutOfRange(parameter)) {
            AlarmOutOfRange(parameter.GetParameterName(), HealthChecker::printOnConsole);
            result = false;
        }
    }

    return result;
}

std::string HealthChecker::PrepareParameterMessage(const std::string &parameterName, MessageState state, const std::string &status) {
    std::stringstream string;
    std::string messageState = MessageStateMap[state];
    string << messageState << ": "<< parameterName << " " << status << "\n";
    return string.str();
}

void HealthChecker::AlarmOutOfRange(const std::string & parameterName, std::function<void(const std::string&)> notify) {
    std::string message = PrepareParameterMessage(parameterName, Alarm, OUTOFRANGE);
    notify(message);
}
    
 void HealthChecker::CheckForEarlyWarning(const Parameter<float> &parameter, int warningTolerancePercent) {
    auto scaledValue = GetScaledParameterValue(parameter.GetValue(),
                                               parameter.GetLowerLimit(),
                                               parameter.GetUpperLimit());
    if(ToleranceChecker::IsLowWarning(scaledValue, warningTolerancePercent)) {
        WarningAlert(parameter.GetParameterName(), "Approaching low breach", HealthChecker::printOnConsole);
    }
    else if(ToleranceChecker::IsHighWarning(scaledValue, warningTolerancePercent)) {
        WarningAlert(parameter.GetParameterName(), "Approaching high breach", HealthChecker::printOnConsole);
    }
}

float HealthChecker::GetScaledParameterValue(const float &value, const float &min, const float &max) {
    return ((value - min) / (max - min)) * 100;
}

void HealthChecker::WarningAlert(const std::string &parameterName, const std::string &status,
                                 std::function<void(const std::string&)> notify) {
    std::string message = PrepareParameterMessage(parameterName, Alarm, status);
    notify(message);
}

void HealthChecker::printOnConsole(const std::string &data) {
    std::cout << data;
}

} /* namespace Battery */
