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

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<long> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  long long result = 0;
  deque<pair<long, long long>> q;
  pair<long, long long> largest_count = {-1, 0};
  pair<long, long long> second_largest_count = {-1, 0};
  for (int i = 0; i < n; ++i) {
    if (h[i] > largest_count.first) {
      second_largest_count = largest_count;
      largest_count = {h[i], 1};
    } else if (h[i] == largest_count.first) {
      largest_count.second += 1;
    } else if (h[i] > second_largest_count.first) {
      second_largest_count = {h[i], 1};
    } else if (h[i] == second_largest_count.first) {
      second_largest_count.second += 1;
    }

    while ((!q.empty()) && (h[i] > q.back().first)) {
      q.pop_back();
    }
    if ((!q.empty()) && (h[i] == q.back().first)) {
      q.back().second += 1;
    } else {
      q.push_back({h[i], 1});
    }
  }
  for (int i = 0; i < n; ++i) {
    if (h[i] == q.front().first) {
      q.front().second -= 1;
      if (q.front().second == 0) {
        q.pop_front();
      }
    }
    while ((!q.empty()) && (h[i] > q.back().first)) {
      result += q.back().second;
      q.pop_back();
    }
    if ((!q.empty()) && (h[i] == q.back().first)) {
      result += q.back().second;
      if (q.size() > 1) {
        result += 1;
      }
      q.back().second += 1;
    } else {
      if (q.size() > 0) {
        result += 1;
      }
      q.push_back({h[i], 1});
    }
  }
  if (largest_count.second == 1) {
    if (second_largest_count.second > 0) {
      result -= second_largest_count.second;
    }
  } else {
    result -= (largest_count.second * (largest_count.second - 1) / 2);
  }
  cout << result << endl;
}