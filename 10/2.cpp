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

int l[100] = {0};
int r[100] = {0};

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    int m;
    cin >> m;
    if (m > k) {
      cout << "-1\n";
      continue;
    }

    int min_dist = -1;
    int min_j = -1, min_l = -1;
    for (int j = 1; j <= k; ++j) {
      int dist, cur_l;
      if (l[j] == 0) {
        dist = abs((j - (k + 1) / 2)) * m + (m % 2 == 0 ? (((m / 2) * (1 + m / 2)) -  m / 2) : ((m / 2) * (1 + m / 2)));
        cur_l = (k - m) / 2 + 1;
      } else {
        int dist_1 = abs((j - (k + 1) / 2)) * m + (((k + 1) / 2) * m - ((l[j] + l[j] - m - 1) * m) / 2);
        int dist_2 = abs((j - (k + 1) / 2)) * m + (((r[j] + r[j] + m + 1) * m) / 2 - ((k + 1) / 2) * m);
        if ((l[j] - 1 >= m) && (r[j] + m <= k)) {
          if (dist_1 <= dist_2) {
            dist = dist_1;
            cur_l = l[j] - m;
          } else {
            dist = dist_2;
            cur_l = r[j] + 1;
          }
        } else if (l[j] - 1 >= m) {
          dist = dist_1;
          cur_l = l[j] - m;
        } else if (r[j] + m <= k) {
          dist = dist_2;
          cur_l = r[j]+ 1;
        } else {
          continue;
        }
      }

      if ((min_dist < 0) || (dist < min_dist)) {
        min_dist = dist;
        min_j = j;
        min_l = cur_l;
      }
    }

    if (min_j < 0) {
      cout << "-1\n";
    } else {
      cout << min_j << " " << min_l << " " << min_l + m - 1 << "\n";
      bool empty = (l[min_j] == 0);
      l[min_j] = (empty ? (min_l) : (min_l < l[min_j] ? min_l : l[min_j]));
      r[min_j] = (empty ? (min_l + m - 1) : (min_l > r[min_j] ? r[min_j] + m : r[min_j]));
    }
  }
}