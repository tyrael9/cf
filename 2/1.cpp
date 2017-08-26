#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int main(int argc, char** argv) {
  int n;
  cin >> n;
  vector<pair<string, int>> history;
  for (int i = 0; i < n; ++i) {
    string name;
    int score;
    cin >> name >> score;
    history.push_back({name, score});
  }
  map<string, long long> scores;
  for (int i = 0; i < history.size(); ++i) {
    scores[history[i].first] += history[i].second;
  }
  long long max_score = scores.begin()->second;
  for (const auto& p : scores) {
    max_score = max(max_score, p.second);
  }
  map<string, long long> scores_2;
  for (int i = 0; i < history.size(); ++i) {
    scores_2[history[i].first] += history[i].second;
    if ((scores[history[i].first] >= max_score) && (scores_2[history[i].first] >= max_score)) {
      cout << history[i].first << endl;
      break;
    }
  }
}