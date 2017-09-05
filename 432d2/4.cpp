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

long x, y, n;
long a[500000];

long cost[1000000];
int count[1000000];

void factor(long num) {
  for (long i = 1; i * i <= num; ++i) {
    if (num % i == 0) {

    }
  }
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);
  
  cin >> n >> x >> y;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }


}