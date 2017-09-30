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

struct item {
  int t;
  int d;
  int p;
  int id;
};

int dp[2001][100];
pair<int, int> dp_prev[2001][100];
int n;
vector<item> items;

bool cmp_item(const item& it1, const item& it2) {
  return it1.d < it2.d;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int t, d, p;
    cin >> t >> d >> p;
    items.push_back({t, d, p, i + 1});
  }

  sort(items.begin(), items.end(), cmp_item);

  for (int i = 0; i <= 2000; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i >= items[j].d) {
        dp[i][j] = (j > 0 ? dp[i][j - 1] : 0);
        dp_prev[i][j] = {i, j - 1};
      } else {
        if (j > 0) {
          dp[i][j] = dp[i][j - 1];
          dp_prev[i][j] = {i, j - 1};
          if (i >= items[j].t) {
            if (dp[i - items[j].t][j - 1] + items[j].p > dp[i][j]) {
              dp[i][j] = dp[i - items[j].t][j - 1] + items[j].p;
              dp_prev[i][j] = {i - items[j].t, j - 1};
            }
          }
        } else {
          if (i >= items[j].t) {
            dp[i][j] = items[j].p;
            dp_prev[i][j] = {i - items[j].t, j - 1};
          } else {
            dp[i][j] = 0;
            dp_prev[i][j] = {i, j - 1};
          }
        }
      }
    }
  }

  int max_cost = 0;
  int max_i = 0;
  for (int i = 0; i <= 2000; ++i) {
    if (max_cost < dp[i][n - 1]) {
      max_cost = dp[i][n - 1];
      max_i = i;
    }
  }

  cout << max_cost << "\n";
  int cur_j = n - 1;
  int cur_i = max_i;
  vector<int> result;
  while (cur_j >= 0) {
    int next_i = dp_prev[cur_i][cur_j].first;
    int next_j = dp_prev[cur_i][cur_j].second;
    if (next_i != cur_i) {
      result.push_back(cur_j);
    }
    cur_i = next_i;
    cur_j = next_j;
  }
  std::reverse(result.begin(), result.end());
  cout << result.size() << "\n";
  for (int i = 0; i < result.size(); ++i) {
    cout << items[result[i]].id;
    if (i != result.size() - 1) {
      cout << " ";
    }
  }
  cout << "\n";
}