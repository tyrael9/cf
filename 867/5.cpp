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

  map<long long, long long> mpq;
  cin >> n;
  long long result = 0;
  for (int i = 0; i < n; ++i) {
    long long val;
    cin >> val;
    if (mpq.empty() || mpq.begin()->first >= val) {
      ++mpq[val];
      continue;
    }
    auto it = mpq.begin();
    result -= it->first;
    cout << "Match " << it->first << " " << val << endl;
    it->second = it->second - 1;
    if (it->second == 0) {
      mpq.erase(it->first);
    }
    ++mpq[val];
    result += val;
  }
  cout << result << endl;
}