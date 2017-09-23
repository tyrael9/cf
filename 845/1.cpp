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
  
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < 2 * n; ++i) {
    int x;
    cin >> x;
    a.push_back(x);
  }

  sort(a.begin(), a.end());
  cout << (a[n] > a[n - 1] ? "YES" : "NO") << endl;
  return 0;
}