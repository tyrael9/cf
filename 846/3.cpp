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

int n;
long long a[5000];
long long presum[5001];
long long sufsum[5001];
int presum_maxi[5001], sufsum_mini[5001];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  presum[0] = 0;
  presum_maxi[0] = 0;
  for (int i = 1; i <= n; ++i) {
    presum[i] = presum[i - 1] + a[i - 1];
    presum_maxi[i] = presum_maxi[i - 1];
    if (presum[i] > presum[presum_maxi[i]]) {
      presum_maxi[i] = i;
    }
  }

  sufsum[n] = 0;
  sufsum_mini[n] = n;
  for (int i = n - 1; i >= 0; --i) {
    sufsum[i] = sufsum[i + 1] + a[i];
    sufsum_mini[i] = sufsum_mini[i + 1];
    if (sufsum[i] < sufsum[sufsum_mini[i]]) {
      sufsum_mini[i] = i;
    }
  }

  long long maxres = -1;
  int d0, d1, d2;
  for (int i = 0; i <= n; ++i) {
    long long res = 2 * presum[presum_maxi[i]] - presum[i] + sufsum[i] - 2 * sufsum[sufsum_mini[i]];
    // cout << presum_maxi[i] << " " << i << " " << sufsum_mini[i] << " " << res << endl;
    if (res > maxres) {
      d0 = presum_maxi[i];
      d1 = i;
      d2 = sufsum_mini[i];
      maxres = res;
    }
  }
  cout << d0 << " " << d1 << " " << d2 << endl;
}