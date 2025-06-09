#include <iostream>
using std::cout;
using std::endl;

class Matrix {
  double** matrix;
  int rows;
  int cols;

  public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
      matrix = new double*[rows];
      for (int i = 0; i < rows; i++) {
        matrix[i] = new double[cols];
      }
    }

    ~Matrix() {
      for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
      }
      delete[] matrix;
    }

    void print() {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          cout << matrix[i][j] << " ";
        }
        cout << endl;
      }
    }

    void set(int i, int j, double value) {
      matrix[i][j] = value;
    }

    static double dot(double* x, double* y) {
      double result = 0;
      for (int i = 0; i < 3; i++) {
        result += x[i] * y[i];
      }
      return result;
    }

    static Matrix mult(const Matrix& a, const Matrix& b) {
      Matrix result(a.rows, b.cols);
      for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
          int sum = 0;
          for (int k = 0; k < a.cols; k++) {
            sum += a.matrix[i][k] * b.matrix[k][j];
          }
          result.set(i, j, sum);
        }
      }
      return result;
    }

    static double* mult(const Matrix& a, const double* x) {
      double* result = new double[a.rows];
      for (int i = 0; i < a.rows; i++) {
        result[i] = 0;
        for (int j = 0; j < a.cols; j++) {
          result[i] += a.matrix[i][j] * x[j];
        }
      }
      return result;
    }

    static double* mult(const double* x, const Matrix& a) {
      double* result = new double[a.cols];
      for (int i = 0; i < a.cols; i++) {
        result[i] = 0;
        for (int j = 0; j < a.rows; j++) {
          result[i] += a.matrix[j][i] * x[j];
        }
      }
      return result;
    }

    Matrix transpose() const {
      Matrix result(cols, rows);
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          result.set(j, i, matrix[i][j]);
        }
      }
      return result;
    }

    static Matrix transpose(const Matrix& a) {
      return a.transpose();
    }
};