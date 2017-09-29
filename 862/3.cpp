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

unsigned long n, x;
set<unsigned long> result;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n >> x;
  unsigned long cur = 0;
  for (unsigned long i = 1; i <= n; ++i) {
    cur ^= i;
    result.insert(i);
  }

  unsigned long rem = x ^ cur;
  if (rem != 0) {
    if (result.find(rem) != result.end()) {
      result.erase(rem);
      result.insert(0);
    } else {
      bool found = false;
      for (unsigned long i = 1; i <= n; ++i) {
        if (result.find(rem ^ i) == result.end()) {
          result.insert(rem ^ i);
          result.erase(i);
          found = true;
          break;
        }
      }
      if (!found) {
        for (unsigned long i = 2; i <= n; ++i) {
          if (i != (rem ^ 1)) {
            result.erase(i);
            result.erase(1);
            result.insert(i | (1 << 19));
            result.insert((rem ^ 1) | (1 << 19));
            found = true;
            break;
          }
        }
      }
      if (!found) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }

  int i = 0;
  cout << "YES" << endl;
  for (const int res : result) {
    ++i;
    cout << res;
    if (i != result.size()) {
      cout << " ";
    }
  }
  cout << "\n";
}