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

int n;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  map<long long, pair<long long, long long>> mpq;
  cin >> n;
  long long result = 0;
  for (int i = 0; i < n; ++i) {
    long long val;
    cin >> val;
    if (mpq.empty() || mpq.begin()->first >= val) {
      ++mpq[val].first;
      continue;
    }
    auto it = mpq.begin();
    result -= it->first;
    if (it->second.first > 0) {
      --it->second.first;
      // cout << "Match single " << it->first << " " << val << endl;
    } else if (it->second.second > 0) {
      --it->second.second;
      ++it->second.first;
      // cout << "Extend " << it->first << " " << val << endl;
    }

    if (it->second.first + it->second.second == 0) {
      mpq.erase(it->first);
      // cout << "Single is last " << it->first << " " << val << endl;
    }
    ++mpq[val].second;
    result += val;
  }
  cout << result << endl;
}