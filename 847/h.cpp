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

int n;
long long a[100000];
long long after[100000];
long long before[100000];
long long before_val[100000];
long long after_val[100000];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  before[0] = 0;
  before_val[0] = a[0];
  long long cur_max = a[0];
  long long cur_sum = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] <= cur_max) {
      ++cur_max;
    } else {
      cur_max = a[i];
    }
    cur_sum += (cur_max - a[i]);
    before[i] = cur_sum;
    before_val[i] = cur_max;
  }
  after[n - 1] = 0;
  after_val[n - 1] = a[n - 1];
  cur_max = a[n - 1];
  cur_sum = 0;
  for (int i = n - 2; i >= 0; --i) {
    if (a[i] <= cur_max) {
      ++cur_max;
    } else {
      cur_max = a[i];
    }
    cur_sum += (cur_max - a[i]);
    after[i] = cur_sum;
    after_val[i] = cur_max;
  }
  long long best = -1;
  for (int i = 0; i < n; ++i) {
    long long val = after[i] + before[i] - (min(before_val[i], after_val[i]) - a[i]);
    best = (best < 0 ? val : min(best, val));
  }
  cout << best << endl;
}