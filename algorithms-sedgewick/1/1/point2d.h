#include <random>
#include <iostream>

using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;

class Point2D {
  double* x, *y;
  int N;
  public:
    Point2D(int N) : N(N) {
      x = new double[N];
      y = new double[N];
      unitSquarePoints();
    }
    
    ~Point2D() {
      delete[] x;
      delete[] y;
    }

    void print() {
      for (int i = 0; i < N; i++) {
        std::cout << x[i] << " " << y[i] << std::endl;
      }
      std::cout << "min distance: " << getMinDistance() << std::endl;

      double** min_distance_points = getMinDistancePoints();
      std::cout << "min distance points: " << "(" << *min_distance_points[0] << ", " << *min_distance_points[1] << "), (" << *min_distance_points[2] << ", " << *min_distance_points[3] << ")" << std::endl;


      std::cout << std::endl;
    }

    double getMinDistance() {
      double min = INFINITY;
      for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
          double distance = std::sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
          if (distance < min) {
            min = distance;
          }
        }
      }
      return min;
    }

    double** getMinDistancePoints() {
      double** min = new double*[4];
      double min_d = INFINITY;
      for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
          double distance = std::sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
          if (distance < min_d) {
            min_d = distance;
            min[0] = &x[i];
            min[1] = &y[i];
            min[2] = &x[j];
            min[3] = &y[j];
          }
        }
      }
      return min;
    }
  
  private:
    void unitSquarePoints() {
      random_device rd;
      mt19937 gen(rd());
      uniform_real_distribution<> dis(0.0, 4.0);
      for (int i = 0; i < N; i++) {
        double d = dis(gen);
        if (d < 1.0) {
          x[i] = d;
          y[i] = 0;
        } else if (d < 2.0) {
          x[i] = 1.0;
          y[i] = d - 1.0;
        } else if (d < 3.0) {
          x[i] = d - 2.0;
          y[i] = 1.0;
        } else {
          x[i] = 0;
          y[i] = d - 3.0;
        }
      }
    }
};