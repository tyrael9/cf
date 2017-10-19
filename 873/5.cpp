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

pair<int, int> a[3000];
int diff[3000];
int res[3000];
int rngmaxi[3000][3000];
int n;

bool cmp_pair(const pair<int, int>& p1, const pair<int, int>& p2) {
  return p1.first < p2.first;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    a[i].first = t;
    a[i].second = i;
  }
  sort(a, a + n, cmp_pair);
  diff[0] = a[0].first;
  for (int i = 1; i < n; ++i) {
    diff[i] = a[i].first - a[i - 1].first;
  }
  for (int i = 0; i < n; ++i) {
    rngmaxi[i][i] = i;
    for (int j = i + 1; j < n; ++j) {
      rngmaxi[i][j] = (diff[rngmaxi[i][j - 1]] > diff[j] ? rngmaxi[i][j - 1] : j);
    }
  }
  int maxi = -1, maxj = -1, maxk = -1;
  for (int i = 0; i < n; ++i) {
    if ((maxi >= 0) && (diff[i] < diff[maxi])) {
      continue;
    }
    for (int j = 0; j < i; ++j) {
      if ((maxi >= 0) && (diff[i] == diff[maxi]) &&
          (maxj >= 0) && (diff[j] < diff[maxj])) {
        continue;
      }
      int cnt3 = n - i;
      int cnt2 = i - j;
      if ((cnt2 > 2 * cnt3) || (cnt3 > 2 * cnt2)) {
        continue;
      }
      int k_r = j - (max(cnt2, cnt3) + 1) / 2;
      int k_l = max(0, j - min(cnt2, cnt3) * 2);
      if ((k_r < 0) || (k_l > k_r)) {
        continue;
      }
      int k = rngmaxi[k_l][k_r];
      if ((maxi >= 0) && (diff[i] == diff[maxi]) &&
          (maxj >= 0) && (diff[j] == diff[maxj]) &&
          (maxk >= 0) && (diff[k] < diff[maxk])) {
        continue;
      }
      maxi = i;
      maxj = j;
      maxk = k;
      // cout << i << " " << j << " " << k << " " << endl;
    }
  }
  if (maxi == -1) {
    cout << "-1\n";
  } else {
    for (int i = 0; i < maxk; ++i) {
      res[a[i].second] = -1;
    }
    for (int i = maxk; i < maxj; ++i) {
      res[a[i].second] = 3;
    }
    for (int i = maxj; i < maxi; ++i) {
      res[a[i].second] = 2;
    }
    for (int i = maxi; i < n; ++i) {
      res[a[i].second] = 1;
    }
    for (int i = 0; i < n - 1; ++i) {
      cout << res[i] << " ";
    }
    cout << res[n - 1] << "\n";
  }
}