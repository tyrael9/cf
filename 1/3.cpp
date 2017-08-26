#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;

int main(int argc, char** argv) {
  double x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1;
  cin >> x2 >> y2;
  cin >> x3 >> y3;
  double a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  double b = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
  double c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
  double r = a * b * c / sqrt((a + b + c) * (a + b - c) * (a - b + c) * (b + c - a));
  double v12 = 2.0 * asin(0.5 * a / r);
  double v23 = 2.0 * asin(0.5 * b / r);
  double v13 = 2.0 * asin(0.5 * c / r);
  int n = -1;
  int it1, it2, it3;
  double err;
  for (int i = 3; i <= 100; ++i) {
    double cur_t1 = 0.5 * (double)i * v12 / M_PI;
    double cur_t2 = 0.5 * (double)i * v23 / M_PI;
    double cur_t3 = 0.5 * (double)i * v13 / M_PI;
    int cur_it1 = (abs(cur_t1 - floor(cur_t1)) < abs(cur_t1 - ceil(cur_t1)) ? floor(cur_t1) : ceil(cur_t1));
    int cur_it2 = (abs(cur_t2 - floor(cur_t2)) < abs(cur_t2 - ceil(cur_t2)) ? floor(cur_t2) : ceil(cur_t2));
    int cur_it3 = (abs(cur_t3 - floor(cur_t3)) < abs(cur_t3 - ceil(cur_t3)) ? floor(cur_t3) : ceil(cur_t3));
    if ((n > 0) && (it1 * i == cur_it1 * n) && (it2 * i == cur_it2 * n) && (it3 * i == cur_it3 * n)) {
      continue;
    }
    double cur_err = min(abs(cur_t1 - floor(cur_t1)), abs(cur_t1 - ceil(cur_t1))) + min(abs(cur_t2 - floor(cur_t2)), abs(cur_t2 - ceil(cur_t2))) + min(abs(cur_t3 - floor(cur_t3)), abs(cur_t3 - ceil(cur_t3)));
    if ((n < 0) || (cur_err < err)) {
      n = i;
      it1 = cur_it1;
      it2 = cur_it2;
      it3 = cur_it3;
      err = cur_err;
    }
  }
  double area = 0.5 * (double)n * r * r * sin(2.0 * M_PI / (double)n);
  std::cout.precision(6);
  cout << std::fixed << area << endl;
}