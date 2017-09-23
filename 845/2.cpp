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

vector<int> a(6);

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);
  
  string s;
  cin >> s;
  for (int i = 0; i < 6; ++i) {
    a[i] = s[i] - '0';
  }
  int sum_before = a[0] + a[1] + a[2];
  int sum_after = a[3] + a[4] + a[5];
  int result = 0;
  if (sum_after > sum_before) {
    a[0] = 9 - a[0];
    a[1] = 9 - a[1];
    a[2] = 9 - a[2];
    sort(a.begin(), a.end());
    sum_after -= sum_before;
    for (int i = 5; i >= 0; --i) {
      result++;
      sum_after -= a[i];
      if (sum_after <= 0) {
        break;
      }
    }
  } else if (sum_after < sum_before) {
    a[3] = 9 - a[3];
    a[4] = 9 - a[4];
    a[5] = 9 - a[5];
    sort(a.begin(), a.end());
    sum_before -= sum_after;
    for (int i = 5; i >= 0; --i) {
      result++;
      sum_before -= a[i];
      if (sum_before <= 0) {
        break;
      }
    }
  }
  cout << result << endl;
}