#include "HealthChecker.h"
#include <assert.h>

void TestIsOk() {
  Battery::HealthChecker BatteryHealthchecker;
  assert(BatteryHealthchecker.IsOk(25, 70, 0.7) == true);
  assert(BatteryHealthchecker.IsOk(50, 85, 0) == false);
}

void TestIsParameterOutOfRange() {
  Battery::HealthChecker BatteryHealthchecker;
  Temperature t(50, 100, 200);
  assert(BatteryHealthchecker.IsParameterOutOfRange(t) == true);
  StateOfCharge soc(5.0, 4.0, 5.0);
  assert(BatteryHealthchecker.IsParameterOutOfRange(soc) == false);  
}

int main() {
  TestIsOk();
}
