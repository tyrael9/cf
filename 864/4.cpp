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

using namespace std;

int cnt[200001];
bool have[200001];
int a[200000];
int n;

int get_next_not_found(int cur) {
  for (int i = cur + 1; i <= n; ++i) {
    if (cnt[i] == 0) {
      return i;
    }
  }
  return -1;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ++cnt[a[i]];
  }

  int cand = get_next_not_found(0);
  int num_replaced = 0;
  for (int i = 0; i < n && (cand != -1); ++i) {
    if (cnt[a[i]] == 1) {
      have[a[i]] = true;
      continue;
    } else {
      if ((have[a[i]]) || (cand < a[i])) {
        --cnt[a[i]];
        ++num_replaced;
        a[i] = cand;
        cand = get_next_not_found(cand);
      }
      have[a[i]] = true;
    }
  }

  cout << num_replaced << endl;
  for (int i = 0; i < n; ++i) {
    cout << a[i];
    if (i != n - 1) {
      cout << " ";
    }
  }
  cout << "\n";
}