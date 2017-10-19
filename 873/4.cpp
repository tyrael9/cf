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

int a[100000];

int get_max_calls(int n) {
  int total = 0;
  while (n != 1) {
    if ((n & 1) != 0) {
      total += n - 1;
      n = (n - 1) / 2 + 1;
    } else {
      total += n;
      n /= 2;
    }
  }
  return total + 1;
}

bool solve(int l, int r, int k) {
  --k;
  if (r == l + 1) {
    return k == 0;
  }
  if (k == 0) {
    return true;
  }
  if ((k & 1) != 0) {
    return false;
  }
  int mid = (l + r) / 2;
  int lmax = get_max_calls(mid - l);
  int rmax = get_max_calls(r - mid);
  if (lmax + rmax < k) {
    return false;
  }
  int tmp = a[mid - 1];
  a[mid - 1] = a[mid];
  a[mid] = tmp;
  int ln = lmax;
  if (ln > k) {
    ln = k - 1;
  }
  return solve(l, mid, ln) && solve(mid, r, k - ln);
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    a[i] = i + 1;
  }

  bool ok = solve(0, n, k);
  if (!ok) {
    cout << "-1\n";
  } else {
    for (int i = 0; i < n - 1; ++i) {
      cout << a[i] << " ";
    }
    cout << a[n - 1] << "\n";
  }
}