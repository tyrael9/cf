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

using namespace std;

long long n, a, b, k, f;
map<pair<string, string>, long long> costed;
vector<long long> v;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n >> a >> b >> k >> f;
  string src, dst;
  long long total_cost = 0;
  for (int i = 0; i < n; ++i) {
    cin >> src;
    long long cur_cost = a;
    if (src == dst) {
      cur_cost = b;
    }
    cin >> dst;
    if (src < dst) {
      costed[{src, dst}] += cur_cost;
    } else {
      costed[{dst, src}] += cur_cost;
    }
    total_cost += cur_cost;
  }

  for (const auto& p: costed) {
    v.push_back(p.second);
  }
  sort(v.begin(), v.end());
  for (int i = v.size() - 1; i >= 0; --i) {
    if (k <= 0) {
      break;
    }

    if (f < v[i]) {
      total_cost -= v[i];
      total_cost += f;
      --k;
    } else {
      break;
    }
  }
  cout << total_cost << endl;
}