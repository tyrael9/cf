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
#include <stdio.h>
#include <math.h>

using namespace std;

long dp[1 << 24];     //bit = 0 (not linked), = 1 (linked with another)
int dp_prev[1 << 24];
long x[25];
long y[25];
long dis[25][25];
long xs, ys;
int nmax;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> x[0] >> y[0];
  cin >> nmax;
  long sum = 0;
  for (int i = 1; i <= nmax; ++i) {
    cin >> x[i] >> y[i];
    dis[0][i] = (x[i] - x[0]) * (x[i] - x[0]) + (y[i] - y[0]) * (y[i] - y[0]);
    sum += 2 * dis[0][i];
  }
  for (int i = 1; i <= nmax; ++i) {
    for (int j = i + 1; j <= nmax; ++j) {
      dis[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    }
  }
  dp[0] = sum;
  int n = 0;
  unsigned long next_num = 2;
  long result = dp[0];
  unsigned long min_time_num = 0;
  unsigned long num_max = (1 << nmax);
  for (unsigned long num = 1; num < num_max; ++num) {
    if (num == next_num) {
      next_num = next_num << 1;
      ++n;
    }
    int min_time = -1;
    int min_i = -1;
    for (int i = 0; i < n; ++i) {
      if (((num >> i) & 1) == 1) {
        unsigned long mask = ((((1ULL << n) - 1) >> (i + 1)) << (i + 1)) | ((1 << i) - 1);
        long val = dp[num & mask];
        if (val < 0) {
          continue;
        }
        val -= dis[0][i + 1];
        val -= dis[0][n + 1];
        val += dis[i + 1][n + 1];
        if ((min_time < 0) || (min_time > val)) {
          min_time = val;
          min_i = i;
        }
      }
    }
    dp[num] = min_time;
    dp_prev[num] = min_i;

    if ((dp[num] >= 0) && (dp[num] < result)) {
      result = dp[num];
      min_time_num = num;
    }
  }
  cout << result << endl;
  bitset<24> bs(min_time_num);
  int hs = 23;
  cout << 0;
  while (bs.any()) {
    while(bs[hs] == 0) {
      --hs;
    }
    int prev_i = dp_prev[bs.to_ulong()];
    bs[hs] = 0;
    bs[prev_i] = 0;
    cout << " " << hs + 1 << " " << prev_i + 1 << " " << 0;
  }
  for (int j = 0; j < nmax; ++j) {
    if (((min_time_num >> j) & 1) == 0) {
      cout << " " << j + 1 << " " << 0;
    }
  }
  cout << endl;
}