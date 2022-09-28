#include "HealthChecker.h"
#include <assert.h>

int main() {
  Battery::HealthChecker BatteryHealthchecker;
  BatteryHealthchecker.IsOk(25, 70, 0.7) == true;  
  //assert(BatteryHealthchecker.IsOk(50, 85, 0) == false);
}
