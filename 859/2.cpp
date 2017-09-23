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

long N;

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> N;

  long min_perimeter = -1;
  for (long i = 1; i * i <= N; ++i) {
    long perimeter = 2 * (i + (N / i)) + (N % i == 0 ? 0 : 2);
    min_perimeter = (min_perimeter < 0 ? perimeter : min(min_perimeter, perimeter));
  }
  cout << min_perimeter << endl;
}