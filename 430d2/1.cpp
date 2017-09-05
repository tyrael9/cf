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
  
  long long l, r, x, y, k;

  cin >> l >> r >> x >> y >> k;
  while ((l <= r) || (x <= y)) {
    if (l > x * k) {
      if (x == y) {
        break;
      }
      ++x;
    } else if (l < x * k) {
      if (l == r) {
        break;
      }
      ++l;
    } else {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}