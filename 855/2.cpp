#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <list>
#include <stack>
#include <bitset>
#include <cmath>
#include <climits>
#include <cassert>

using namespace std;

long long before_min[100000];
long long before_max[100000];
long long after_min[100000];
long long after_max[100000];
long long a[100000];

long long n, p, q, r;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n >> p >> q >> r;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  before_min[0] = a[0];
  before_max[0] = a[0];
  for (long long i = 1; i < n; ++i) {
    before_min[i] = min(before_min[i - 1], a[i]);
    before_max[i] = max(before_max[i - 1], a[i]);
  }
  after_min[n - 1] = a[n - 1];
  after_max[n - 1] = a[n - 1];
  for (long long i = n - 2; i >= 0; --i) {
    after_min[i] = min(after_min[i + 1], a[i]);
    after_max[i] = max(after_max[i + 1], a[i]);
  }
  long long result = 0;
  bool have_result = false;
  for (long long j = 0; j < n; ++j) {
    long long cur_max = q * a[j] + p * (p < 0 ? before_min[j] : before_max[j]) + r * (r < 0 ? after_min[j] : after_max[j]);
    if ((!have_result) || (result < cur_max)) {
      have_result = true;
      result = cur_max;
    }
  }
  cout << result << "\n";
}