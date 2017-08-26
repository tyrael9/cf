#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int num_p = 0;
  long long bytes = 0;
  string s;
  while (getline(cin, s)) {
    if (s[0] == '+') {
      ++num_p;
    } else if (s[0] == '-') {
      --num_p;
    } else {
      for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ':') {
          bytes += num_p * (s.length() - 1 - i);
        }
      }
    }
  }
  cout << bytes << endl;
}