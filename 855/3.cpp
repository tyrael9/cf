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

using namespace std;

const long long MOD_BASE = (1000000007LL);

long long dp[100000][11][3];
bool visited[100000][11][3];
vector<int> edge[100000];
long long lvldp[11][3];

long long n, m;
long long k;
int x;

#define SPECIAL 0
#define FREE 1
#define LIMITED 2

void dfs(int cur, int parent) {
  if ((edge[cur].empty()) ||
      ((edge[cur].size() == 1) && (parent >= 0))) {
    dp[cur][1][SPECIAL] = 1;
    dp[cur][0][FREE] = m - 1;
    dp[cur][0][LIMITED] = k - 1;
    return;
  }

  for (const auto nxt : edge[cur]) {
    if (nxt == parent) {
      continue;
    }
    dfs(nxt, cur);
  }

  bool first = true;
  for (const auto nxt : edge[cur]) {
    if (nxt == parent) {
      continue;
    }
    for (int i = x; i >= 0; --i) {
      if (!first) {
        long long sum[3] = {0};
        for (int j = 0; j <= i; ++j) {
          sum[SPECIAL] += lvldp[j][SPECIAL] * dp[nxt][i - j][LIMITED];
          sum[LIMITED] += lvldp[j][LIMITED] * (dp[nxt][i - j][SPECIAL] + dp[nxt][i - j][FREE]);
          sum[FREE] += lvldp[j][FREE] * dp[nxt][i - j][FREE];
          sum[SPECIAL] %= MOD_BASE;
          sum[LIMITED] %= MOD_BASE;
          sum[FREE] %= MOD_BASE;
        }
        lvldp[i][SPECIAL] = sum[SPECIAL];
        lvldp[i][LIMITED] = sum[LIMITED];
        lvldp[i][FREE] = sum[FREE];
      } else {
        lvldp[i][SPECIAL] = dp[nxt][i][LIMITED];
        lvldp[i][LIMITED] = (dp[nxt][i][SPECIAL] + dp[nxt][i][FREE]) % MOD_BASE;
        lvldp[i][FREE] = dp[nxt][i][FREE];
      }
    }
    first = false;
  }

  for (int i = x; i >= 0; --i) {
    dp[cur][i][SPECIAL] = (i == 0 ? 0 : lvldp[i - 1][SPECIAL]);
    dp[cur][i][FREE] = (lvldp[i][LIMITED] * (k - 1) + lvldp[i][FREE] * (m - k)) % MOD_BASE;
    dp[cur][i][LIMITED] = (lvldp[i][LIMITED] * (k - 1)) % MOD_BASE;
  }
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  cin >> k >> x;
  long long result = 0;
  dfs(0, -1);
  for (int i = 0; i <= x; ++i) {
    result = (result + dp[0][i][SPECIAL] + dp[0][i][FREE]) % MOD_BASE;
  }
  cout << result << "\n";
}