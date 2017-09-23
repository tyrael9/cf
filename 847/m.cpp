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
int t[100];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  int delta = -1;
  for (int i = 1; i < n; ++i) {
    int cur_delta = t[i] - t[i - 1];
    if (i == 1) {
      delta = cur_delta;
    } else {
      if (delta != cur_delta) {
        cout << t[n - 1] << endl;
        return 0;
      }
    }
  }
  cout << t[n - 1] + delta << endl;
  return 0;
}