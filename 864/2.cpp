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

int n;
string s;
set<char> cs;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n;
  cin >> s;

  unsigned long maxlen = 0;
  for (int i = 0; i < n; ++i) {
    if ((s[i] >= 'A') && (s[i] <= 'Z')) {
      maxlen = (maxlen > cs.size() ? maxlen : cs.size());
      cs.clear();
    } else {
      cs.insert(s[i]);
    }
  }
  maxlen = (maxlen > cs.size() ? maxlen : cs.size());
  cout << maxlen << endl;
}