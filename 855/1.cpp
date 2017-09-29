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

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n;
  set<string> ss;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (ss.find(s) == ss.end()) {
      cout << "NO\n";
      ss.insert(s);
    } else {
      cout << "YES\n";
    }
  }
}