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

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  vector<int> n(4);
  for (int i = 0; i < 4; ++i) {
    cin >> n[i];
  }
  sort(n.begin(), n.end());
  bool has_segment = false;
  for (int i = 0; i < 4; ++i) {
    for (int j = i + 1; j < 4; ++j) {
      for (int k = j + 1; k < 4; ++k) {
        if (n[i] + n[j] > n[k]) {
          cout << "TRIANGLE" << endl;
          return 0;
        } else if (n[i] + n[j] == n[k]) {
          has_segment = true;
        }
      }
    }
  }
  cout << (has_segment ? "SEGMENT" : "IMPOSSIBLE") << endl;
  return 0;
}