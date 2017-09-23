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

long long x, y, n;

#define N 1000000LL

long long cnt[N + 1];
long long sum[N + 1];
bool v[N + 1];

long long min_cost_for_prime_factor(long long k) {
  long long c = x / y;
  long long cost = 0;
  c = min(c, k - 1);
  for (long long i = k; i < N + k; i += k) {
    cost += x * (cnt[min(i - c - 1, N)] - cnt[i - k]);
    cost += y * ((cnt[min(i - 1, N)] - cnt[min(i - c - 1, N)]) * i - (sum[min(i - 1, N)] - sum[min(i - c - 1, N)]));
  }
  return cost;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);
  
  cin >> n >> x >> y;
  for (long long i = 0; i < n; ++i) {
    long a;
    cin >> a;
    cnt[a] += 1;
    sum[a] += a;
  }

  for (long long i = 1; i <= N; ++i) {
    cnt[i] += cnt[i - 1];
    sum[i] += sum[i - 1];
  }

  long long min_cost = x * n;
  for (long long k = 2; k <= N; ++k) {
    if (v[k]) {
      continue;
    }
    long long tmp = min_cost_for_prime_factor(k);
    if (min_cost > tmp) {
      // cout << tmp << " " << k << endl;
      min_cost = tmp;
    }
    for (long long j = k; j <= N; j+=k) {
      v[j] = true;
    }
  }
  cout << min_cost << endl;
}