#include <array>
#include <optional>
#include <iostream>
#include <algorithm>

using std::array;

class Interval {
  array<double, 2> interval;
  public:
    Interval(double a, double b) {
      if (a < b) {
        interval = {a, b};
      }
      else {
        interval = {b, a};
      }
    }

    double min() const { return interval[0]; }
    double max() const { return interval[1]; }

    friend std::ostream& operator<<(std::ostream& os, const Interval& i) {
      os << "[" << i.min() << ", " << i.max() << "]";
      return os;
    }

    bool operator==(const Interval& other) const {
      return min() == other.min() && max() == other.max();
    }

};

std::optional<Interval> intersect(const Interval& a, const Interval& b) {
  double start = std::max(a.min(), b.min());
  double end = std::min(a.max(), b.max());
  if (start <= end) {
    return Interval(start, end);
  }
  return std::nullopt;
}