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

int a[100];
int zero_before[100];
int one_after[100];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i == 0) {
      zero_before[i] = 0;
    } else {
      zero_before[i] = zero_before[i - 1];
    }
    if (a[i] == 0) {
      ++zero_before[i];
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (i == n - 1) {
      one_after[i] = 0;
    } else {
      one_after[i] = one_after[i + 1];
    }
    if (a[i] == 1) {
      ++one_after[i];
    }
  }
  int maxleave = 0;
  for (int i = 0; i < n; ++i) {
    maxleave = max(maxleave, zero_before[i] + one_after[i]);
  }
  cout << maxleave << endl;
}