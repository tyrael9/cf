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

bool has[102];
int n, x;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    int val;
    cin >> val;
    if (val <= 101) {
      has[val] = true;
    }
  }

  int result = 0;
  for (int i = 0; i < x; ++i) {
    if (!has[i]) {
      ++result;
    }
  }
  if (has[x]) {
    ++result;
  }
  cout << result << endl;
}