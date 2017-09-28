#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <list>
#include <stack>
#include <bitset>
#include <cmath>
#include <climits>
#include <cassert>

using namespace std;

template <typename T>
class Edge {
public:
  int u, v;
  T val;

  Edge(int _u, int _v, T& _val) : u(_u), v(_v), val(_val) {}
};

template <typename VT, typename ET>
class DGraph {
public:
  vector<pair<VT, list<Edge<ET>>>> adjs;

  DGraph(int n) : adjs(n) {}

  Edge<ET>* insert_edge(int u, int v, ET val) {
    assert(u >= 0 && u < adjs.size());
    assert(v >= 0 && v < adjs.size());
    adjs[u].second.emplace_back(Edge<ET>(u, v, val));
    return &(adjs[u].second.back());
  }

  void set_vertex_val(int v, VT val) {
    assert(v >= 0 && v < adjs.size());
    adjs[v].first = val;
  }
};

class MaxFlow {
public:
  struct EdgeInfo {
    long long cap, flow;
    Edge<EdgeInfo*>* reverse_edge;

    EdgeInfo(long long _cap, Edge<EdgeInfo*>* _reverse_edge)
      : cap(_cap), flow(0), reverse_edge(_reverse_edge) {}
  };

  list<EdgeInfo> edge_infos;
  DGraph<int, EdgeInfo*> graph;
  long long max_flow;

  MaxFlow(int n) : graph(n) {}

  virtual void find_augment_path(int s, int t, list<Edge<EdgeInfo*>>& result) = 0;
  virtual void init_computation(int s, int t) = 0;
  virtual void push_flow_on_edge(long long f, Edge<EdgeInfo*>& e) = 0;

  void compute_max_flow(int s, int t) {
    init_computation(s, t);

    max_flow = 0;
    list<Edge<EdgeInfo*>> path;

    while (true) {
      path.clear();
      find_augment_path(s, t, path);

      if (path.empty()) {
        break;
      }
      long long f = LLONG_MAX;
      for (const auto& e : path) {
        f = min(f, e.val->cap - e.val->flow);
      }
      for (auto& e : path) {
        e.val->flow += f;
        e.val->reverse_edge->val->flow -= f;
        push_flow_on_edge(f, e);
      }

      max_flow += f;
    }
  }

  virtual void insert_edge(int u, int v, long long cap) {
    assert(u != v);
    edge_infos.push_back(EdgeInfo(cap, NULL));
    Edge<EdgeInfo*>* e1 = graph.insert_edge(u, v, &(edge_infos.back()));
    edge_infos.push_back(EdgeInfo(0, NULL));
    Edge<EdgeInfo*>* e2 = graph.insert_edge(v, u, &(edge_infos.back()));
    e1->val->reverse_edge = e2;
    e2->val->reverse_edge = e1;
  }
};

class MinCostMaxFlow : public MaxFlow {
public:
  struct MinCostEdgeInfo : EdgeInfo {
    long long cost;

    MinCostEdgeInfo(long long _cap, long long _cost, Edge<EdgeInfo*>* _reverse_edge)
      : EdgeInfo(_cap, _reverse_edge), cost(_cost) {}
  };

  long long min_cost;
  list<MinCostEdgeInfo> min_cost_edge_infos;

  MinCostMaxFlow(int n) : MaxFlow(n) {}

  void find_augment_path(int s, int t, list<Edge<EdgeInfo*>>& result) override {
    int n = graph.adjs.size();
    vector<long long> d(n, LLONG_MAX);
    vector<Edge<EdgeInfo*>*> prev_edge(n);
    vector<bool> in_queue(n, false);
    queue<int> q;
    
    d[s] = 0;
    q.push(s);
    in_queue[s] = true;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      in_queue[u] = false;
      for (auto& e : graph.adjs[u].second) {
        MinCostEdgeInfo* edge_info = static_cast<MinCostEdgeInfo*>(e.val);
        if ((edge_info->flow < edge_info->cap) && (d[u] + edge_info->cost < d[e.v])) {
          d[e.v] = d[u] + edge_info->cost;
          prev_edge[e.v] = &e;
          if (!in_queue[e.v]) {
            q.push(e.v);
            in_queue[e.v] = true;
          }
        }
      }
    }

    if (d[t] != LLONG_MAX) {
      for (int cur_v = t; cur_v != s; cur_v = prev_edge[cur_v]->u) {
        result.push_front(*(prev_edge[cur_v]));
      }
    }
  }

  void init_computation(int s, int t) override {
    min_cost = 0;
  }

  void push_flow_on_edge(long long f, Edge<EdgeInfo*>& e) override {
    min_cost += f * (static_cast<MinCostEdgeInfo*>(e.val))->cost;
  }

  void insert_edge(int u, int v, long long cap) override {
    assert(false);
  }

  void insert_edge(int u, int v, long long cap, long long cost) {
    assert(u != v);
    min_cost_edge_infos.push_back(MinCostEdgeInfo(cap, cost, NULL));
    Edge<EdgeInfo*>* e1 = graph.insert_edge(u, v, &(min_cost_edge_infos.back()));
    min_cost_edge_infos.push_back(MinCostEdgeInfo(0, -cost, NULL));
    Edge<EdgeInfo*>* e2 = graph.insert_edge(v, u, &(min_cost_edge_infos.back()));
    e1->val->reverse_edge = e2;
    e2->val->reverse_edge = e1;
  }
};

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int min_x[50];
  int max_x[50];
  int cnt[50];
  int n;
  int q;

  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    min_x[i] = 1;
    max_x[i] = n;
    cnt[i] = 0;
  }
  for (int i = 0; i < q; ++i) {
    int t, l, r, v;
    cin >> t >> l >> r >> v;
    --l;
    --r;
    if (t == 1) {
      for (int j = l; j <= r; ++j) {
        min_x[j] = max(min_x[j], v);
      }
    } else {
      for (int j = l; j <= r; ++j) {
        max_x[j] = min(max_x[j], v);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (min_x[i] > max_x[i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  MinCostMaxFlow mcmf(2 * n + 2);
  for (int i = 1; i <= n; ++i) {
    for (int j = min_x[i - 1]; j <= max_x[i - 1]; ++j) {
      mcmf.insert_edge(j, i + n, 1, 0);
      ++cnt[j - 1];
    }
    mcmf.insert_edge(i + n, 2 * n + 1, 1, 0);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= cnt[i - 1]; ++j) {
      mcmf.insert_edge(0, i, 1, 2 * j - 1);
    }
  }
  mcmf.compute_max_flow(0, 2 * n + 1);
  cout << mcmf.min_cost << endl;
}