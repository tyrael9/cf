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

  int cur_speed = 0;
  int nt_count = 0;
  stack<int> sp_limits;

  int n;
  cin >> n;
  int num_bad = 0;
  for (int i = 0; i < n; ++i) {
    int type;
    cin >> type;
    if (type == 1) {
      cin >> cur_speed;
      while ((!sp_limits.empty()) && (cur_speed > sp_limits.top())) {
        num_bad++;
        sp_limits.pop();
      }
    } else if (type == 2) {
      if (nt_count > 0) {
        num_bad += nt_count;
      }
      nt_count = 0;
    } else if (type == 3) {
      int l;
      cin >> l;
      if (cur_speed > l) {
        num_bad++;
      } else {
        sp_limits.push(l);
      }
    } else if (type == 4) {
      nt_count = 0;
    } else if (type == 5) {
      while(!sp_limits.empty()) {
        sp_limits.pop();
      }
    } else if (type == 6) {
      ++nt_count;
    }
  }
  cout << num_bad << endl;
}