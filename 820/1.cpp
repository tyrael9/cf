#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
  long c, v0, v1, a, l;
  cin >> c >> v0 >> v1 >> a >> l;
  long current = 0;
  long long days = 0;
  while (true) {
    ++days;
    current = max(0L, current - l);
    current += v0;
    if (current >= c) {
      break;
    }
    v0 = min(v0 + a, v1);
  }
  cout << days << endl;
}