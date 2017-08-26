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

  vector<string> ss;
  string s;
  size_t maxlen = 0;
  while (getline(cin, s)) {
    maxlen = max(s.length(), maxlen);
    ss.push_back(s);
  }
  for (int i = 0; i < maxlen + 2; ++i) {
    cout << "*";
  }
  cout << "\n";
  bool left = true;
  for (int i = 0; i < ss.size(); ++i) {
    int difflen = maxlen - ss[i].length();
    cout << "*";
    for (int i = 0; i < difflen / 2; ++i) {
      cout << " ";
    }
    if ((difflen % 2 != 0) && (!left)) {
      cout << " ";
    }
    cout << ss[i];
    if ((difflen % 2 != 0) && (left)) {
      cout << " ";
    }
    for (int i = 0; i < difflen / 2; ++i) {
      cout << " ";
    }
    cout << "*\n";
    if (difflen % 2 != 0) {
      left = !left;
    }
  }
  for (int i = 0; i < maxlen + 2; ++i) {
    cout << "*";
  }
  cout << "\n";
}