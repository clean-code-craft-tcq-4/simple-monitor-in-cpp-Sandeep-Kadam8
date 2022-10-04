#include "HealthChecker.h"
#include "Temperature.h"
#include "StateOfCharge.h"
#include "ChargeRate.h"
#include <assert.h>

void TestIsOk() {
  Battery::HealthChecker BatteryHealthchecker;
  assert(BatteryHealthchecker.IsOk(50, 70, 0.7) == true);
  assert(BatteryHealthchecker.IsOk(75, 85, 0) == false);
}

void TestIsParameterOutOfRange() {
  Battery::HealthChecker BatteryHealthchecker;
  Battery::Temperature t(50, 100, 200);
  assert(BatteryHealthchecker.IsParameterOutOfRange(t) == true);
  Battery::StateOfCharge soc(5.0, 4.0, 5.0);
  assert(BatteryHealthchecker.IsParameterOutOfRange(soc) == false);
  Battery::ChargeRate chargeRate(0.8, 0.0, 0.8);
  assert(BatteryHealthchecker.IsParameterOutOfRange(chargeRate) == false);
}

void TestCheckForEarlyWarning() {
    Battery::HealthChecker BatteryHealthchecker;
    Battery::StateOfCharge soc(78.0);
    BatteryHealthchecker.CheckForEarlyWarning(soc, 5);
}

int main() {
  TestIsOk();
  TestIsParameterOutOfRange();
  TestCheckForEarlyWarning();
}
