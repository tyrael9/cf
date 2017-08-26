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

using namespace std;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  string s;
  cin >> s;
  vector<int> dp(s.length());
  stack<int> stk;
  int maxlen = 0;
  int max_count = 1;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '(') {
      stk.push(i);
      dp[i] = 0;
    } else {
      if (!stk.empty()) {
        int l = stk.top();
        stk.pop();
        dp[i] = (l > 0 ? dp[l - 1] : 0) + (i - l) + 1;
        if (dp[i] > maxlen) {
          maxlen = dp[i];
          max_count = 1;
        } else if ((dp[i] == maxlen) && (maxlen > 0)) {
          ++max_count;
        }
      } else {
        dp[i] = 0;
      }
    }
  }
  cout << maxlen << " " << max_count << endl;
}