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

int numftos = 0;
int numstof = 0;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 1; i < n; ++i) {
    if (s[i] == 'S' && s[i - 1] == 'F') {
      ++numftos;
    } else if (s[i] == 'F' && s[i - 1] == 'S') {
      ++numstof;
    }
  }
  cout << (numstof > numftos ? "YES" : "NO") << "\n";
}