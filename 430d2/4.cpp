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
#include <unordered_map>

using namespace std;

const long long N = (1 << 20);

long long n, m;
long long t[(N << 1)];

long long solve(long long x, long long cur, int b) {
  if (b < 0) {
    return 0;
  }
  if ((x >> b) & 1) {
    if (t[(cur << 1) | 1] < (1 << b)) {
      return solve(x, (cur << 1) | 1, b - 1);
    } else {
      return (1 << b) | solve(x, (cur << 1), b - 1);
    }
  } else {
    if (t[(cur << 1)] < (1 << b)) {
      return solve(x, (cur << 1), b - 1);
    } else {
      return (1 << b) | solve(x, (cur << 1) | 1, b - 1);
    }
  }
}

void dfs_sum(long long v) {
  if (v >> 20) {
    return;
  }
  dfs_sum(v << 1);
  dfs_sum((v << 1) | 1);
  t[v] = t[v << 1] + t[(v << 1) | 1];
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);
  
  cin >> n >> m;
  for (long long i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    t[a | N] = 1LL;
  }
  dfs_sum(1LL);
  long long cur_x = 0;
  for (long long i = 0; i < m; ++i) {
    long long x;
    cin >> x;
    cur_x ^= x;
    cout << solve(cur_x, 1LL, 19) << "\n";
  }
}