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
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  long n, k;
  cin >> n >> k;
  map<long, long> lm;
  map<long, long, std::greater<long>> gm;
  vector<long> h(n);
  for (long i = 0; i < n; ++i) {
    cin >> h[i];
  }
  long l = 0, r = 0;
  long maxlen = 0;
  vector<pair<int, int>> maxrecord;
  lm[h[r]] += 1;
  gm[h[r]] += 1;
  while (r < n) {
    if (abs(lm.begin()->first - gm.begin()->first) <= k) {
      long len = r - l + 1;
      if (len > maxlen) {
        maxlen = len;
        maxrecord.clear();
      }
      if (len == maxlen) {
        maxrecord.push_back({l, r});
      }
      ++r;
      if (r < n) {
        lm[h[r]] += 1;
        gm[h[r]] += 1;
      }
    } else {
      lm[h[l]] -= 1;
      if (lm[h[l]] == 0) {
        lm.erase(h[l]);
      }
      gm[h[l]] -= 1;
      if (gm[h[l]] == 0) {
        gm.erase(h[l]);
      }
      ++l;
    }
  }
  cout << maxrecord[0].second - maxrecord[0].first + 1 << " " << maxrecord.size() << endl;
  for (int i = 0; i < maxrecord.size(); ++i) {
    cout << maxrecord[i].first + 1 << " " << maxrecord[i].second + 1 << endl;
  }
}