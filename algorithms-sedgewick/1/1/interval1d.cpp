#include "interval1d.h"
#include <vector>

using std::cout;
using std::cin;
using std::endl;


int main(const int argc, const char *argv[]) {
  int N;

  cout << "Enter N: " << endl;
  cin >> N;
  double* a;
  double* b;
  a = new double[N];
  b = new double[N];
  std::vector<Interval> intervals;
  intervals.reserve(N);
  for (int i = 0; i < N; i++) {
    cout << "Enter a: " << endl;
    cin >> a[i];
    cout << "Enter b: " << endl;
    cin >> b[i];
    
    intervals.emplace_back(a[i], b[i]);
  }
  for (int i = 0; i < intervals.size(); i++) {
    for (int j = 0; j < i + 1; j++) {
      auto inter = intersect(intervals[i], intervals[j]);
      if (inter) {
        cout << inter->min() << " " << inter->max() << endl;
      }
    }
  }
  return 0;
}