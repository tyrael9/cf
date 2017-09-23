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
#include <unordered_set>
#include <unordered_map>

using namespace std;

int v[1000][5];
unordered_set<int> bad;
unordered_set<int> pending;

bool is_good(int a, int b, int c) {
  long dot_sum = 0;
  for (int i = 0; i < 5; ++i) {
    dot_sum += (v[b][i] - v[a][i]) * (v[c][i] - v[a][i]);
  }
  return dot_sum <= 0;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    pending.insert(i);
    for (int j = 0; j < 5; ++j) {
      cin >> v[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    pending.erase(i);
    if (bad.find(i) != bad.end()) {
      continue;
    }
    while (!pending.empty()) {
      int j = *pending.begin();
      pending.erase(j);
      int k = -1;
      if (!pending.empty()) {
        k = *pending.begin();
        pending.erase(k);
      }
      if (k == -1) {
        if (i > 0) {
          k = i - 1;
        } else {
          if (j - 1 > i) {
            k = j - 1;
          } else if (j + 1 < n) {
            k = j + 1;
          }
        }
      }
      if (k == -1) {
        break;
      }
      if (is_good(i, j, k)) {
        bad.insert(j);
        bad.insert(k);
      } else {
        bad.insert(i);
        break;
      }
    }
    if (bad.find(i) != bad.end()) {
      continue;
    }
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < j; ++k) {
        if ((k == i) || (j == i)) {
          continue;
        }
        if (!is_good(i, j, k)) {
          bad.insert(i);
          break;
        }
      }
      if (bad.find(i) != bad.end()) {
        break;
      }
    }
  }

  cout << n - bad.size() << "\n";
  for (int i = 0; i < n; ++i) {
    if (bad.find(i) == bad.end()) {
      cout << i + 1 << "\n";
    }
  }
}