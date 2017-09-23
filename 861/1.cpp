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

  long long n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << n << endl;
    return 0;
  }
  long long n5 = 0, n2 = 0, orgn = n;
  while (n % 2 == 0) {
    n = n / 2;
    ++n2;
  }
  while (n % 5 == 0) {
    n = n / 5;
    ++n5;
  }
  while ((n2 != n5) && min(n2, n5) < k) {
    if (n2 > n5) {
      orgn *= 5;
      ++n5;
    } else {
      orgn *= 2;
      ++n2;
    }
  }
  while (min(n2, n5) < k) {
    orgn *= 10;
    ++n5;
    ++n2;
  }
  cout << orgn << endl;
}