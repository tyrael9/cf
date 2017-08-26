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

  priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
  string s;
  cin >> s;
  int count = 0;
  long long sum = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '(') {
      ++count;
    } else if (s[i] == ')') {
      --count;
    } else {
      long lc, rc;
      cin >> lc >> rc;
      pq.push({lc - rc, i});
      s[i] = ')';
      --count;
      sum += rc;
    }
    if (count < 0) {
      if (pq.empty()) {
        cout << -1 << endl;
        return 0;
      }
      s[pq.top().second] = '(';
      count += 2;
      sum += pq.top().first;
      pq.pop();
    }
  }
  if (count != 0) {
    cout << -1 << endl;
  } else {
    cout << sum << endl;
    cout << s << endl;
  }
  return 0;
}