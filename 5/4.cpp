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
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  long long a, v, l, d, w;
  cin >> a >> v;
  cin >> l >> d >> w;

  double t;
  if (w * w > 2 * a * d) {
    if (v * v < 2 * a * l) {
      t = (double)l / (double)v + 0.5 * (double)v / (double)a;
    } else {
      t = sqrt((double)(2 * l) / (double)a);
    }
  } else {
    if (v < w) {
      t = (double)l / (double)v + 0.5 * (double)v / (double)a;
    } else {
      long long dd = v * v + (v - w) * (v + w);
      double t1, t2;
      if (dd < 2 * a * d) {
        t1 = (double)(2 * a * d - dd) / (double)(2 * a * v) + (double)(2 * v - w) / (double)a;
      } else {
        double t11 = sqrt((double)(2 * a * d + w * w) / (double)(2 * a * a));
        double t12 = t11 - (double)(w) / (double)(a);
        t1 = t11 + t12;
      }
      long long ldd = (v - w) * (v + w);
      if (ldd > 2 * a * (l - d)) {
        t2 = (sqrt((double)(4 * w * w - 8 * a * (d - l))) - (double)(2 * w)) / (double)(2 * a);
      } else {
        t2 = (double)(v - w) / (double)a + (double)(2 * a * (l - d) - ldd) / (double)(2 * a * v);
      }
      t = t1 + t2;
    }
  }
  std::cout.precision(6);
  cout << std::fixed << t << endl;
}