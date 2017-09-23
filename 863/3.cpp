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

long long k;
int a, b;

int A[3][3];
int B[3][3];

int nxt[9];
pair<long long, long long> pts[9];

bool better(int ac, int bc) {
  if (ac == 0) {
    return bc == 2;
  } else if (ac == 1) {
    return bc == 0;
  } else {
    return bc == 1;
  }
}

pair<long long, long long> getpts(int ac, int bc) {
  if (ac == bc) {
    return {0, 0};
  } else {
    if (better(ac, bc)) {
      return {1, 0};
    } else {
      return {0, 1};
    }
  }
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> k >> a >> b;
  --a;
  --b;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) { 
      cin >> A[i][j];
      --A[i][j];
    }
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) { 
      cin >> B[i][j];
      --B[i][j];
    }
  }

  for (int i = 0; i < 9; ++i) {
    int prevA = i / 3;
    int prevB = i % 3;
    int nextA = A[prevA][prevB];
    int nextB = B[prevA][prevB];
    nxt[i] = nextA * 3 + nextB;
    pts[i] = getpts(prevA, prevB);
  }
  int start = 3 * a + b;
  int cur = start;
  vector<int> path;
  bool visited[9] = { false };
  while (!visited[cur]) {
    visited[cur] = true;
    path.push_back(cur);
    cur = nxt[cur];
  }

  int cycle_start = cur;
  bool cycle_started = false;
  long long cycle_len = 0;
  pair<long long, long long> cycle_pts = {0, 0};
  for (int i = 0; i < path.size(); ++i) {
    if (cycle_start == path[i]) {
      cycle_started = true;
    }
    if (cycle_started) {
      ++cycle_len;
      cycle_pts.first += pts[path[i]].first;
      cycle_pts.second += pts[path[i]].second;
    }
  }
  cur = start;
  pair<long long, long long> result_pts = {0, 0};
  while ((cur != cycle_start) && (k > 0)) {
    --k;
    result_pts.first += pts[cur].first;
    result_pts.second += pts[cur].second;
    cur = nxt[cur];
  }
  long long num_cycles = k / cycle_len;
  long long rem = k % cycle_len;
  result_pts.first += num_cycles * cycle_pts.first;
  result_pts.second += num_cycles * cycle_pts.second;
  cur = cycle_start;
  for (int i = 0; i < rem; ++i) {
    result_pts.first += pts[cur].first;
    result_pts.second += pts[cur].second;
    cur = nxt[cur];
  }
  cout << result_pts.first << " " << result_pts.second << "\n";
}