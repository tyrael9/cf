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

int a[100000];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  map<int, int> m;
  for (int i = 0; i < n; ++i) {
    ++m[a[i]];
  }
  long long result = 0;
  for (int i = 0; i < n; ++i) {
    if (m.find(x ^ a[i]) != m.end()) {
      if ((x ^ a[i]) == a[i]) {
        result += (m[x ^ a[i]] - 1);
      } else {
        result += m[x ^ a[i]];
      }
    }
  }
  cout << (result >> 1) << endl;
}