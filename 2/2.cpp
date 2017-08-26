#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdio.h>
#include <assert.h>

using namespace std;

int main(int argc, char** argv) {
  bool has_zero = false;
  int zero_i, zero_j;
  int n;
  scanf("%d", &n);
  vector<vector<vector<char>>> nums(2, vector<vector<char>>(n, vector<char>(n, 0)));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      long val;
      scanf("%ld", &val);
      if (val == 0) {
        has_zero = true;
        zero_i = i;
        zero_j = j;
        nums[0][i][j] = -1;
        nums[1][i][j] = -1;
        continue;
      }
      while ((val & 0x1) == 0) {
        val = val >> 1;
        ++nums[0][i][j];
      }
      while (val % 5 == 0) {
        val = val / 5;
        ++nums[1][i][j];
      }
    }
  }
  vector<vector<long>> min_dp(2, vector<long>(n, 0));
  vector<vector<vector<char>>> min_dp_move(2, vector<vector<char>>(n, vector<char>(n, 0)));
  min_dp[0][0] = nums[0][0][0];
  min_dp[1][0] = nums[1][0][0];
  for (int j = 1; j < n; ++j) {
    for (int k = 0; k < 2; ++k) {
      if (min_dp[k][j - 1] < 0) {
        min_dp[k][j] = -1;
        min_dp_move[k][0][j] = 'U';
      } else {
        min_dp[k][j] = (nums[k][0][j] < 0 ? -1 : (min_dp[k][j - 1] + nums[k][0][j]));
        min_dp_move[k][0][j] = 'R';
      }
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int k = 0; k < 2; ++k) {
      if (min_dp[k][0] < 0) {
        min_dp[k][0] = -1;
        min_dp_move[k][i][0] = 'U';
      } else {
        min_dp[k][0] = (nums[k][i][0] < 0 ? -1 : (min_dp[k][0] + nums[k][i][0]));
        min_dp_move[k][i][0] = 'D';
      }
    }
    for (int j = 1; j < n; ++j) {
      for (int k = 0; k < 2; ++k) {
        if (min_dp[k][j] < 0) {
          if (min_dp[k][j - 1] < 0) {
            min_dp[k][j] = -1;
            min_dp_move[k][i][j] = 'U';
          } else {
            min_dp[k][j] = (nums[k][i][j] < 0 ? -1 : (min_dp[k][j - 1] + nums[k][i][j]));
            min_dp_move[k][i][j] = 'R';
          }
        } else {
          if (min_dp[k][j - 1] < 0) {
            min_dp[k][j] = (nums[k][i][j] < 0 ? -1 : (min_dp[k][j] + nums[k][i][j]));
            min_dp_move[k][i][j] = 'D';
          } else {
            min_dp_move[k][i][j] = (min_dp[k][j] < min_dp[k][j - 1] ? 'D' : 'R');
            min_dp[k][j] = (nums[k][i][j] < 0 ? -1 : (min_dp[k][j] < min_dp[k][j - 1] ? (min_dp[k][j] + nums[k][i][j]) : (min_dp[k][j - 1] + nums[k][i][j])));
          }
        }
      }
    }
  }

  if (has_zero && ((max(min_dp[0][n-1], min_dp[1][n-1]) < 0) || (min(min_dp[0][n-1], min_dp[1][n-1]) > 1))) {
    printf("1\n");
    for(int i = 0; i < zero_i; ++i) {
      printf("D");
    }
    for(int j = 0; j < zero_j; ++j) {
      printf("R");
    }
    for(int i = zero_i; i < n - 1; ++i) {
      printf("D");
    }
    for(int j = zero_j; j < n - 1; ++j) {
      printf("R");
    }
    printf("\n");
  } else {
    int k = (min_dp[0][n-1] < min_dp[1][n-1] ? 0 : 1);
    printf("%ld\n", min_dp[k][n-1]);
    string moves;
    int i = n - 1, j = n - 1;
    while ((i > 0) || (j > 0)) {
      if (min_dp_move[k][i][j] == 'D') {
        --i;
        moves.push_back('D');
      } else if (min_dp_move[k][i][j] == 'R') {
        --j;
        moves.push_back('R');
      } else {
        assert(false);
      }
    }
    std::reverse(moves.begin(), moves.end());
    printf("%s\n", moves.c_str());
  }
}