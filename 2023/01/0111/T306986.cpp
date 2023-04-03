#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
struct node {
  int d, v;
  int happy;
};
node a[N];
bool cmp(node x, node y) {
  return x.happy > y.happy;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].d;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].v;
  }
  int happy = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[j].happy = a[j].d - (i - 1) * a[j].v;
    }
    sort(a + 1, a + 1 + n, cmp);
    int cnt = 0;
    for (int j = 1; j <= i; j++) {
      cnt += a[j].happy;
    }
    if (cnt >= happy) {
      happy = cnt;
      ans = i;
    }
  }
  cout << happy << "\n"
       << ans;
  return 0;
}