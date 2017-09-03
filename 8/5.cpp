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

unsigned long long reverse_num(unsigned long long a, int n) {
  unsigned long long b = 0;
  for (int i = 0; i < n; ++i) {
    b = b << 1;
    b = b | ((a >> i) & 1);
  }
  return b;
}

unsigned long long flip_num(unsigned long long a, int n) {
  unsigned long long b = 0;
  for (int i = 0; i < n; ++i) {
    b = b << 1;
    b = b | (((a >> (n - i - 1)) & 1) ^ 1);
  }
  return b;
}

// count of numbers that x < b and reverse(x) > a
unsigned long long get_num_l_e_b_rev_g_e_a(unsigned long long a, unsigned long long b, int n) {
  unsigned long long cur_count = 0;
  for (int i = 0; i < n; ++i) {
    if (((b >> i) & 1) == 1) {
      if (i != 0) {
        cur_count += ((1 << i) - (a >> (n - i)) - 1);
      }
      if ((i != 0) && (((a >> (n - i - 1)) & 1) == 0)) {
        // in this case the previous part could be equal, which was not considered in previous computation
        cur_count += ((reverse_num((a >> (n - i)), i) < (b & ((1 << i) - 1))) ? 1 : 0);
      }
    }
  }
  return cur_count;
}

// count of numbers that x < b and reverse(flip(x)) > a
unsigned long long get_num_l_e_b_rev_flip_g_e_a(unsigned long long a, unsigned long long b, int n) {
  unsigned long long cur_count = 0;
  for (int i = 0; i < n; ++i) {
    if (((b >> i) & 1) == 1) {
      if (i != 0) {
        cur_count += ((1 << i) - (a >> (n - i)) - 1);
        if ((i != 0) && (((a >> (n - i - 1)) & 1) == 0)) {
          // in this case the previous part could be equal, which was not considered in previous computation
          ++cur_count;
        }
      } else {
        cur_count = (((a >> (n - i - 1)) & 1) == 0 ? 1 : 0);
      }
    } else {
      if ((i != 0) && (((a >> (n - i - 1)) & 1) == 0)) {
        // in this case the previous part could be equal, which was not considered in previous computation
        cur_count += ((flip_num(reverse_num((a >> (n - i)), i), i) < (b & ((1 << i) - 1))) ? 1 : 0);
      }
    }
  }
  return cur_count;
}

unsigned long long get_num_less_than(unsigned long long k, int n) {
  unsigned long long result = 0;
  bool even = (n % 2 == 0);
  int len = (n - 2) / 2;
  if (len == 0) {
    if (!even) {
      result = 1;
      if (k >= 1) {
        ++result;
      }
      if (k >= 2) {
        ++result;
      }
      return result;
    } else {
      result = 1;
      if (k >= 1) {
        ++result;
      }
      return result;
    }
  }

  if ((k >> (n - 1)) != 0) {
    return 2 * (1 << len) * ((1 << len) + 1);
  }

  unsigned long long a = k >> (even ? len + 1 : len + 2);
  unsigned long long b = 0;
  for (int i = len; i >= 1; --i) {
    b = b << 1;
    b = b | ((k >> i) & 1);
  }
  // consider those ones with trailing 0, a <= b
  // front half to "a-1"
  result += (1 << len) * a - ((a - 1) * a) / 2;
  if (!even) {
    // double for middle toggle
    result += (1 << len) * a - ((a - 1) * a) / 2;
  }
  // 0a1bx ??
  if ((!even) && (((k >> (len + 1)) & 1) != 0)) {
    // count "a" stuff for middle 0
    result += ((1 << len) - a);
  }
  // count "a" stuff for middle == middle
  result += get_num_l_e_b_rev_g_e_a(a, b, len);
  if (reverse_num(a, len) < b) {
    ++result;
  }
  if (reverse_num(b, len) >= a) {
    ++result;
  }

  // consider those ones with trailing 1, a <= flip(b)
  // front half to "a-1"
  result += (1 << len) * a - ((a - 1) * a) / 2;
  if (!even) {
    // double for middle toggle
    // must be greater, equal is not good
    result += (1 << len) * a - ((a + 1) * a) / 2;
  }
  // 0a1bx ??
  if ((!even) && (((k >> (len + 1)) & 1) != 0)) {
    // count "a" stuff for middle 0
    result += ((1 << len) - a);
  }
  // count "a" stuff for middle == middle
  result += get_num_l_e_b_rev_flip_g_e_a(a, b, len);
  bool mid_is_zero = true;
  if ((!even) && (((k >> (len + 1)) & 1) != 0)) {
    mid_is_zero = false;
  }
  if ((flip_num(reverse_num(a, len), len) < b) && mid_is_zero) {
    ++result;
  }
  if (((flip_num(reverse_num(b, len), len) > a) || ((flip_num(reverse_num(b, len), len) == a) && mid_is_zero)) && ((k & 1) != 0)) {
    ++result;
  }
  return result;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);
  // cout << get_num_less_than(18, 6) << endl;

  unsigned long long n;
  unsigned long long k;
  cin >> n >> k;
  unsigned long long l = 0, r = (1ULL << n) - 1ULL;
  while (l < r) {
    unsigned long long mid = l + (r - l) / 2ULL;
    // cout << get_num_less_than(mid, n) << " " << mid << endl;
    if (get_num_less_than(mid, n) >= k + 1) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  if (get_num_less_than(l, n) != k + 1) {
    cout << "-1\n";
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    cout << ((l >> (n - i - 1)) & 1);
  }
  cout << "\n";
}