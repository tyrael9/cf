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

int n, m;
pair<int, int> kf[100];

bool isgood(int ff) {
  for (int i = 0; i < m; ++i) {
    if (((kf[i].first - 1) < (kf[i].second - 1) * ff) || (kf[i].first - 1) >= (kf[i].second) * ff) {
      return false;
    }
  }
  return true;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> kf[i].first >> kf[i].second;
  }

  if (m == 0) {
    if (n == 1) {
      cout << "1" << endl;
    } else {
      cout << "-1" << endl;
    }
    return 0;
  }

  int nf = -1;
  for (int ff = 1; ff < 200; ++ff) {
    if (isgood(ff)) {
      if (nf == -1) {
        nf = ((n - 1) / ff) + 1;
      } else {
        int tmpnf = ((n - 1) / ff) + 1;
        if (tmpnf != nf) {
          cout << "-1" << endl;
          return 0;
        }
      }
    }
  }
  cout << nf << endl;
}