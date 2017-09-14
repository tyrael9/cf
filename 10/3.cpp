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

const int N = 1000000;

long long cnt[10] = {0};
long long bad_count = 0;
int d[N + 1];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  long long n;
  cin >> n;
  for (int i = 1; i <= 9; ++i) {
    d[i] = i;
  }

  long long nn = max(n, 100LL);
  for (long long i = 1; i <= nn; ++i) {
    long long t = (i / 1000000) + ((i / 100000) % 10) + ((i / 10000) % 10) + ((i / 1000) % 10) + ((i / 100) % 10) + ((i / 10) % 10) + (i  % 10);
    d[i] = d[t];
    if (i <= n) {
      ++cnt[d[i]];
    }
  }

  for (long long i = 1; i <= n; ++i) {
    for (long long k = i, p = 1; k <= n; k += i, ++p) {
      if (d[k] == d[d[p] * d[i]]) {
        ++bad_count;
      }
    }
  }

  long long ttl_count = 0;
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      if ((cnt[i] > 0) && (cnt[j] > 0)) {
        ttl_count += cnt[i] * cnt[j] * cnt[d[i * j]];
      }
    }
  }
  cout << ttl_count - bad_count << "\n";
}