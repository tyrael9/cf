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

long a[200000];
long b[200000];
bool visited[200000];
unordered_map<long, long> counts;

void dfs(int i, int depth, const vector<vector<int>>& adj) {
  visited[i] = true;
  if (depth <= 2) {
    for (long x = 1; x * x <= a[i]; ++x) {
      if (a[i] % x == 0) {
        ++counts[x];
        if (x * x != a[i]) {
          ++counts[a[i] / x];
        }
      }
    }
  } else {
    for (auto& p : counts) {
      if (a[i] % p.first == 0) {
        ++p.second;
      }
    }
  }
  b[i] = 0;
  for (auto& p : counts) {
    if (p.second >= depth - 1) {
      b[i] = max(b[i], p.first);
    }
  }
  for (const auto child : adj[i]) {
    if (visited[child]) {
      continue;
    }
    dfs(child, depth + 1, adj);
  }
  vector<long> to_erase;
  for (auto& p : counts) {
    if (a[i] % p.first == 0) {
      --p.second;
      if (p.second == 0) {
        to_erase.push_back(p.first);
      }
    }
  }
  for (long t : to_erase) {
    counts.erase(t);
  }
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    visited[i] = false;
  }
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  dfs(0, 1, adj);
  for (int i = 0; i < n; ++i) {
    cout << b[i];
    if (i < n - 1) {
      cout << " ";
    }
  }
  cout << "\n";
}