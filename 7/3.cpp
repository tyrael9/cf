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

long long gcd(long long A, long long B, long long *X, long long *Y) {
  if (B == 0) {
    *X = 1;
    *Y = 0;
    return A;
  } else {
    long long r = gcd(B, A % B, X, Y);
    long long t = *X;
    *X = *Y;
    *Y = t - A / B * (*Y);
    return r;
  }
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  long long A, B, C;
  cin >> A >> B >> C;
  long long X, Y, G;
  if (A == 0) {
    if (abs(C) % abs(B) == 0) {
      cout << "0 " << (-C / B) << "\n";
    } else {
      cout << "-1\n";
    }
    return 0;
  }
  if (B == 0) {
    if (abs(C) % abs(A) == 0) {
      cout << (-C / A) << " 0" << "\n";
    } else {
      cout << "-1\n";
    }
    return 0;
  }
  long long signA = A >= 0 ? 1 : -1;
  long long signB = B >= 0 ? 1 : -1;
  long long signC = C >= 0 ? 1 : -1;
  G = gcd(abs(A), abs(B), &X, &Y);
  if (abs(C) % G != 0) {
    cout << "-1\n";
    return 0;
  }
  long long K = abs(C) / G;
  long long M = X * K, N = Y * K;
  cout << M * signA * -signC << " " << N * signB * -signC << endl;
  return 0;
}