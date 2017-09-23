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

const long long mod_base = 1000000007;
const int N = 100000;

int nxt[2 * N + 1] = {0};
vector<int> prevs[2 * N + 1];
int visited[2 * N + 1] = {0};
int cycle_visited[2 * N + 1] = {0};

long long dfs_prev_len(int i) {
  if (visited[i]) {
    return 0;
  }
  visited[i] = 1;
  long long result = 1;
  for (const auto p : prevs[i]) {
    result += dfs_prev_len(p);
  }
  return result;
}

int get_cycle_node(int i) {
  if (cycle_visited[i]) {
    return i;
  }
  cycle_visited[i] = 1;
  return get_cycle_node(nxt[i]);
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int c, c_next;
    cin >> c >> c_next;
    nxt[c] = c_next;
    prevs[c_next].push_back(c);
  }

  long long result = 1;
  for (int i = 1; i <= 2 * n; ++i) {
    if (nxt[i] == 0 && !prevs[i].empty()) {
      result = (result * (dfs_prev_len(i) % mod_base)) % mod_base;
    }
  }
  for (int i = 1; i <= 2 * n; ++i) {
    if (prevs[i].empty() && nxt[i] != 0 && visited[i] == 0) {
      int cycle_i = get_cycle_node(i);
      dfs_prev_len(cycle_i);
      if (nxt[cycle_i] != cycle_i) {
        result = (result * (2 % mod_base)) % mod_base;
      }
    }
  }
  for (int i = 1; i <= 2 * n; ++i) {
    if (!prevs[i].empty() && nxt[i] != 0 && visited[i] == 0) {
      dfs_prev_len(i);
      if (nxt[i] != i) {
        result = (result * (2 % mod_base)) % mod_base;
      }
    }
  }
  cout << result << endl;
}