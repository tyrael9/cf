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
  long m = s.length();
  long n = 2 * m + 1;
  vector<long> p(n);
  p[0] = 0;
  long k = 0;
  for (long i = 1; i < n; ++i) {
    while (k > 0 && !(((k != m) && (i != m)) ? ((k < m ? s[k] : s[m + m - k]) == (i < m ? s[i] : s[m + m - i])) : (k == i))) {
      k = p[k - 1];
    }
    if ((((k != m) && (i != m)) ? ((k < m ? s[k] : s[m + m - k]) == (i < m ? s[i] : s[m + m - i])) : (k == i))) {
      k += 1;
    }
    p[i] = k;
  }
  vector<bool> is_p_prefix(m, false);
  vector<long> p_degree(m, 0);
  long x = p[m << 1] - 1;
  while (x >= 0) {
    is_p_prefix[x] = true;
    x = p[x] - 1;
  }
  p_degree[0] = 1;
  long long sum = 1;
  for (long i = 1; i < m; ++i) {
    if (is_p_prefix[i]) {
      long ih = ((i + 1) >> 1) - 1;
      if (is_p_prefix[ih]) {
        p_degree[i] = p_degree[ih] + 1;
      } else {
        p_degree[i] = 1;
      }
    } else {
      p_degree[i] = 0;
    }
    sum += p_degree[i];
  }
  cout << sum << endl;
}