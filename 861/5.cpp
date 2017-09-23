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
#include <sstream>

using namespace std;

int n = 0, e = 0;
set<int> a_e;
set<int> a_n;

set<int> n_at_e;
set<int> e_at_n;
bool occupied[300000];

vector<pair<string, int>> files;

int is_good_file(const string& s, bool is_e, int &real_val) {
  if (s[0] == '0') {
    return -1;
  }
  if (s.length() > 6) {
    return -1;
  }
  int cur = 0;
  for (char c : s) {
    if ((c < '0') || (c > '9')) {
      return -1;
    }
    cur *= 10;
    cur += c - '0';
  }
  real_val = cur;
  if (cur > n) {
    return -1;
  }
  if (is_e) {
    return (cur <= e ? cur : -3);
  } else {
    return (cur > e ? cur : -4);
  }
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string name;
    int type;
    cin >> name >> type;
    files.push_back({name, type});
    if (type == 1) {
      ++e;
    }
  }

  for (int i = 1; i <= e; ++i) {
    a_e.insert(i);
  }
  for (int i = e + 1; i <= n; ++i) {
    a_n.insert(i);
  }
  int total_move_count = 0;
  for (int i = 0; i < files.size(); ++i) {
    int real_val;
    int val = is_good_file(files[i].first, files[i].second == 1, real_val);
    if ((val != -1) && (real_val < 300000)) {
      occupied[real_val] = true;
    }
    if (val > 0) {
      files[i].second = 2;
      if (val <= e) {
        a_e.erase(val);
      } else {
        a_n.erase(val);
      }
    } else if (val == -3) {
      e_at_n.insert(real_val);
      a_n.erase(real_val);
      files[i].second = 2;
      ++total_move_count;
    } else if (val == -4) {
      n_at_e.insert(real_val);
      a_e.erase(real_val);
      files[i].second = 2;
      ++total_move_count;
    } else {
      ++total_move_count;
    }
  }

  bool spaced = false;
  int target;
  int source;
  if (a_e.size() == 0 && a_n.size() == 0 && n_at_e.size() > 0) {
    spaced = true;
    int ei = *n_at_e.begin();
    source = ei;
    n_at_e.erase(ei);
    a_e.insert(ei);

    for (int i = 100001; i < 300000; ++i) {
      if (!occupied[i]) {
        target = i;
        break;
      }
    }

    ++total_move_count;
    cout << total_move_count << endl;
    cout << "move " << ei << " " << target << endl;
  } else {
    cout << total_move_count << endl;
  }

  while (n_at_e.size() != 0 || e_at_n.size() != 0) {
    if ((e_at_n.size() != 0) && (a_e.size() != 0)) {
      int ni = *e_at_n.begin();
      int ei = *a_e.begin();
      cout << "move " << ni << " " << ei << endl;
      e_at_n.erase(ni);
      a_n.insert(ni);
      a_e.erase(ei);
    }
    if ((n_at_e.size() != 0) && (a_n.size() != 0)) {
      int ei = *n_at_e.begin();
      int ni = *a_n.begin();
      cout << "move " << ei << " " << ni << endl;
      n_at_e.erase(ei);
      a_e.insert(ei);
      a_n.erase(ni);
    }
  }

  if (spaced) {
    int ni = *a_n.begin();
    cout << "move " << target << " " << ni << endl;
    a_n.erase(ni);
  }

  for (int i = 0; i < files.size(); ++i) {
    if (files[i].second != 2) {
      if (files[i].second == 1) {
        int target = *a_e.begin();
        a_e.erase(target);
        cout << "move " << files[i].first << " " << target << endl;
      } else {
        int target = *a_n.begin();
        a_n.erase(target);
        cout << "move " << files[i].first << " " << target << endl;
      }
    }
  }
}