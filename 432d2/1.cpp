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
  
  long n, k, t;
  cin >> n >> k >> t;

  long num_stand = 0;
  if (t >= 1 && t <= k) {
    num_stand = t;
  } else if (t > k && t <= n) {
    num_stand = k;
  } else if (t > n && t <= n + k) {
    num_stand = k - (t - n);
  }

  cout << num_stand << endl;
}