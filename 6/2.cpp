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

char mat[100][100];
pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n, m;
  char c;
  cin >> n >> m;
  cin >> c;
  set<char> seen;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == c) {
        for (const auto& d: dir) {
          int k = d.first;
          int l = d.second;
          if ((i + k >= 0) && (i + k < n) && (j + l >= 0) && (j + l < m)) {
            seen.insert(mat[i+k][j+l]);
          }
        }
      }
    }
  }
  seen.erase(c);
  seen.erase('.');
  cout << seen.size() << endl;
}