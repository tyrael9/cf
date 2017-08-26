#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <stdio.h>

using namespace std;

struct envlope {
  long w;
  long h;
  int index;
};

bool cmp_e(const envlope& e1, const envlope& e2) {
  if (e1.w == e2.w) {
    return e1.h > e2.h;
  }
  return e1.w < e2.w;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  long cw, ch;
  cin >> cw >> ch;
  vector<envlope> e;
  for (int i = 0; i < n; ++i) {
    long w, h;
    cin >> w >> h;
    if ((w <= cw) || (h <= ch)) {
      continue;
    } else {
      e.push_back({w, h, i + 1});
    }
  }
  if (e.empty()) {
    cout << 0 << endl;
    return 0;
  }
  sort(e.begin(), e.end(), cmp_e);
  vector<long> c(e.size() + 1);
  vector<int> c_ind(e.size() + 1);
  vector<int> dp(e.size());
  int sz = 1;
  c[1] = e[0].h;
  c_ind[0] = -1;
  c_ind[1] = 0;
  dp[0] = -1;
  for (int i = 1; i < e.size(); ++i) {
    if (e[i].h < c[1]) {
      c[1] = e[i].h;
      c_ind[1] = i;
      dp[i] = -1;
    } else if (e[i].h > c[sz]) {
      c[sz + 1] = e[i].h;
      c_ind[sz + 1] = i;
      dp[i] = c_ind[sz];
      ++sz;
    } else {
      int k = std::lower_bound(c.begin() + 1, c.begin() + sz + 1, e[i].h) - c.begin();
      c[k] = e[i].h;
      c_ind[k] = i;
      dp[i] = c_ind[k - 1];
    }
  }
  int k = c_ind[sz];
  vector<int> result;
  while (k != -1) {
    result.push_back(e[k].index);
    k = dp[k];
  }
  std::reverse(result.begin(), result.end());
  cout << result.size() << endl;
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i];
    if (i < result.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;
  return 0;
}