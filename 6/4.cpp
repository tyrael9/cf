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

int dp[10][17][17];
int prevj[10][17][17];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int a, b, n;
  cin >> n >> a >> b;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 17; ++j) {
      for (int k = 0; k < 17; ++k) {
        dp[i][j][k] = -1;
        prevj[i][j][k] = -1;
      }
    }
  }

  for (int j = 0; j < 17; ++j) {
    for (int k = 0; k < 17; ++k) {
      dp[0][j][k] = -1;
      prevj[0][j][k] = -1;
    }
  }
  dp[0][0][0] = 0;

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 17; ++j) {
      for (int k = 0; k < 17; ++k) {
        if ((i == n - 1) && (k != 0)) {
          continue;
        }
        int min_hit = -1;
        int min_prevj = -1;
        for (int l = 0; l < 17; ++l) {
          if (dp[i - 1][l][j] < 0) {
            continue;
          }
          if (k * b + j * a + l * b > h[i - 1]) {
            if ((min_hit < 0) || (dp[i - 1][l][j] + k < min_hit)) {
              min_hit = dp[i - 1][l][j] + k;
              min_prevj = l;
            }
          }
        }
        // cout << i << " " << j << " " << k << " "<< min_hit << "\n";
        dp[i][j][k] = min_hit;
        prevj[i][j][k] = min_prevj;
      }
    }
  }

  int min_result = -1;
  int min_j = -1;
  for (int j = 0; j < 17; ++j) {
    if ((j * b > h[n - 1]) && (dp[n - 1][j][0] > 0)) {
      if ((min_result < 0) || (min_result > dp[n - 1][j][0])) {
        min_result = dp[n - 1][j][0];
        min_j = j;
      }
    }
  }

  cout << min_result << "\n";
  vector<int> ids;
  int i = n - 1;
  int cur_hit = 0;
  int prev_hit = min_j;
  while (i > 0) {
    for (int k = 0; k < cur_hit; ++k) {
      ids.push_back(i + 1);
    }
    int tmp_hit = prev_hit;
    prev_hit = prevj[i][prev_hit][cur_hit];
    cur_hit = tmp_hit;
    --i;
  }
  for (int l = 0; l < ids.size(); ++l) {
    cout << ids[l];
    if (l != ids.size() - 1) {
      cout << " ";
    }
  }
  cout << "\n";
}