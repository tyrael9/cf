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
#include <string.h>

using namespace std;

int psum[100001];
int minpos[200001];
int maxpos[200001];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n;
  string s;
  cin >> n;
  cin >> s;

  for (int i = 1; i <= n; ++i) {
    if (s[i - 1] == '0') {
      psum[i] = psum[i - 1] - 1;
    } else {
      psum[i] = psum[i - 1] + 1;
    }
  }

  for (int i = 1; i <= n; ++i) {
    minpos[psum[i] + 100000] = ((minpos[psum[i] + 100000] != 0) ? min(minpos[psum[i] + 100000], i) : i);
    maxpos[psum[i] + 100000] = max(maxpos[psum[i] + 100000], i);
  }
  minpos[100000] = 0;
  int result = 0;
  result = max(result, maxpos[100000] - minpos[100000]);
  for (int i = 0; i < 200001; ++i) {
    if (minpos[i] != 0 && maxpos[i] != 0) {
      result = max(result, maxpos[i] - minpos[i]);
    }
  }
  cout << result << endl;
}