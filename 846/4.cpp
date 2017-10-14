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

struct colinfo {
  deque<int> td;
  int h;
};

int n, m, k, q;
int mat[500][500];
colinfo cols[500];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n >> m >> k >> q;

  for (int i = 0; i < q; ++i) {
    int x, y, t;
    cin >> x >> y >> t;
    ++t;
    --x;
    --y;
    mat[x][y] = t;
  }

  int result = -1;
  for (int i = 0; i < n; ++i) {
    deque<int> row;
    int l = 0;
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == 0) {
        cols[j].td.clear();
        cols[j].h = 0;
      } else {
        while(!cols[j].td.empty() && mat[cols[j].td.back()][j] < mat[i][j]) {
          cols[j].td.pop_back();
        }
        cols[j].td.push_back(i);
        if (!cols[j].td.empty() && (i - cols[j].td.front() + 1) > k) {
          cols[j].td.pop_front();
        }
        cols[j].h = min(cols[j].h + 1, k);
      }

      if (cols[j].h == k) {
        while(!row.empty() && mat[cols[row.back()].td.front()][row.back()] < mat[cols[j].td.front()][j]) {
          row.pop_back();
        }
        row.push_back(j);
        if (!row.empty() && (j - row.front() + 1) > k) {
          row.pop_front();
        }
        l = min(l + 1, k);
        if (l == k) {
          int t = mat[cols[row.front()].td.front()][row.front()] - 1;
          result = (result < 0 ? t : min(result, t));
        }
      } else {
        row.clear();
        l = 0;
      }
    }
  }

  cout << result << endl;
}