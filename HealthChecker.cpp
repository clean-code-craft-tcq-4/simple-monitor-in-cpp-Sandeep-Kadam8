#include "HealthChecker.h"
#include "Temperature.h"
#include "StateOfCharge.h"
#include "ChargeRate.h"
#include <iostream>
#include <sstream>

namespace Battery {

HealthChecker::HealthChecker() {

}

HealthChecker::~HealthChecker() {
}

bool HealthChecker::IsOk(float temperature, float soc, float chargeRate) {
    std::vector<Parameter<float>> parameters = {Temperature(temperature), StateOfCharge(soc), ChargeRate(chargeRate)};

    bool result = true;
    for(const auto& parameter:parameters) {
        if(IsParameterOutOfRange(parameter)) {
            WarningOutOfRange(parameter.GetParameterName(), HealthChecker::printOnConsole);
            result = false;
        }
    }

    return result;
}

std::string HealthChecker::PrepareParameterMessage(const std::string &parameterName, const std::string &status) {
    std::stringstream string;
    string << parameterName << ": " << status << "\n";
    return string.str();
}

void HealthChecker::WarningOutOfRange(const std::string & parameterName, std::function<void(const std::string&)> function) {
    std::string message = PrepareParameterMessage(parameterName, OUTOFRANGE);
    function(message);
}

void HealthChecker::printOnConsole(const std::string &data) {
    std::cout << data;
}

} /* namespace Battery */
