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

int n, k, x;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n >> k >> x;
  long long sum = 0;
  for (int i = 0; i < n - k; ++i) {
    int a;
    cin >> a;
    sum += a;
  }
  for (int i = 0; i < k; ++i) {
    int a;
    cin >> a;
  }
  sum += k * x;
  cout << sum << endl;
}