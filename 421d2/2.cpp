#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
  long n, a;
  cin >> n >> a;
  long k = a * n / 180;
  if (a * n > 180 * (n - 2)) {
    k = n - 2;
  }
  if (k == 0) {
    k = 1;
  }
  if ((k < n - 2) && (k > 0)) {
    if (abs((k + 1) * 180 - a * n) < abs(k * 180 - a * n)) {
      k = k + 1;
    }
  }
  cout << 2 << " " << 1 << " " << 2 + k << endl;
}