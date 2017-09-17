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
#include <unordered_map>

using namespace std;

unordered_map<long long, set<int>> phone;
vector<string> vs;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    vs.push_back(s);
  }

  for (int i = 0; i < vs.size(); ++i) {
    for (int j = 0; j < vs[i].length(); ++j) {
      long long val = 1;
      for (int k = j; k < vs[i].length(); ++k) {
        val *= 10;
        val += vs[i][k] - '0';
        phone[val].insert(i);
      }
    }
  }

  for (int i = 0; i < vs.size(); ++i) {
    long long minval = -1;
    for (int j = 0; j < vs[i].length(); ++j) {
      long long val = 1;
      for (int k = j; k < vs[i].length(); ++k) {
        val *= 10;
        val += vs[i][k] - '0';
        if (phone[val].size() == 1 && (*phone[val].begin()) == i) {
          if (minval < 0 || val < minval) {
            minval = val;
          }
        }
      }
    }

    cout << to_string(minval).substr(1) << "\n";
  }
}