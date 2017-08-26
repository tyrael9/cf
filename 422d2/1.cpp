#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char** argv) {
  long long A, B;
  cin >> A >> B;
  if (A < B) {
    long long tmp = A;
    A = B;
    B = tmp;
  }
  long long result = 1;
  for (long long i = 1; i <= B; ++i) {
    result = result * i;
  }
  cout << result << endl;
}