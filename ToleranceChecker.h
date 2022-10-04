#ifndef TOLERANCECHECKER_H_
#define TOLERANCECHECKER_H_

namespace Battery {

class ToleranceChecker final {
 public:
    ToleranceChecker();
    virtual ~ToleranceChecker() = default;

    static bool IsLowWarning(float value, int tolerance_percent);
    static bool IsHighWarning(float value, int tolerance_percent);
    static bool IsInRange(float value, float min, float max);
};

} /* namespace Battery */

#endif /* TOLERANCECHECKER_H_ */
