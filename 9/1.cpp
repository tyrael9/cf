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

  int Y, W;
  cin >> Y >> W;

  int t = 6 - max(Y, W) + 1;
  int b = 6;

  if (t == b) {
    cout << "1/1" << endl;
  } else {
    for (int i = 2; i < 6; ++i) {
      while ((t % i) == 0 && (b % i) == 0) {
        t /= i;
        b /= i;
      }
    }
    cout << t << "/" << b << endl;
  }
}