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
long long q, p;
long long noise[250][250] = {0};
string qtrs[250];
bool visited[250][250] = {false};

pair<int, int> ds[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct qtr {
  int i;
  int j;
  long long nlvl;
};

void bfs(int i, int j) {
  queue<qtr> worklist;
  for (int x = -25; x <= 25; ++x) {
    for (int y = -25; y <= 25; ++y) {
      if ((i + x >= 0) && (i + x < n) && (j + y >= 0) && (j + y < m)) {
        visited[i + x][j + y] = false;
      }
    }
  }
  worklist.push({i, j, q * (qtrs[i][j] - 'A' + 1)});
  while (!worklist.empty()) {
    qtr cur_qtr = worklist.front();
    worklist.pop();
    if (visited[cur_qtr.i][cur_qtr.j]) {
      continue;
    }
    visited[cur_qtr.i][cur_qtr.j] = true;

    noise[cur_qtr.i][cur_qtr.j] += cur_qtr.nlvl;
    if (cur_qtr.nlvl >= 2) {
      for (const auto &d : ds) {
        int next_i = cur_qtr.i + d.first;
        int next_j = cur_qtr.j + d.second;
        if ((next_i >= 0) && (next_i < n) && (next_j >= 0) && (next_j < m) &&
            (!visited[next_i][next_j]) && (qtrs[next_i][next_j] != '*')) {
          worklist.push({next_i, next_j, cur_qtr.nlvl / 2});
        }
      }
    }
  }
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n >> m >> q >> p;
  for (int i = 0; i < n; ++i) {
    cin >> qtrs[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if ((qtrs[i][j] >= 'A') && (qtrs[i][j] <= 'Z')) {
        bfs(i, j);
      }
    }
  }

  int result = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      // cout << noise[i][j] << " ";
      if (noise[i][j] > p) {
        ++result;
      }
    }
    // cout << endl;
  }
  cout << result << endl;
}