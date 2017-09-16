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

long a[501];
long b[501];

// DP[i][j] means LCIS with subarray a[0...i] and b[0...j], and must contain b[j]
int dp[501][501];
int step[501];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n, m;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
  }

  for (int i = 1; i <= n; ++i) {
    // pos is the index j with max dp[i][j] and b[j] less than a[i]
    int pos = 0;
    for (int j = 1; j <= m; ++j) {
      if (a[i] == b[j]) {
        // b[pos] < a[i], and dp[i][pos] is the greatest so far.
        dp[i][j] = dp[i][pos] + 1;
        step[j] = pos;
      } else {
        // b[j] must be selected, and a[i] != b[j], so a[i] is useless!
        dp[i][j] = dp[i - 1][j];
      }
      if (a[i] > b[j] && dp[i][pos] < dp[i][j]) {
        pos = j;
      }
    }
  }

  int maxlen = 0, step_cur = 0;
  for (int j = 1; j <= m; ++j) {
    if (dp[n][j] > maxlen) {
      maxlen = dp[n][j];
      step_cur = j;
    }
  }
  cout << maxlen << "\n";
  vector<long> result;
  while (step_cur != 0) {
    result.push_back(b[step_cur]);
    step_cur = step[step_cur];
  }
  std::reverse(result.begin(), result.end());
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i];
    if (i != result.size() - 1) {
      cout << " ";
    }
  }
  cout << "\n";
}