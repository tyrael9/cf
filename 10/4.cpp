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

long a[500];
long b[500];

pair<int, int> dp[500];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n, m;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  int l = max(m, n);
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < i; ++j) {

    }
  }
}