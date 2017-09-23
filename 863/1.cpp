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

long x;

bool is_palin(const string& s) {
  int l = 0, r = s.length() - 1;
  while (l < r) {
    if (s[l] != s[r]) {
      return false;
    }
    ++l;
    --r;
  }
  return true;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> x;
  string s = to_string(x);
  int n = s.length();
  if (is_palin(s)) {
    cout << "YES\n";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    s = "0" + s;
    if (is_palin(s)) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
}