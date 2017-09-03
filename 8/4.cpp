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
#include <stdio.h>
#include <cmath>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

const double EPS = 1e-12;

using namespace std;

int t1, t2, xc, yc, xh, yh, xs, ys;

struct point {
  double x;
  double y;
};

struct circle {
  double x;
  double y;
  double r;
};

int get_deviation(double a, double b) {
  double delta = a - b;
  if (abs(delta) < EPS) return 0;
  return (delta > 0 ? 1 : -1);
}

vector<point> intersect(circle &c1, circle &c2) {
  vector<point> result;
  double d = sqrt((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y));
  if ((get_deviation(d, c1.r + c2.r) > 0) || (get_deviation(d, abs(c1.r - c2.r)) < 0)) {
    return result;
  }
  double angle;
  if (get_deviation(c1.y, c2.y) == 0) {
    if (c1.x < c2.x) {
      angle = 0;
    } else {
      angle = M_PI;
    }
  } else if (get_deviation(c1.x, c2.x) == 0) {
    if (c1.y < c2.y) {
      angle = 0.5 * M_PI;
    } else {
      angle = 1.5 * M_PI;
    }
  } else {
    if (c1.x < c2.x) {
      angle = atan((double)(c2.y - c1.y) / (double)(c2.x - c1.x));
    } else {
      angle = M_PI + atan((double)(c2.y - c1.y) / (double)(c2.x - c1.x));
    }
  }
  if ((get_deviation(d, c1.r + c2.r) == 0) || (get_deviation(d, abs(c1.r - c2.r)) == 0)) {
    result.push_back({c1.x + c1.r * cos(angle), c1.y + c1.r * sin(angle)});
    return result;
  }
  double s = 0.5 * (d + c1.r + c2.r);
  double area = sqrt(s * (s - d) * (s - c1.r) * (s - c2.r));
  double h = 2.0 * area / d;
  double angle_h = asin(h / c1.r);
  result.push_back({c1.x + c1.r * cos(angle + angle_h), c1.y + c1.r * sin(angle + angle_h)});
  result.push_back({c1.x + c1.r * cos(angle - angle_h), c1.y + c1.r * sin(angle - angle_h)});
  return result;
}

bool any_in_circle(vector<point> points, circle &c) {
  for (const auto& p : points) {
    if (get_deviation((p.x - c.x) * (p.x - c.x) + (p.y - c.y) * (p.y - c.y), c.r * c.r) <= 0) {
      return true;
    }
  }
  return false;
}

bool circle_in_circle(circle &c1, circle &c2) {
  if (get_deviation(c1.r, c2.r) > 0) {
    return false;
  }
  double d = sqrt((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y));
  return get_deviation(d, abs(c1.r - c2.r)) <= 0;
}

bool intersect_all_circles(circle cirs[3]) {
  return (circle_in_circle(cirs[0], cirs[1]) && circle_in_circle(cirs[0], cirs[2])) || 
         (circle_in_circle(cirs[1], cirs[0]) && circle_in_circle(cirs[1], cirs[2])) ||
         (circle_in_circle(cirs[2], cirs[0]) && circle_in_circle(cirs[2], cirs[1])) ||
         any_in_circle(intersect(cirs[0], cirs[1]), cirs[2]) ||
         any_in_circle(intersect(cirs[0], cirs[2]), cirs[1]) ||
         any_in_circle(intersect(cirs[1], cirs[2]), cirs[0]);
}

int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);

  cin >> t1 >> t2;
  cin >> xc >> yc;
  cin >> xh >> yh;
  cin >> xs >> ys;

  double s_ch = sqrt((xc - xh) * (xc - xh) + (yc - yh) * (yc - yh));
  double s_cs = sqrt((xc - xs) * (xc - xs) + (yc - ys) * (yc - ys));
  double s_sh = sqrt((xh - xs) * (xh - xs) + (yh - ys) * (yh - ys));
  double result;

  if (s_cs + s_sh > s_ch + t2) {
    circle cirs[3];
    cirs[0].x = (double)xc;
    cirs[0].y = (double)yc;
    cirs[1].x = (double)xs;
    cirs[1].y = (double)ys;
    cirs[2].x = (double)xh;
    cirs[2].y = (double)yh;
    double r1 = (double)t1 + s_cs;
    double r2 = (double)t2 + s_ch;
    double l = 0, r = min(r1, r2);
    while (get_deviation(l, r) < 0) {
      double mid = 0.5 * (l + r);
      cirs[0].r = mid;
      cirs[1].r = r1 - mid;
      cirs[2].r = r2 - mid;
      if (!intersect_all_circles(cirs)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    result = l;
  } else {
    result = min(s_cs + s_sh + (double)t1, s_ch + (double)t2);
  }
  std::cout.precision(12);
  cout << std::fixed << result << endl;
}