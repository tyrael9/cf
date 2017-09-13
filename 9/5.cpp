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

int n, m;
vector<vector<int>> g(50);
map<int, pair<int, int>> path;

bool add_path(int x, int y) {
  if ((x == y) || ((path.find(x) != path.end()) && (path[x].first == y))) {
    // has cycle
    return true;
  }
  int a = x, b = y;
  int len = 1;
  if (path.find(x) != path.end()) {
    a = path[x].first;
    len += path[x].second;
    path.erase(x);
  }
  if (path.find(y) != path.end()) {
    b = path[y].first;
    len += path[y].second;
    path.erase(y);
  }
  path[a] = {b, len};
  path[b] = {a, len};
  return false;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  for (int i = 0; i < n; ++i) {
    if (g[i].size() > 2) {
      cout << "NO\n";
      return 0;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (const int j : g[i]) {
      if (i <= j) {
        if (add_path(i, j)) {
          cout << (path[i].second == n - 1 ? "YES\n0\n" : "NO\n");
          return 0;
        }
      }
    }
  }
  vector<int> to_remove;
  for (const auto& p : path) {
    if (p.first > p.second.first) {
      to_remove.push_back(p.first);
    }
  }
  for (const auto& p : to_remove) {
    path.erase(p);
  }
  for (int i = 0; i < n; ++i) {
    if (g[i].empty()) {
      path[i] = {i, 0};
    }
  }
  // for (const auto& p : path) {
  //   cout << "PATH " << p.first << " " << p.second.first << endl;
  // }
  cout << "YES\n" << path.size() << "\n";
  while (path.size() > 1) {
    auto it = path.begin();
    int a = it->first, b = it->second.first, len1 = it->second.second;
    ++it;
    int c = it->first, d = it->second.first, len2 = it->second.second;
    path.erase(a);
    path.erase(c);
    path[min(b, d)] = {max(b, d), len1 + len2 + 1};
    cout << a + 1 << " " << c + 1 << "\n";
  }
  cout << path.begin()->first + 1 << " " << path.begin()->second.first + 1 << "\n";
  return 0;
}