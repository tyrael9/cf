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

int n;
string has_class[1000];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> has_class[i];
  }

  int max_rooms = 0;
  for (int i = 0; i < 7; ++i) {
    int num_rooms = 0;
    for (int j = 0; j < n; ++j) {
      if (has_class[j][i] == '1') {
        ++num_rooms;
      }
    }
    max_rooms = max(max_rooms, num_rooms);
  }
  cout << max_rooms << endl;
}