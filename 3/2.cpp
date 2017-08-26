#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct vsi {
  int p;
  int id;
};

bool cmp_vs(const vsi& vs1, const vsi& vs2) {
  return vs1.p > vs2.p;
}

int main(int argc, char** argv) {
  int n;
  long v;
  scanf("%d", &n);
  scanf("%ld", &v);
  vector<vsi> vs1;
  vector<vsi> vs2;
  for (int i = 0; i < n; ++i) {
    int t, p;
    scanf("%d", &t);
    scanf("%d", &p);
    if (t == 1) {
      vs1.push_back({p, i + 1});
    } else {
      vs2.push_back({p, i + 1});
    }
  }
  sort(vs1.begin(), vs1.end(), cmp_vs);
  sort(vs2.begin(), vs2.end(), cmp_vs);
  int i1 = 0, i2 = 0;
  long capacity = 0;
  vector<int> ids;
  if (v % 2 != 0) {
    if (vs1.size() > 0) {
      ids.push_back(vs1[i1].id);
      capacity += vs1[i1].p;
      --v;
      ++i1;
    }
  }
  while ((v > 1) && (i1 + 1 < vs1.size() || i2 < vs2.size())) {
    long c1 = (i1 + 1 < vs1.size() ? vs1[i1].p + vs1[i1 + 1].p : -1);
    long c2 = (i2 < vs2.size() ? vs2[i2].p : -1);
    if (c1 > c2) {
      ids.push_back(vs1[i1].id);
      ids.push_back(vs1[i1 + 1].id);
      capacity += c1;
      i1 = i1 + 2;
      v -= 2;
    } else {
      ids.push_back(vs2[i2].id);
      capacity += c2;
      i2 = i2 + 1;
      v -= 2;
    }
  }
  if ((v > 0) && (i1 < vs1.size()) && (i2 >= vs2.size())) {
    ids.push_back(vs1[i1].id);
    capacity += vs1[i1].p;
    i1++;
    v -= 1;
  }
  printf("%ld\n", capacity);
  for (int i = 0; i < ids.size(); ++i) {
    printf("%d", ids[i]);
    if (i < ids.size() - 1) {
      printf(" ");
    }
  }
  printf("\n");
}