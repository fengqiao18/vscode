#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int fa[N];
inline int find(int x) {
  if (fa[x] == x) {
    return x;
  }
  printf("%d ", fa[x]);
  return find(fa[x]);
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    fa[y] = x;
  }
  int x;
  cin >> x;
  find(x);
  return 0;
}