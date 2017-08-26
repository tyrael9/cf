#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>

using namespace std;

int main(int argc, char** argv) {
  int n, x;
  int l, r;
  long cost;
  map<int, map<long, list<int>>> l_by_duration_cost;
  map<int, map<int, long>> cost_by_r_duration;
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    cin >> l >> r >> cost;
    int duration = r - l + 1;
    l_by_duration_cost[duration][cost].push_back(l);
    if (cost_by_r_duration[r].find(duration) == cost_by_r_duration[r].end()) {
      cost_by_r_duration[r][duration] = cost;
    } else {
      cost_by_r_duration[r][duration] = min(cost_by_r_duration[r][duration], cost);
    }
  }
  for (auto& p : l_by_duration_cost) {
    for (auto& pp : p.second) {
      pp.second.sort();
    }
  }
  long min_cost = -1;
  for (const auto& p : cost_by_r_duration) {
    r = p.first;
    for (const auto& pp : p.second) {
      int duration = pp.first;
      int rem_dur = x - duration;
      while (l_by_duration_cost.find(rem_dur) != l_by_duration_cost.end()) {
        while (!l_by_duration_cost[rem_dur].empty()) {
          long cur_cost = l_by_duration_cost[rem_dur].begin()->first;
          list<int>& l_set = l_by_duration_cost[rem_dur].begin()->second;
          while (!l_set.empty()) {
            int cur_l = *l_set.begin();
            if (cur_l <= r) {
              l_set.pop_front();
            } else {
              break;
            }
          }
          if (l_set.empty()) {
            l_by_duration_cost[rem_dur].erase(cur_cost);
          } else {
            break;
          }
        }
        if (l_by_duration_cost[rem_dur].empty()) {
          l_by_duration_cost.erase(rem_dur);
        } else {
          break;
        }
      }
      if (l_by_duration_cost.find(rem_dur) != l_by_duration_cost.end()) {
        long total_cost = pp.second + l_by_duration_cost[rem_dur].begin()->first;
        if (min_cost < 0) {
          min_cost = total_cost;
        } else {
          min_cost = min(min_cost, total_cost);
        }
      }
    }
  }
  cout << min_cost << endl;
}