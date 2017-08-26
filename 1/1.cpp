#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  long long n, m, a;
  long long result;
  cin >> n >> m >> a;
  cout << ((n + (a - 1)) / a) * ((m + (a - 1)) / a) << endl;
}