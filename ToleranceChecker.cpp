#include "ToleranceChecker.h"

namespace Battery {

bool ToleranceChecker::IsLowWarning(float value, int tolerance_percent) {
    return IsInRange(value, 0, tolerance_percent);
}

bool ToleranceChecker::IsHighWarning(float value, int tolerance_percent) {
    return IsInRange(value, 100 - tolerance_percent, 100);
}

bool ToleranceChecker::IsInRange(float value, float min, float max) {
    return (value >= min && value <= max);
}

} /* namespace Battery */
