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
#include <string.h>

using namespace std;

int n, k;
long long M;
long long t[45];
long long sum_t;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n >> k >> M;
  sum_t = 0;
  for (int i = 0; i < k; ++i) {
    cin >> t[i];
    sum_t += t[i];
  }
  sort(t, t + k);
  long long maxpoints = 0;
  for (int i = 0; i <= n; ++i) {
    long long points = i * (k + 1);
    long long rem = M - i * sum_t;
    if (rem < 0) {
      continue;
    }
    int j = 0;
    while ((rem >= 0) && (j < k)) {
      if (rem >= t[j] * (n - i)) {
        rem -= t[j] * (n - i);
        points += (n - i);
      } else {
        break;
      }
      ++j;
    }
    if (j == k) {
      points += (n - i);
    } else {
      points += (rem / t[j]) * (j == k - 1 ? 2 : 1);
    }
    maxpoints = max(points, maxpoints);
  }
  cout << maxpoints << endl;
}