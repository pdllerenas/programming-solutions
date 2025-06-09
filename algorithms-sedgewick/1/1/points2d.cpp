#include "point2d.h"

int main() {
  int N;

  std::cout << "Enter N: " << std::endl;
  std::cin >> N;

  Point2D p(N);

  p.print();
  return 0;
}