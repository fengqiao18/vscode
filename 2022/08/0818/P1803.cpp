#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct node {
  int start, end;
};
node a[N];
bool cmp(node x, node y) {
  return x.end < y.end;
}
int main() {
  int n, last = 1, cnt = 1;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i].start >> a[i].end;
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 2; i <= n; i++)
    if (a[i].start >= a[last].end) {
      cnt++;
      last = i;
    }
  cout << cnt;
  return 0;
}