#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void rc_to_non_rc(string& s, int c_pos) {
  long row = 0;
  for (int i = 1; i < c_pos; ++i) {
    row *= 10;
    row += (s[i] - '0');
  }
  long col = 0;
  for (int i = c_pos + 1; i < s.length(); ++i) {
    col *= 10;
    col += (s[i] - '0');
  }
  string col_s;
  while (col > 0) {
    col_s.push_back('A' + ((col - 1) % 26));
    col = (col - 1) / 26;
  }
  reverse(col_s.begin(), col_s.end());
  cout << col_s << row << endl;
}

void non_rc_to_rc(string& s) {
  long row = 0;
  long col = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] >= '0' && s[i] <= '9') {
      row *= 10;
      row += (s[i] - '0');
    } else {
      col *= 26;
      col += (s[i] - 'A') + 1;
    }
  }
  cout << "R" << row << "C" << col << endl;
}

int main(int argc, char** argv) {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int k = 0;
    int c_pos = -1;
    while (k < s.length()) {
      if (s[k] == 'C') {
        if ((s[k - 1] >= '0' && s[k - 1] <= '9') && (s[k + 1] >= '0' && s[k + 1] <= '9')) {
          c_pos = k;
          break;
        }
      }
      ++k;
    }
    if (c_pos >= 0) {
      rc_to_non_rc(s, c_pos);
    } else {
      non_rc_to_rc(s);
    }
  }
}