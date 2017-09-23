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

long long n, k, m, a;
long long g[100];

struct candinfo {
  int index;
  int numvote;
  int lastvote;
};

pair<int, int> cands[100];
vector<candinfo> cv;
int result[100];

bool cmp_cand(const candinfo& c1, const candinfo& c2) {
  if (c1.numvote != c2.numvote) {
    return c1.numvote < c2.numvote;
  }
  return c1.lastvote > c2.lastvote;
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> n >> k >> m >> a;
  for (int i = 0; i < a; ++i) {
    int voted;
    cin >> voted;
    ++cands[voted - 1].first;
    cands[voted - 1].second = i + 1;
  }

  for (int i = 0; i < n; ++i) {
    candinfo ci;
    ci.index = i;
    ci.numvote = cands[i].first;
    ci.lastvote = cands[i].second;
    cv.push_back(ci);
  }
  sort(cv.begin(), cv.end(), cmp_cand);
  const int rem_vote = m - a;
  for (int i = 0; i < cv.size(); ++i) {
    int final_vote = cv[i].numvote + rem_vote;
    if (final_vote == 0) {
      result[cv[i].index] = 3;
      continue;
    }
    int better = 0;
    for (int j = i + 1; j < cv.size(); ++j) {
      if (cv[j].numvote >= final_vote) {
        ++better;
      }
    }
    if (better > k - 1) {
      result[cv[i].index] = 3;
    }
  }

  for (int i = cv.size() - 1; i >= 0; --i) {
    int final_vote = cv[i].numvote;
    if (final_vote == 0) {
      continue;
    }
    int cur_rem_vote = rem_vote;
    int better = 0;
    for (int j = i - 1; j >= 0; --j) {
      if (cur_rem_vote <= 0) {
        break;
      }
      if (final_vote + 1 > cv[j].numvote) {
        cur_rem_vote -= (final_vote + 1 - cv[j].numvote);
      }
      if (cur_rem_vote >= 0) {
        better++;
      }
    }
    if (better + (cv.size() - 1 - i) <= k - 1) {
      result[cv[i].index] = 1;
    }
  }

  for (int i = 0; i < n; ++i) {
    if ((result[i] != 1) && (result[i] != 3)) {
      cout << 2;
    } else {
      cout << result[i];
    }
    if (i != n - 1) {
      cout << " ";
    }
  }
  cout << endl;
}