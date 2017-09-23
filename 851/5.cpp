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

long long a[100];
map<unsigned long, unsigned long> v;

unsigned long solve(unsigned long mask) {
  set<int> mex;
  if (v.find(mask) != v.end()) {
    return v[mask];
  }
  for (int i = 0; i < 32; ++i) {
    if ((mask >> i) > 0) {
      mex.insert(solve((mask >> (i + 1)) | (mask & ((1 << i) - 1))));
    }
  }
  unsigned long res = 0;
  while (mex.find(res) != mex.end()) {
    ++res;
  }
  v[mask] = res;
  return res;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  
  map<long long, unsigned long> factors;
  for (int i = 0; i < n; ++i) {
    for (long long x = 2; x * x <= 1000000000LL; ++x) {
      int bit = 0;
      while (a[i] % x == 0) {
        a[i] /= x;
        ++bit;
      }
      if (bit > 0) {
        factors[x] = factors[x] | (1 << (bit - 1));
      }
    }
    if (a[i] > 1) {
      factors[a[i]] = factors[a[i]] | 1;
    }
  }
  
  unsigned long result = 0;
  for (const auto& p : factors) {
    result ^= solve(p.second);
  }
  cout << (result ? "Mojtaba" : "Arpa") << endl;
}