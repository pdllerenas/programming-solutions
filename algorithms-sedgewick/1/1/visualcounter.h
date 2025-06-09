#include "../../matplotlib-cpp/matplotlibcpp.h"

class VisualCounter {
  private:
    int N;
    int max;
    int count;
    int iteration;

  public:
    VisualCounter(int N, int max) : N(N), max(max) {}

    void increment() {
      if (count < max && iteration < N) {
        count++;
        iteration++;
      }

    }

    void decrease() {
      if (count > -max && iteration < N) {
        count--;
        iteration++;
      }
    }

    void print() {

    }
  
};