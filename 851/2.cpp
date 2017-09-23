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

long long x[3], y[3];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);
  
  for (int i = 0; i < 3; ++i) {
    cin >> x[i] >> y[i];
  }

  if ((x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]) == (x[2] - x[1]) * (x[2] - x[1]) + (y[2] - y[1]) * (y[2] - y[1])) {
    if ((y[1] - y[0]) * (x[2] - x[1]) != (y[2] - y[1]) * (x[1] - x[0])) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
}