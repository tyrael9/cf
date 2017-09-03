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

struct dancer {
  long id;
  long delay;
  long pos;
};

long n, w, h;

bool cmp_dancer(const dancer& d1, const dancer& d2) {
  return d1.pos < d2.pos;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n >> w >> h;

  vector<dancer> hdancers;
  vector<dancer> vdancers;
  for (long i = 1; i <= n; ++i) {
    long g, p, t;
    cin >> g >> p >> t;
    if (g == 1) {
      vdancers.push_back({i, t, p});
    } else {
      hdancers.push_back({i, t, p});
    }
  }
  sort(hdancers.begin(), hdancers.end(), cmp_dancer);
  sort(vdancers.begin(), vdancers.end(), cmp_dancer);
  map<int, deque<long>> groups_pos;
  map<int, deque<long>> groups;
  for (const auto& d : vdancers) {
    groups_pos[d.pos - d.delay].push_back(d.pos);
    groups[d.pos - d.delay].push_back(d.id);
  }

  vector<pair<long, long>> result(n + 1);
  for (const auto& hd : hdancers) {
    long delta = hd.pos - hd.delay;
    if (groups.find(delta) == groups.end()) {
      result[hd.id] = {w, hd.pos};
    } else {
      result[groups[delta].back()] = {w, hd.pos};
      groups[delta].pop_back();
      groups[delta].push_front(hd.id);
    }
  }

  for (const auto& p : groups) {
    auto it = p.second.begin();
    auto it_pos = groups_pos[p.first].begin();
    while (it != p.second.end()) {
      result[*it] = {*it_pos, h};
      ++it;
      ++it_pos;
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << result[i].first << " " << result[i].second << "\n";
  }
}