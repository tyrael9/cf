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

long long n, m, q;
long long a[100000];
long long b[100000];
long long f[100000];

long long get_result(long long x) {
  long long *lb = lower_bound(f, f + (m - n) + 1, -x);
  if (lb == f + (m - n) + 1) {
    return abs(f[m - n] + x);
  } else if (lb == f) {
    return abs(f[0] + x);
  } else {
    return min(abs(*(lb - 1) + x), abs(*lb + x));
  }
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n >> m >> q;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  long long sign = 1;
  for (int i = 0; i < n; ++i) {
    f[0] += sign * (a[i] - b[i]);
    sign *= -1;
  }
  if (m > n) {
    sign = 1;
    for (int i = 0; i < n; ++i) {
      f[1] += sign * (a[i] - b[i + 1]);
      sign *= -1;
    }
  }
  for (int i = 2; i <= (m - n); ++i) {
    f[i] = f[i - 2] + (b[i - 2] - b[i - 1]);
    if (n % 2 == 1) {
      f[i] += b[n + i - 2] - b[n + i - 1];
    } else {
      f[i] -= b[n + i - 2] - b[n + i - 1];
    }
  }
  sort(f, f + (m - n) + 1);
  long long x = 0;
  cout << get_result(x) << "\n";
  for (int i = 0; i < q; ++i) {
    long long l, r, cur_x;
    cin >> l >> r >> cur_x;
    if (((r - l) % 2) == 0) {
      if ((l % 2) == 0) {
        x -= cur_x;
      } else {
        x += cur_x;
      }
    }
    cout << get_result(x) << "\n";
  }
}