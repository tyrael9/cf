#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <bitset>
#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;

int t1, t2, xc, yc, xh, yh, xs, ys;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> t1 >> t2;
  cin >> xc >> yc;
  cin >> xh >> yh;
  cin >> xs >> ys;

  double s_ch = sqrt((xc - xh) * (xc - xh) + (yc - yh) * (yc - yh));
  double s_cs = sqrt((xc - xs) * (xc - xs) + (yc - ys) * (yc - ys));
  double s_sh = sqrt((xh - xs) * (xh - xs) + (yh - ys) * (yh - ys));
  double result;

  if (s_cs + s_sh > s_ch + t2) {
    double r1 = (double)t1 + s_cs;
    double r2 = (double)t2 + s_ch;
    double l = 0, r = min(r1, r2);
    for (int i = 0; i < 500; ++i) {
      double mid = l + (r - l) * 0.5;
      double r1p = r1 - mid;
      double r2p = r2 - mid;
      if (s_sh > r1p + r2p) {
        right = mid;
      } else {
        left = mid;
      }
    }
  } else {
    result = min(s_cs + s_sh + (double)t1, s_ch + (double)t2);
  }
  std::cout.precision(6);
  cout << std::fixed << result << endl;
}