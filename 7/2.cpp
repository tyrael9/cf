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

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int t, m;
  cin >> t >> m;
  int used = 0;
  map<int, int> u;
  map<int, int> id_to_start;
  int cur_id = 1;
  for (int i = 0; i < t; ++i) {
    string s;
    int x;
    cin >> s;
    if (s == "alloc") {
      cin >> x;
      auto cur = u.begin();
      if ((u.empty() && (x <= m)) || (!u.empty() && x <= cur->first)) {
        cout << cur_id << "\n";
        id_to_start[cur_id++] = 0;
        u[0] = x;
        used += x;
      } else {
        while (cur != u.end()) {
          auto next_cur = cur;
          ++next_cur;
          int next = ((next_cur == u.end()) ? m : (next_cur->first));
          if (cur->first + cur->second + x <= next) {
            break;
          }
          ++cur;
        }
        if (cur != u.end()) {
          cout << cur_id << "\n";
          id_to_start[cur_id++] = cur->first + cur->second;
          u[cur->first + cur->second] = x;
          used += x;
        } else {
          cout << "NULL" << "\n";
        }
      }
      
    } else if (s == "erase") {
      cin >> x;
      if (id_to_start.find(x) == id_to_start.end()) {
        cout << "ILLEGAL_ERASE_ARGUMENT" << "\n";
      } else {
        used -= u[id_to_start[x]];
        u.erase(id_to_start[x]);
        id_to_start.erase(x);
      }
    } else if (s == "defragment") {
      map<int, int> tmp;
      map<int, int> start_to_id;
      for (const auto& p : id_to_start) {
        start_to_id[p.second] = p.first;
      }
      id_to_start.clear();
      int cur_addr = 0;
      for (const auto& p : u) {
        id_to_start[start_to_id[p.first]] = cur_addr;
        tmp[cur_addr] = p.second;
        cur_addr += p.second;
      }
      u = tmp;
    }
  }
}