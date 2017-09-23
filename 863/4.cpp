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

struct qry {
  int t;
  int l;
  int r;
};

int b[100];
int a[200000];
int n, q, m;
vector<qry> querys;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n >> q >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < q; ++i) {
    int t, l, r;
    cin >> t >> l >> r;
    --l;
    --r;
    querys.push_back({t, l, r});
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    --b[i];
  }
  for (int i = querys.size() - 1; i >= 0; --i) {
    int t = querys[i].t;
    int l = querys[i].l;
    int r = querys[i].r;
    if (t == 1) {
      for (int j = 0; j < m; ++j) {
        if (b[j] == l) {
          b[j] = r;
        } else if ((b[j] > l) && (b[j] <= r)) {
          --b[j];
        }
      }
    } else {
      for (int j = 0; j < m; ++j) {
        if ((b[j] >= l && b[j] <= r)) {
          b[j] = r - (b[j] - l);
        }
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    cout << a[b[i]];
    if (i != m) {
      cout << " ";
    }
  }
  cout << "\n";
}