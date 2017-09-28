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

struct tv {
  int l;
  int r;
  int id;
};

int n;
vector<tv> tvs(200000);

bool cmp_tv(const tv& t1, const tv& t2) {
  if (t1.l != t2.l) {
    return t1.l < t2.l;
  }
  return t1.r > t2.r;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> tvs[i].l >> tvs[i].r;
    tvs[i].id = i + 1;
  }

  sort(tvs.begin(), tvs.begin() + n, cmp_tv);
  for (int i = 1; i < n; ++i) {
    if (tvs[i].r <= tvs[i - 1].r) {
      cout << tvs[i].id << endl;
      return 0;
    }
  }
  for (int i = 1; i < n - 1; ++i) {
    if (tvs[i + 1].l <= tvs[i - 1].r + 1) {
      cout << tvs[i].id << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}