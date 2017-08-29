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

long long dp[1 << 24];     //processed i, left j
long long x[24];
long long y[24];
long long xs, ys;
int nmax;

void dfs(int n, unsigned long num, int num_ones) {
  if (num_ones % 2 == 0) {
    if (((num >> n) & 1) == 1) {
      int min_time = -1;
      for (int i = 0; i < n; ++i) {
        if (((num >> i) & 1) == 1) {
          unsigned long mask = ((((1ULL << n) - 1) >> (i + 1)) << (i + 1)) | ((1 << i) - 1);
          long long val = dp[num & mask];
          val -= ((x[i] - xs) * (x[i] - xs) + (y[i] - xs) * (y[i] - xs));
          val -= ((x[n] - xs) * (x[n] - xs) + (y[n] - xs) * (y[n] - xs));
          val += (x[n] - x[i]) * (x[n] - x[i]) + (y[n] - y[i]) * (y[n] - y[i]);
          if ((min_time < 0) || (min_time > val)) {
            min_time = val;
          }
        }
      }
      dp[num] = min_time;
    }
  } else {
    dp[num] = -1;
  }
  if (n < nmax - 1) {
    dfs(n + 1, num, num_ones);
    dfs(n + 1, num | (1 << (n + 1)), num_ones + 1);
  }
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> xs >> ys;
  cin >> nmax;
  long long sum = 0;
  for (int i = 0; i < nmax; ++i) {
    cin >> x[i] >> y[i];
    sum += 2 * ((x[i] - xs) * (x[i] - xs) + (y[i] - ys) * (y[i] - ys));
  }
  dp[0] = sum;
  dfs(0, 0, 0);
  dfs(0, 1, 1);
  long long result = dp[0];
  for (unsigned long i = 0; i < (1 << nmax); ++i) {
    if ((dp[i] >= 0) && (dp[i] < result)) {
      result = dp[i];
    }
  }
  cout << result << endl;
}