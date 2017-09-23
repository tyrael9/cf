#include <iostream>
#include <stdlib.h>
#include <set>

using namespace std;

int main(int argc, char** argv) {
  long long a, b;
  long long l, r;
  cin >> a >> b;
  cin >> l >> r;
  l = l - 1;
  r = r - 1;
  r = r - (l / (2 * (a + b))) * (2 * (a + b));
  l = l % (2 * (a + b));
  char rep_1, rep_2;
  if (l < a) {
    rep_1 = 'a' + a - 1;
  } else {
    rep_1 = 'a' + min(b, a - 1LL);
  }
  if (l < 2 * a + b) {
    rep_2 = 'a' + a + max(a - b - 1, 0LL);
  } else {
    rep_2 = 'a' + a + min(0LL, max(a - b - 1, 0LL));
  }
  set<char> result_set;
  for (int k = 0; k < 4 * (a + b); ++k) {
    int i = k % (2 * (a + b));
    char cur;
    if (i < a) {
      cur = 'a' + i;
    } else if ((i >= a) && (i < a + b)) {
      cur = rep_1;
    } else if ((i >= a + b) && (i < 2 * a + b - max(1LL, a - b))) {
      cur = 'a' + i - (a + b);
    } else if ((i >= 2 * a + b - max(1LL, a - b)) && (i < 2 * a + b)) {
      cur = 'a' + a + i - (2 * a + b - max(1LL, a - b));
    } else {
      cur = rep_2;
    }
    if ((k >= l) && (k <= r)) {
      result_set.insert(cur);
    }
  }

  cout << result_set.size() << endl;
}