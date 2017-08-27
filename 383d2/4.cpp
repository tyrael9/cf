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
#include <stdio.h>
#include <math.h>

using namespace std;

long warr[1000];
long b[1000];

int parent[1000];
int rk[1000];

long dp[1001];

void makeset(int x) {
  parent[x] = x;
  rk[x] = 0;
}

int find(int x) {
  if (parent[x] != x) {
    parent[x] = find(parent[x]);
  }
  return parent[x];
}

void unionxy(int x, int y) {
  int rx = find(x);
  int ry = find(y);

  if (rx == ry) {
    return;
  }

  if (rk[rx] < rk[ry]) {
    parent[rx] = ry;
  } else if (rk[rx] > rk[ry]) {
    parent[ry] = rx;
  } else {
    parent[ry] = rx;
    rk[rx] += 1;
  }
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  long n, m, w;
  cin >> n >> m >> w;
  for (int i = 0; i < n; ++i) {
    cin >> warr[i];
    makeset(i);
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  for (long i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    unionxy(x - 1, y - 1);
  }

  map<int, set<int>> total;
  for (int i = 0; i < n; ++i) {
    total[find(i)].insert(i);
  }
  for (int i = 0; i <= w; ++i) {
    dp[i] = 0;
  }
  for (const auto& p : total) {
    for (int v = w; v >= 0; --v) {
      const auto& ss = p.second;
      long totalw = 0;
      long totalb = 0;
      for (const auto& id : ss) {
        if (v - warr[id] >= 0) {
          dp[v] = max(dp[v], dp[v - warr[id]] + b[id]);
        }
        totalw += warr[id];
        totalb += b[id];
      }
      if (v - totalw >= 0) {
        dp[v] = max(dp[v], dp[v - totalw] + totalb);
      }
    }
  }
  long maxb = 0;
  for (int i = 0; i <= w; ++i) {
    maxb = max(maxb, dp[i]);
  }
  cout << maxb << endl;
}