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

map<pair<int, int>, map<int, long long>> lt_map;
map<pair<int, int>, map<int, long long>> goet_map;

long long numTreesLessThanHeight(int l, int r, int h) {
  if (h <= 0) {
    return 0;
  }
  if (l > r) {
    return 1;
  }
  if (lt_map.find({l, r}) != lt_map.end() && lt_map[{l, r}].find(h) != lt_map[{l, r}].end()) {
    return lt_map[{l, r}][h];
  }
  long long result = 0;
  for (int i = l; i <= r; ++i) {
    result += numTreesLessThanHeight(l, i - 1, h - 1) * numTreesLessThanHeight(i + 1, r, h - 1);
  }
  lt_map[{l, r}][h] = result;
  return result;
}

long long numTreesGreaterOrEqualThanHeight(int l, int r, int h) {
  if (r - l + 1 < h) {
    return 0;
  }
  if (l > r) {
    return 1;
  }
  if (goet_map.find({l, r}) != goet_map.end() && goet_map[{l, r}].find(h) != goet_map[{l, r}].end()) {
    return goet_map[{l, r}][h];
  }
  long long result = 0;
  for (int i = l; i <= r; ++i) {
    result += numTreesGreaterOrEqualThanHeight(l, i - 1, h - 1) * numTreesLessThanHeight(i + 1, r, h - 1) +
              numTreesLessThanHeight(l, i - 1, h - 1) * numTreesGreaterOrEqualThanHeight(i + 1, r, h - 1) +
              numTreesGreaterOrEqualThanHeight(l, i - 1, h - 1) * numTreesGreaterOrEqualThanHeight(i + 1, r, h - 1);
  }
  goet_map[{l, r}][h] = result;
  return result;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n, h;
  cin >> n >> h;
  cout << numTreesGreaterOrEqualThanHeight(1, n, h) << endl;
}