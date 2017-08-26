#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int main(int argc, char** argv) {
  string s1, s2;
  cin >> s1 >> s2;
  int dx = s2[0] - s1[0];
  int dy = s2[1] - s1[1];
  cout << max(abs(dx), abs(dy)) << endl;
  while ((dx != 0) || (dy != 0)) {
    if ((dx != 0) && (dy != 0)) {
      if (dx > 0) {
        if (dy > 0) {
          cout << "RU" << endl;
          --dx;
          --dy;
        } else {
          cout << "RD" << endl;
          --dx;
          ++dy;
        }
      } else {
        if (dy > 0) {
          cout << "LU" << endl;
          ++dx;
          --dy;
        } else {
          cout << "LD" << endl;
          ++dx;
          ++dy;
        }
      }
    } else if (dx == 0) {
      if (dy > 0) {
        cout << "U" << endl;
        --dy;
      } else {
        cout << "D" << endl;
        ++dy;
      }
    } else {
      if (dx > 0) {
        cout << "R" << endl;
        --dx;
      } else {
        cout << "L" << endl;
        ++dx;
      }
    }
  }
}