#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  int n, m;
  string s;
  string t;

  cin >> n >> m;
  cin >> s;
  cin >> t;

  int min_mismatch = n;
  int min_mismatch_j = -1;
  for (int j = 0; j < m - n + 1; ++j) {
    int mismatch = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] != t[j + i]) {
        mismatch += 1;
      }
    }
    if (mismatch <= min_mismatch) {
      min_mismatch = mismatch;
      min_mismatch_j = j;
    }
  }
  cout << min_mismatch << endl;
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[min_mismatch_j + i]) {
      cout << i + 1 << " ";
    }
  }
  cout << endl;
}