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

int N;
long long s[50];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> s[i];
  }
  int a[2];
  int b[2];
  a[0] = s[N - 1];
  a[1] = 0;
  b[0] = 0;
  b[1] = s[N - 1];
  for (int i = N - 2; i >= 0; --i) {
    int tmpa[2];
    int tmpb[2];
    if (s[i] + b[0] > a[0]) {
      tmpa[0] = s[i] + b[0];
      tmpa[1] = b[1];
    } else {
      tmpa[0] = a[0];
      tmpa[1] = a[1] + s[i];
    }
    if (s[i] + a[1] > b[1]) {
      tmpb[1] = s[i] + a[1];
      tmpb[0] = a[0];
    } else {
      tmpb[1] = b[1];
      tmpb[0] = b[0] + s[i];
    }
    a[0] = tmpa[0];
    a[1] = tmpa[1];
    b[0] = tmpb[0];
    b[1] = tmpb[1];
  }
  cout << b[0] << " " << b[1] << endl;
}