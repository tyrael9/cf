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

struct episode {
  int x;
  int y;
  int z;
};

int n, m;
vector<int> e[200000];
int num_visited_e[200000];
int state[200000];
bool single_degree_added[200000];
vector<vector<int>> pending_stk;
vector<episode> result;

#define WHITE 0
#define GRAY 1
#define BLACK 2

void process_node(int cur, vector<int>& path) {
  // cout << "Processing " << cur << endl;
  vector<int>& pending = pending_stk.back();
  if (single_degree_added[cur]) {
    return;
  }
  while (pending.size() >= 2) {
    int p1 = pending.back();
    pending.pop_back();
    int p2 = pending.back();
    pending.pop_back();
    result.push_back({p1, cur, p2});
  }
  if (!pending.empty()) {
    if (!path.empty()) {
      result.push_back({pending.back(), cur, path.back()});
    }
    pending.pop_back();
  } else {
    if (!path.empty()) {
      vector<int>& prev_pending = pending_stk.end()[-2];
      if ((e[path.back()].size() > num_visited_e[path.back()]) || (!prev_pending.empty())) {
        // cout << "Pending " << cur << endl;
        prev_pending.push_back(cur);
      } else {
        if (path.size() >= 2) {
          result.push_back({cur, path.back(), path.end()[-2]});
          single_degree_added[path.back()] = true;
        }
      }
    }
  }
}

void dfs(int cur, vector<int>& path) {
  // cout << cur << endl;
  // for (const int p : path) {
  //   cout << p << " ";
  // }
  // cout << endl;
  state[cur] = GRAY;
  int parent = (path.empty() ? -1 : path.back());
  pending_stk.push_back({});
  path.push_back(cur);
  for (const int next : e[cur]) {
    if (state[next] == GRAY) {
      // Back Edge
      if (next != parent) {
        num_visited_e[cur]++;
        num_visited_e[next]++;
        pending_stk.push_back({});
        process_node(next, path);
        pending_stk.pop_back();
      }
    } else if (state[next] == WHITE) {
      // Tree Edge
      num_visited_e[cur]++;
      num_visited_e[next]++;
      dfs(next, path);
    }
  }
  path.pop_back();
  process_node(cur, path);
  pending_stk.pop_back();
  state[cur] = BLACK;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  vector<int> path;
  for (int i = 0; i < n; ++i) {
    if (state[i] == WHITE) {
      dfs(i, path);
    }
  }

  cout << result.size() << "\n";
  for (const auto& epi : result) {
    cout << epi.x + 1 << " " << epi.y + 1 << " " << epi.z + 1 << "\n";
  }
}