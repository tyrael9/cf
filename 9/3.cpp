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

long to_radix_2(long n) {
  long res = 0;
  long base = 1;
  while (n > 0) {
    res += (n % 2) * base;
    n = n / 2;
    base *= 10;
  }
  return res;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  long n;
  cin >> n;
  long l = 1, r = (1 << 9);
  while (l < r) {
    long mid = (l + r + 1) / 2;
    if (to_radix_2(mid) > n) {
      r = mid - 1;
    } else {
      l = mid;
    }
  }
  cout << l << endl;
}