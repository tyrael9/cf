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

bool cmp_pair(const pair<int, int> &res1, const pair<int, int> &res2) {
  if (res1.first == res2.first) {
    return res1.second < res2.second;
  }
  return res1.first < res2.first;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);
  
  int r1 = -1, r2 = -1;
  long n;
  cin >> n;
  vector<pair<int, int>> res(n);
  for (long i = 0; i < n; ++i) {
    long l, r;
    cin >> l >> r;
    res[i].first = l;
    res[i].second = r;
  }
  sort(res.begin(), res.end());
  for (const auto& p : res) {
    if (p.first > r1) {
      r1 = p.second;
    } else if (p.first > r2) {
      r2 = p.second;
    } else {
      cout << "NO" << "\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}