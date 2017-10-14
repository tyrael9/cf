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
#include <string.h>

using namespace std;

long long a[1000001];
long long n;
int last_pos[1000001];
int nxt[1000001];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n;
  long long cur_sum = 0;
  long long num_uniq = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (last_pos[a[i]] == 0) {
      ++num_uniq;
    } else {
      nxt[last_pos[a[i]]] = i;
    }
    last_pos[a[i]] = i;
    cur_sum += num_uniq;
  }
  long long total_sum = 0;
  for (int i = 1; i <= n; ++i) {
    total_sum += (cur_sum - 1) * 2;
    cur_sum -= ((nxt[i] == 0 ? n + 1 : nxt[i]) - i);
  }
  total_sum += n;
  long long total_cnt = n * n;
  double result = (double)total_sum / (double)total_cnt;
  std::cout.precision(12);
  cout << std::fixed << result << endl;
}