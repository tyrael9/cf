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

double prob[64][64];
double prob_dp[64][64][64];
double score_dp[64][64][64];

const double EPS = 1e-9;

int get_deviation(double a, double b) {
  double delta = a - b;
  if (abs(delta) < EPS) return 0;
  return (delta > 0 ? 1 : -1);
}

void do_it(int l, int r, int winner) {
  if (prob_dp[l][r][winner] > -1.0) {
    return;
  }
  if (l + 1 == r) {
    if (winner == l) {
      prob_dp[l][r][winner] = prob[l][r];
    } else {
      prob_dp[l][r][winner] = prob[r][l];
    }
    return;
  }
  double cur_prob = 0;
  int mid = (l + r + 1) / 2;
  if (winner < mid) {
    do_it(l, mid - 1, winner);
    for (int i = mid; i <= r; ++i) {
      do_it(mid, r, i);
      cur_prob += prob[winner][i] * prob_dp[mid][r][i];
    }
    cur_prob *= prob_dp[l][mid - 1][winner];
  } else {
    do_it(mid, r, winner);
    for (int i = l; i < mid; ++i) {
      do_it(l, mid - 1, i);
      cur_prob += prob[winner][i] * prob_dp[l][mid - 1][i];
    }
    cur_prob *= prob_dp[mid][r][winner];
  }
  prob_dp[l][r][winner] = cur_prob;
}

void do_it_2(int l, int r, int rnd, int winner) {
  if (score_dp[l][r][winner] > -1.0) {
    return;
  }
  if (l + 1 == r) {
    score_dp[l][r][winner] = prob_dp[l][r][winner] * (double)(1 << (rnd - 1));
    return;
  }
  double cur_score = -1.0;
  int mid = (l + r + 1) / 2;
  if (winner < mid) {
    do_it_2(l, mid - 1, rnd -1 , winner);
    for (int i = mid; i <= r; ++i) {
      do_it_2(mid, r, rnd -1 , i);
      if ((cur_score < 0) || (get_deviation(cur_score, score_dp[mid][r][i]) < 0)) {
        cur_score = score_dp[mid][r][i];
      }
    }
    cur_score += score_dp[l][mid - 1][winner];
    cur_score += prob_dp[l][r][winner] * (double)(1 << (rnd - 1));
  } else {
    do_it_2(mid, r, rnd -1 , winner);
    for (int i = l; i < mid; ++i) {
      do_it_2(l, mid - 1, rnd -1 , i);
      if ((cur_score < 0) || (get_deviation(cur_score, score_dp[l][mid -1][i]) < 0)) {
        cur_score = score_dp[l][mid - 1][i];
      }
    }
    cur_score += score_dp[mid][r][winner];
    cur_score += prob_dp[l][r][winner] * (double)(1 << (rnd - 1));
  }
  score_dp[l][r][winner] = cur_score;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int N;
  int n;
  cin >> N;
  n = (1 << N);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int probb;
      cin >> probb;
      prob[i][j] = (double)(probb) / 100.0;
      for (int k = 0; k < n; ++k) {
        prob_dp[i][j][k] = -2.0;
        score_dp[i][j][k] = -2.0;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    do_it(0, n - 1, i);
  }
  for (int i = 0; i < n; ++i) {
    do_it_2(0, n - 1, N, i);
  }
  double max_score = -2.0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        if ((max_score < 0) || (get_deviation(max_score, score_dp[i][j][k]) < 0)) {
          max_score = score_dp[i][j][k];
        }
      }
    }
  }
  std::cout.precision(12);
  cout << std::fixed << max_score << endl;
}