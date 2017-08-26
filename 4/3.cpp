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

  set<string> names;
  map<string, int> prompts;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (names.find(s) == names.end()) {
      cout << "OK\n";
      names.insert(s);
      continue;
    }
    prompts[s] += 1;
    cout << s << prompts[s] << "\n";
  }
  return 0;
}