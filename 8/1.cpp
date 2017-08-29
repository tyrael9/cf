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
#include <stdio.h>
#include <math.h>

using namespace std;

string res[2][2] = {{"fantasy", "backward"}, {"forward", "both"}};

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  string s, s1, s2;
  cin >> s;
  cin >> s1;
  cin >> s2;
  string rs1 = s1;
  string rs2 = s2;
  reverse(rs1.begin(), rs1.end());
  reverse(rs2.begin(), rs2.end());
  size_t ss1 = s.find(s1), rss2 = s.rfind(s2);
  size_t rsrs1 = s.rfind(rs1), srs2 = s.find(rs2);
  int ok = 0, rok = 0;
  if (ss1 != string::npos && rss2 != string::npos && ss1 + s1.length() <= rss2) {
    ok = 1;
  }
  if (rsrs1 != string::npos && srs2 != string::npos && srs2 + rs2.length() <= rsrs1) {
    rok = 1;
  }
  cout << res[ok][rok] << endl;
  return 0;
}