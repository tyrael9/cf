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
#include <stdio.h>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  string s;
  cin >> s;

  set<pair<int, int>> ss;
  int x = 0, y = 0;
  for (char c : s) {
    int orgx = x;
    int orgy = y;
    ss.insert({x, y});
    switch(c) {
      case 'L': --x; break;
      case 'R': ++x; break;
      case 'U': ++y; break;
      case 'D': --y; break;
    }
    if (ss.find({x, y}) != ss.end()) {
      cout << "BUG" << endl;
      return 0;
    }
    ss.insert({orgx - 1, orgy});
    ss.insert({orgx + 1, orgy});
    ss.insert({orgx, orgy - 1});
    ss.insert({orgx, orgy + 1});
  }
  cout << "OK" << endl;
  return 0;
}