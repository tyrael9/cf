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

char b[8][8];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      cin >> b[i][j];
    }
  }
  int nabr = 0;
  int nabc = 0;
  for (int i = 0; i < 8; ++i) {
    bool abr = true;
    bool abc = true;
    for (int j = 0; j < 8; ++j) {
      if (b[i][j] != 'B') {
        abr = false;
      }
      if (b[j][i] != 'B') {
        abc = false;
      }
    }
    if (abr) ++nabr;
    if (abc) ++nabc;
  }
  cout << (nabr == 8 && nabc == 8 ? 8 : nabr + nabc) << endl;
}