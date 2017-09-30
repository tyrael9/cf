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

long long a, b, f, k;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> a >> b >> f >> k;

  if (b < f) {
    cout << -1 << endl;
    return 0;
  }

  long long total = k * a;
  long long refuel = 0;
  long long pos = 0;
  long long rem = b % (2 * a);
  while (total > b) {
    long long next_pos = (pos + rem) % (2 * a);
    long long last_total = total;
    if (next_pos < f) {
      pos = a + a - f;
      total -= (b - next_pos - f);
    } else if ((next_pos >= f) && (next_pos < a + a - f)) {
      pos = f;
      total -= (b - (next_pos - f));
    } else {
      pos = a + a - f;
      total -= (b - (next_pos - (a + a - f)));
    }
    if (last_total == total) {
      cout << -1 << endl;
      return 0;
    }
    ++refuel;
  }

  cout << refuel << endl;
}