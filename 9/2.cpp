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
#include <cmath>

using namespace std;

#define EPS 1e-6

long long x[100];

int get_deviation(double a, double b) {
  double delta = a - b;
  if (abs(delta) < EPS) return 0;
  return (delta > 0 ? 1 : -1);
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n;
  long long vb, vs;
  cin >> n >> vb >> vs;
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  long long xu, yu;
  cin >> xu >> yu;

  double min_time = -1.0;
  int min_i = 0;
  long long min_to_univ = 0;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      continue;
    }
    double t = (double)x[i] / (double)vb + sqrt((x[i] - xu) * (x[i] - xu) + yu * yu) / (double)vs;
    long long to_univ = (x[i] - xu) * (x[i] - xu) + yu * yu;
    if (min_time < 0 || get_deviation(t, min_time) < 0 ||
        (get_deviation(t, min_time) == 0 && to_univ < min_to_univ)) {
      min_time = t;
      min_i = i;
      min_to_univ = to_univ;
    }
  }
  cout << min_i + 1 << endl;
}