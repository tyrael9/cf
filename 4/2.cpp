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

  int d, sum_time;
  cin >> d >> sum_time;
  vector<int> min_time(d, 0);
  vector<int> max_time(d, 0);
  for (int i = 0; i < d; ++i) {
    int m, n;
    cin >> m >> n;
    min_time[i] = (i > 0 ? min_time[i - 1] + m : m);
    max_time[i] = (i > 0 ? max_time[i - 1] + n : n);
  }
  if ((sum_time >= min_time[d - 1]) && (sum_time <= max_time[d - 1])) {
    cout << "YES" << endl;
    vector<int> result;
    for (int i = d - 1; i >= 1; --i) {
      int m = min_time[i] - min_time[i - 1];
      int n = max_time[i] - max_time[i - 1];
      for (int k = m; k <= n; ++k) {
        if ((sum_time - k >= min_time[i - 1]) && (sum_time - k <= max_time[i - 1])) {
          sum_time -= k;
          result.push_back(k);
          break;
        }
      }
    }
    result.push_back(sum_time);
    std::reverse(result.begin(), result.end());
    for (int i = 0; i < result.size(); ++i) {
      cout << result[i];
      if (i < result.size() - 1) {
        cout << " ";
      }
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
  }
}