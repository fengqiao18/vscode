#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 5;
int fa[N];
struct node {
  double x, y, z;
};
node a[N];
inline double f(double x) { return x * x; } 
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); };
inline int unionn(int x, int y) { return x = find(x), y = find(y), fa[x] = x != y ? y : fa[x]; }
inline double dis(int i, int j) { return sqrt(f(a[i].x - a[j].x) + f(a[i].y - a[j].y) + f(a[i].z - a[j].z)); }  
inline bool helper(int n, double h, double r) {
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y >> a[i].z;
  }
  for (int i = 1; i <= n + 2; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (dis(i, j) <= 2 * r) {  
        unionn(i, j);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i].z <= r) { 
      unionn(i, n + 1);
    }
    if (a[i].z + r >= h) {  
      unionn(i, n + 2);
    }
  }
  return find(n + 1) == find(n + 2);
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    double h, r;
    cin >> n >> h >> r;
    cout << (helper(n, h, r) ? "Yes" : "No") << endl;
  }
  return 0;
}