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

int K;
set<int> accepted;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> K;

  for (int i = 0; i < K; ++i) {
    int r;
    cin >> r;
    accepted.insert(r);
  }
  for (int i = 1; i <= 25; ++i) {
    if ((accepted.find(i) == accepted.end()) && (accepted.size() < 25)) {
      accepted.insert(i);
    }
  }
  long cur = 0;
  long num_declined = 0;
  for (const auto r : accepted) {
    if (r != cur + 1) {
      num_declined += r - cur - 1;
    }
    cur = r;
  }
  cout << num_declined << endl;
}