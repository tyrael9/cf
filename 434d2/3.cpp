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

string s;
bool isvowel[256];

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> s;
  isvowel['a'] = true;
  isvowel['e'] = true;
  isvowel['i'] = true;
  isvowel['o'] = true;
  isvowel['u'] = true;

  set<char> cons;
  int last_cons_index = -1;
  int len_cons = 0;
  vector<int> space_index;
  for (int i = 0; i < s.length(); ++i) {
    if (!isvowel[s[i]]) {
      if (last_cons_index == -1) {
        last_cons_index = i;
        len_cons = 1;
        cons.insert(s[i]);
      } else {
        if (len_cons >= 2) {
          if ((cons.size() > 1) || (cons.find(s[i]) == cons.end())) {
            space_index.push_back(i);
            last_cons_index = i;
            len_cons = 1;
            cons.clear();
            cons.insert(s[i]);
          } else {
            ++len_cons;
            cons.insert(s[i]);
          }
        } else {
          ++len_cons;
          cons.insert(s[i]);
        }
      }
    } else {
      last_cons_index = -1;
      len_cons = 0;
      cons.clear();
    }
  }

  vector<string> result;
  if (space_index.empty()) {
    cout << s << endl;
  } else {
    result.push_back(s.substr(0, space_index[0]));
    for (int i = 0; i < space_index.size() - 1; ++i) {
      result.push_back(s.substr(space_index[i], space_index[i + 1] - space_index[i]));
    }
    result.push_back(s.substr(space_index[space_index.size() - 1]));
    for (int i = 0; i < result.size(); ++i) {
      cout << result[i];
      if (i != result.size() - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }
}