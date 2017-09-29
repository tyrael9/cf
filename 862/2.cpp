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

long long numr;

int n;
vector<int> edges[100000];
bool visited[100000];
vector<int> lid;

void dfs(int cur, bool is_l) {
  if (visited[cur]) {
    return;
  }
  if(is_l) {
    lid.push_back(cur);
  } else {
    ++numr;
  }
  visited[cur] = true;
  for (const int next : edges[cur]) {
    dfs(next, !is_l);
  }
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }

  dfs(0, false);
  
  long long result = 0;
  for (const int l : lid) {
    result += numr - edges[l].size();
  }
  cout << result << endl;
}