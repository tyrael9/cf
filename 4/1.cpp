#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int w;
  cin >> w;
  if (w == 2) {
    cout << "NO" << endl;
    return 0;
  }
  cout << (w % 2 == 0 ? "YES" : "NO") << endl; 
  return 0;
}