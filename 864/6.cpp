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

vector<pair<int, int>> query[3000][3000];
vector<int> edges[3000];
int q_result[400000];
int n, m, q;
int cur_s;

char color[3000];
bool in_cycle[3000];
vector<int> path;
int rev_index_in_path[3000];

#define WHITE 0
#define GRAY  1
#define BLACK 2

void clear_state() {
  memset(color, 0, 3000);
  memset(in_cycle, 0, 3000);
}

void dfs(int cur, bool no_ideal) {
  if (color[cur] == BLACK) {
    return;
  }
  if (color[cur] == GRAY) {
    // cycle
    for (int i = rev_index_in_path[cur]; i < path.size(); ++i) {
      if (in_cycle[path[i]]) {
        break;
      }
      in_cycle[path[i]] = true;
    }
    return;
  }

  color[cur] = GRAY;
  path.push_back(cur);
  rev_index_in_path[cur] = path.size() - 1;
  if (!query[cur_s][cur].empty()) {
    if (no_ideal) {
      for (const auto& p : query[cur_s][cur]) {
        q_result[p.second] = -1;
      }
    } else {
      for (const auto& p : query[cur_s][cur]) {
        q_result[p.second] = (p.first < path.size() ? (path[p.first] + 1) : -1);
      }
    }
  }
  for (const auto nxt : edges[cur]) {
    dfs(nxt, no_ideal || in_cycle[cur]);
  }
  path.pop_back();
  color[cur] = BLACK;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n >> m >> q;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    edges[x].push_back(y);
  }
  for (int i = 0; i < n; ++i) {
    sort(edges[i].begin(), edges[i].end());
  }
  for (int i = 0; i < q; ++i) {
    int s, t, k;
    cin >> s >> t >> k;
    --s;
    --t;
    --k;
    query[s][t].push_back({k, i});
    q_result[i] = -1;
  }
  for (int i = 0; i < n; ++i) {
    clear_state();
    cur_s = i;
    dfs(cur_s, false);
  }
  for (int i = 0; i < q; ++i) {
    cout << q_result[i] << "\n";
  }
}