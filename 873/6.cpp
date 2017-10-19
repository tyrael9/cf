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
#include <string.h>

using namespace std;

template<typename T, int SZ_ALPHABET>
class SuffixAutomaton {
public:
  struct State {
    int len;
    int next[SZ_ALPHABET];
    int next_keys[SZ_ALPHABET];
    int num_nexts;
    int parent;
    T val;
    bool is_clone;
  };

  int last;
  int size;
  vector<State> states;

  SuffixAutomaton(int n) : states(2 * n) {}

  void init() {
    last = 0;
    size = 0;
    states[0].len = 0;
    states[0].parent = -1;
    ++size;
  }

  void extend(int c, T val) {
    int p = last;
    int cur = size;
    ++size;
    states[cur].len = states[p].len + 1;
    states[cur].val = val;
    while (p != -1) {
      if (states[p].next[c] != 0) {
        break;
      }
      states[p].next[c] = cur;
      states[p].next_keys[states[p].num_nexts] = c;
      ++states[p].num_nexts;
      p = states[p].parent;
    }
    if (p == -1) {
      states[cur].parent = 0;
    } else {
      int q = states[p].next[c];
      if (states[p].len + 1 == states[q].len) {
        states[cur].parent = q;
      } else {
        int clone_q = size;
        ++size;

        states[clone_q].len = states[p].len + 1;
        for (int i = 0; i < states[q].num_nexts; ++i) {
          int next_key = states[q].next_keys[i];
          states[clone_q].next_keys[i] = next_key;
          states[clone_q].next[next_key] = states[q].next[next_key];
        }
        states[clone_q].num_nexts = states[q].num_nexts;
        states[clone_q].parent = states[q].parent;
        states[clone_q].val = states[q].val;
        states[clone_q].is_clone = true;

        states[q].parent = clone_q;
        states[cur].parent = clone_q;
        while (p != -1) {
          if (states[p].next[c] != q) {
            break;
          }
          states[p].next[c] = clone_q;
          p = states[p].parent;
        }
      }
    }
    last = cur;
  }
};

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  int n;
  string s;
  string t;
  cin >> n;
  cin >> s;
  cin >> t;

  SuffixAutomaton<int, 26> *sam = new SuffixAutomaton<int, 26>(n);
  sam->init();
  for (int i = 0; i < n; ++i) {
    sam->extend(s[i] - 'a', t[i] == '0' ? 1 : 0);
  }
  vector<vector<SuffixAutomaton<int, 26>::State*>> v(n + 1);
  for (int i = 0; i < sam->size; ++i) {
    if (sam->states[i].is_clone) {
      sam->states[i].val = 0;
    }
    v[sam->states[i].len].push_back(&(sam->states[i]));
  }
  for (int i = n; i >= 0; --i) {
    for (const auto sp : v[i]) {
      sam->states[sp->parent].val += sp->val;
    }
  }
  long long result = 0;
  for (int i = n; i >= 0; --i) {
    for (const auto sp : v[i]) {
      result = max(result, ((long long)(sp->len)) * ((long long)(sp->val)));
    }
  }
  cout << result << "\n";
}