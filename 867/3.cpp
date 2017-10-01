#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <list>
#include <stack>
#include <bitset>
#include <cmath>
#include <climits>
#include <cassert>

using namespace std;

struct con {
  long long s;
  long long a;
  long long b;
};

long long N, S;
// con arr[100000];

map<long long, long long> diff_t1;
map<long long, long long> diff_t2;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> N >> S;
  long long sum_s = 0;
  long long sum_t1_o = 0;
  long long sum_t2_o = 0;
  long long result = 0;
  for (int i = 0; i < N; ++i) {
    long long s, a, b;
    cin >> s >> a >> b;
    sum_s += s;
    if (a >= b) {
      sum_t1_o += s;
      result += s * a;
      diff_t1[a - b] += s;
    } else if (a < b) {
      sum_t2_o += s;
      result += s * b;
      diff_t2[b - a] += s;
    }
  }
  long long num_p = (sum_s + (S - 1)) / S;
  long long total_extra = sum_s % S;
  long long num_t1_extra = sum_t1_o % S;
  long long num_t2_extra = sum_t2_o % S;
  if (num_t1_extra + num_t2_extra > S) {
    cout << result << "\n";
    return 0;
  }
  long long result_t1 = result;
  while (num_t1_extra > 0) {
    auto it = diff_t1.begin();
    result_t1 -= min(it->second, num_t1_extra) * it->first;
    num_t1_extra -= it->second;
    diff_t1.erase(it->first);
  }
  long long result_t2 = result;
  while (num_t2_extra > 0) {
    auto it = diff_t2.begin();
    result_t2 -= min(it->second, num_t2_extra) * it->first;
    num_t2_extra -= it->second;
    diff_t2.erase(it->first);
  }
  cout << max(result_t1, result_t2) << "\n";
}