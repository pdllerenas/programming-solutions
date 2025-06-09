#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

double logNFactorial(int n) {
  if (n == 1) {
    return 0.0;
  }
  return log(n) + logNFactorial(n - 1);
}

int rank2(int key, vector<int> a, int lo, int hi, int iteration = 0) {
  if (lo > hi) {
    return -1;
  }
  int mid = lo + (hi - lo) / 2;
  printf("lo: %d, hi: %d, mid: %d, iteration: %d\n", lo, hi, mid, iteration);
  if (key < a[mid]) return rank2(key, a, lo, mid - 1, iteration + 1);
  if (key > a[mid]) return rank2(key, a, mid + 1, hi, iteration + 1);
  return mid;
}

int search(int key, vector<int> a) {
  printf("given key: %d\n", key);
  return rank2(key, a, 0, a.size() - 1);
}

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

vector<vector<bool>> rPrime(int n) {
  vector<vector<bool>> result(n, vector<bool>(n, false));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      result[i][j] = gcd(i + 1, j + 1) == 1;
    }
  }
  return result;
}

int main(const int argc, const char *argv[]) {
  if (string(argv[1]) == "1") {
    printf("%d\n", (0 + 15) / 2);
    printf("%f\n", (double)2.0e-6 * (double)100000000.1);
    printf("%d\n", true && false || true && true);
  }

  else if (string(argv[1]) == "2") {
    cout << (1+2.236)/2 << " with type " << typeid((1+2.236)/2).name() << endl;
    cout << 1+2+3+4.0 << " with type " << typeid(1+2+3+4.0).name() << endl;
    cout << (4.1 >= 4) << " with type " << typeid((4.1 >= 4)).name() << endl;
    cout << 1 + 2 + "3" << " with type " << typeid(1 + 2 + "3").name() << endl;
  }

  else if (string(argv[1]) == "3") {
    if (argc != 5) {
      cout << "Wrong number of arguments" << endl;
      return 1;
    }
    if (stoi(argv[2]) == stoi(argv[3]) && stoi(argv[3]) == stoi(argv[4])) {
      cout << "equal" << endl;
    }
    else {
      cout << "not equal" << endl;
    }
  }

  else if (string(argv[1]) == "4") {
    
  }
  else if (string(argv[1]) == "5") {
    if (argc != 4) {
      cout << "Wrong number of arguments" << endl;
      return 1;
    }
    double x = stod(argv[2]);
    double y = stod(argv[3]);

    cout << ((0 < x && x < 1 && 0 < y && y < 1) ? "true" : "false") << endl;
  }

  else if (string(argv[1]) == "6") {
    int f = 0;
    int g = 1;
    for (int i = 0; i <= 15; i++) {
      cout << f << endl;
      f = f + g;
      g = f - g;
    }
  }

  else if (string(argv[1]) == "7") {
    if (string(argv[2]) == "1") {
      double t = 9.0;
      while (abs(t - 9.0/t) > .001)
        t = (9.0/t + t) / 2.0;
      printf("%.5f\n", t);
    }
    else if (string(argv[2]) == "2") {
      int sum = 0;
      for (int i = 1; i < 1000; i++) {
        for (int j = 0; j < i; j++) {
          sum++;
        }
      }
      cout << sum << endl;
    }

    else if (string(argv[2]) == "3") {
      int sum = 0;
      for (int i = 1; i < 1000; i *= 2) {
        for (int j = 0; j < i; j++) {
          sum++;
        }
      }
      cout << sum << endl;
    }
    
  }

  else if (string(argv[1]) == "20") {
    printf("%f\n", logNFactorial(stoi(argv[2])));
  }
  
  else if (string(argv[1]) == "22") {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    search(stoi(argv[2]), a);
  }

  else if (string(argv[1]) == "30") {
    vector<vector<bool>> result = rPrime(stoi(argv[2]));
    for (int i = 0; i < result.size(); i++) {
      for (int j = 0; j < result[i].size(); j++) {
        cout << result[i][j] << " ";
      }
      cout << endl;
    }
  }



  
  return 0;
}

