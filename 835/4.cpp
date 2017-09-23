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

bool is_palin[5000][5000];
int palin_d[5000];
int result[5001];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i <= n; ++i) {
    result[i] = 0;
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i; j < n; ++j) {
      is_palin[i][j] = ((i + 1 > j - 1) ? true : is_palin[i + 1][j - 1]) && (s[i] == s[j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (i == j) {
        palin_d[j] = 1;
      } else {
        if (is_palin[i][j]) {
          palin_d[j] = palin_d[i + (j - i + 1) / 2 - 1] + 1;
        } else {
          palin_d[j] = 0;
        }
      }
      ++result[palin_d[j]];
    }
  }
  for (int i = n - 2; i >= 1; --i) {
    result[i] += result[i + 1];
  }
  for (int i = 1; i <= n; ++i) {
    cout << result[i];
    if (i < n) {
      cout << " ";
    }
  }
  cout << endl;
}