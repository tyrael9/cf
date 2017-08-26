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

  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  int i = 0, j = n - 1;
  bool ie = false, je = false;
  while (i < j) {
    if (c[i] == c[j]) {
      je = false;
      ie = false;
      ++i;
      --j;
    }
    while ((i < j) && (c[j] > c[i])) {
      je = true;
      ie = false;
      c[j] -= c[i];
      ++i;
    }
    while ((i < j) && (c[j] < c[i])) {
      je = false;
      ie = true;
      c[i] -= c[j];
      --j;
    }
  }
  if ((i == j) && (!je) && (!ie)) {
    ++i;
  }
  cout << (ie ? i + 1 : i) << " " << (je ? n - j : n - j - 1) << endl;
}