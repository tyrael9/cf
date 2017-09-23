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

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);
  
  int r, d;
  int n;
  cin >> r >> d;
  cin >> n;
  int good = 0;
  for (int i = 0; i < n; ++i) {
    int x, y, ri;
    cin >> x >> y >> ri;
    if (x * x + y * y < (ri + r - d) * (ri + r - d)) {
      continue;
    }
    if (x * x + y * y > (r - ri) * (r - ri)) {
      continue;
    }
    ++good;
  }
  cout << good << endl;
}