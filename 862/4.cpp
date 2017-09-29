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

int main(int argc, char** argv) {
  // std::ios::sync_with_stdio(false);

  cin >> n;
  string s(n, '0');
  cout << "? " << s << endl;
  fflush(stdout);

  int init_count;
  cin >> init_count;
  init_count = n - init_count;
  int prev_count = n - init_count;

  int l = 0, r = n - 1;
  while (r - l >= 1) {
    // [l...r] must contain at least one 0 and 1
    int mid = (l + r) / 2;
    string tmp_s(n, '0');
    for (int i = l; i <= mid; ++i) {
      tmp_s[i] = '1';
    }
    cout << "? " << tmp_s << endl;
    fflush(stdout);

    int cur_count;
    cin >> cur_count;
    cur_count = n - cur_count;
    if (cur_count - init_count == mid - l + 1) {
      // [l, mid] is all one
      if (cur_count - prev_count == r - mid) {
        cout << "! " << mid + 2 << " " << mid + 1 << endl;
        fflush(stdout);
        return 0;
      }
      prev_count = prev_count - (mid - l + 1);
      l = mid + 1;
    } else if (init_count - cur_count == mid - l + 1) {
      // [l, mid] is all zero
      if (prev_count - cur_count == r - mid) {
        cout << "! " << mid + 1 << " " << mid + 2 << endl;
        fflush(stdout);
        return 0;
      }
      prev_count = prev_count + (mid - l + 1);
      l = mid + 1;
    } else {
      r = mid;
      prev_count = cur_count;
    }
  }
}