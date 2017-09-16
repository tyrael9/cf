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

long long a[400];
long long g[400];
long long m[400];
long long g_tmp[400];
int n;

void greedy_change(long long val, long long *result) {
  for (int i = 0; i < n; ++i) {
    result[i] = val / a[i];
    val = val % a[i];
  }
}

long long get_num(long long *res) {
  long long w = 0;
  for (int i = 0; i < n; ++i) {
    w += res[i] * a[i];
  }
  return w;
}

long long get_sum(long long *res) {
  long long s = 0;
  for (int i = 0; i < n; ++i) {
    s += res[i];
  }
  return s;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long minw = -1;
  for (int i = 1; i < n; ++i) {
    greedy_change(a[i - 1] - 1, g);
    for (int k = 0; k < n; ++k) {
      m[k] = (k <= i - 1 ? g[k] : 0);
    }
    for (int j = i; j < n; ++j) {
      m[j - 1] = g[j - 1];
      m[j] = g[j] + 1;
      long long w = get_num(m);
      greedy_change(w, g_tmp);
      if (get_sum(m) < get_sum(g_tmp)) {
        minw = (minw < 0 ? w : min(minw, w));
      }
    }
  }

  cout << minw << endl;
  return 0;
}