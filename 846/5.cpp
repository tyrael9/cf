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

vector<int> child[100001];
long long val[100001];
long long k[100001];
int n;

const long long lm = -2 * 10e17;

bool dfs(int cur) {
  for (const int nxt : child[cur]) {
    if (!dfs(nxt)) {
      return false;
    }
    if (val[nxt] >= 0) {
      val[cur] += val[nxt];
    } else {
      if (lm / k[nxt] > val[nxt]) {
        return false;
      }
      val[cur] += k[nxt] * val[nxt];
    }
    if (val[cur] < lm) {
      return false;
    }
  }
  return true;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
  }
  for (int i = 1; i <= n; ++i) {
    long long a;
    cin >> a;
    val[i] -= a;
  }
  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x >> k[i];
    child[x].push_back(i);
  }
  cout << ((dfs(1) && val[1] >= 0) ? "YES" : "NO") << "\n";
}