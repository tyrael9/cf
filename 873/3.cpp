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

int mat[100][100];
int n, m, k;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }

  int total = 0;
  int numrep = 0;
  for (int j = 0; j < m; ++j) {
    int num = 0;
    for (int i = 0; i < k; ++i) {
      num += mat[i][j];
    }
    int maxnum = num;
    int maxi = 0;
    for (int i = 0; i < n; ++i) {
      if (num > maxnum) {
        maxnum = num;
        maxi = i;
      }
      num -= mat[i][j];
      if (i + k < n) {
        num += mat[i + k][j];
      }
    }
    total += maxnum;
    for (int i = maxi - 1; i >= 0; --i) {
      numrep += mat[i][j];
    }
  }

  cout << total << " " << numrep << "\n";
}