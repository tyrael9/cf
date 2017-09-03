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

// count of numbers that x <= b and reverse(x) > a
unsigned long long get_num_l_e_b_rev_g_a(unsigned long long a, unsigned long long b, int n) {
  
}

unsigned long long get_num_less_than(unsigned long long k, int n) {
  if ((k >> (n - 1)) != 0) {
    return (1 << n);
  }

  long long result = 0;
  bool even = (n % 2 == 0);
  int len = (n - 2) / 2;
  long long a = k >> (even ? len + 1 : len + 2);
  long long b = 0;
  for (int i = 1; i < len + 1; ++i) {
    b = b << 1;
    b = b | ((k >> i) & 1);
  }
  // consider those ones with trailing 0, a <= b
  // front half to "a-1"
  result += (2 << n) * a - ((a + 1) * a) / 2;
  if ((!even) {
    // double for middle toggle
    result += (2 << n) * a - ((a + 1) * a) / 2;
  }
  // 0a1bx ??
  if ((!even) && (((k >> len + 1) & 1) != 0)) {
    // count "a" stuff for middle 0
    result += ((2 << len) - a);
    // count "a" stuff for middle 1
    result += max(b - a + 1, 0);
  } else {
    // count "a" stuff for middle 0
    result += max(b - a + 1, 0);
  }
  // consider those ones with trailing 1, a <= flip(b)
  // front half to "a-1"
  result += (2 << n) * a - ((a + 1) * a) / 2;
  if ((!even) {
    // double for middle toggle
    result += (2 << n) * a - ((a + 1) * a) / 2;
  }
  // 0a1bx ??
  if ((!even) && (((k >> len + 1) & 1) != 0)) {
    // count "a" stuff for middle 1
    result += max(b - a + 1, 0);
  } else {
    // count "a" stuff for middle 0
    result += max(b - a + 1, 0);
  }

}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  
}