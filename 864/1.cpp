#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <list>
#include <stack>
#include <bitset>
#include <cmath>
#include <climits>
#include <cassert>

using namespace std;

map<int, int> m;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++m[x];
  }
  if (m.size() == 2) {
    auto it = m.begin();
    int n1 = it->first;
    int v1 = it->second;
    ++it;
    int n2 = it->first;
    int v2 = it->second;
    if (v1 == v2) {
      cout << "YES" << "\n";
      cout << n1 << " " << n2 << "\n";
      return 0;
    }
  }
  cout << "NO" << "\n";
}