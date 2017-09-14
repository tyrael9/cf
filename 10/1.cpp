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

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n, p1, p2, p3, t1, t2;
  cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
  long long power = 0;
  int l = -1, r = -1;
  for (int i = 0; i < n; ++i) {
    int prevl = l, prevr = r;
    cin >> l >> r;
    power += (r - l) * p1;
    int dur = l - (prevr < 0 ? l : prevr); 
    power += max(0, min(t1, dur)) * p1;
    power += max(0, min(t2, dur - t1)) * p2;
    power += max(0, dur - t1 - t2) * p3;
  }
  cout << power << endl;
}