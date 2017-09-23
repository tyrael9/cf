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

int n;
int a[100];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < 2 * n; ++i) {
    cin >> a[i];
  }
  sort(a, a + 2 * n);
  long long result = 0;
  long long best = -1;
  long long best2 = -1;
  for (int i = 1; i < 2 * n; i += 2) {
    result += a[i] - a[i - 1];
  }
  for (int i = 1; i < 2 * n; i += 2) {
    best = (best < 0 ? result - (a[i] - a[i - 1]) : min(best, result - (a[i] - a[i - 1])));
  }
  for (int i = 0; i < 2 * n; i += 2) {
    for (int j = i + 3; j < 2 * n; j += 2) {
      long long val = 0;
      for (int k = 1; k < i; k += 2) {
        val += a[k] - a[k - 1];
      }
      for (int k = i + 2; k < j; k += 2) {
        val += a[k] - a[k - 1];
      }
      for (int k = j + 2; k < 2 * n; k += 2) {
        val += a[k] - a[k - 1];
      }
      best2 = (best2 < 0 ? val : min(best2, val));
    }
  }
  cout << (best2 < 0 ? best : min(best, best2)) << endl;
}