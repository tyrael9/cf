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

int n, crush[100];
int cir_len[100];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> crush[i];
  }
  for (int i = 0; i < n; ++i) {
    int cur = crush[i] - 1;
    int step = 1;
    while ((cur != i) && (step <= n)) {
      cur = crush[cur] - 1;
      ++step;
    }
    if (cur == i) {
      cir_len[i] = step;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  int factors[101];
  for (int i = 0; i <= 100; ++i) {
    factors[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    int cur_len = cir_len[i];
    for (int j = 2; j <= 100; ++j) {
      int cur_factors = 0;
      while (cur_len % j == 0) {
        cur_len /= j;
        cur_factors += 1;
      }
      if (cur_factors > factors[j]) {
        factors[j] = cur_factors;
      }
    }
  }
  long long result = 1;
  for (int i = 0; i <= 100; ++i) {
    for (int j = 0; j < factors[i]; ++j) {
      result *= i;
    }
  }
  if (result % 2 == 0) {
    cout << (result >> 1) << endl;
  } else {
    cout << result << endl;
  }
}