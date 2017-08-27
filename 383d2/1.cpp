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

int rem[4] = {6, 8, 4, 2};

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  long n;
  cin >> n;
  
  if (n == 0) {
    cout << 1 << endl;
  } else {
    cout << rem[n % 4] << endl;
  }
  return 0;
}