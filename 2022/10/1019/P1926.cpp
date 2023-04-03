#include <bits/stdc++.h>
using namespace std;

const int N = 15;
struct node {
  int score, time;
};

node hw[N];
int n, m, k, r;
int a[N], mini = 1e9;

void dfs(int cur, int time, int sum) {
  if (time > r) {
    return;
  }
  if (sum > k) {
    mini = min(mini, time);
    return;
  }
  if (cur == m + 1) {
    return;
  }
  dfs(cur + 1, time, sum);
  dfs(cur + 1, time + hw[cur].time, sum + hw[cur].score);
  return;
}

int main() {
  cin >> n >> m >> k >> r;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> hw[i].time;
  }
  for (int i = 1; i <= m; i++) {
    cin >> hw[i].score;
  }
  sort(a + 1, a + 1 + n);
  dfs(1, 0, 0);
  if (mini == (int)1e9) {
    cout << 0;
    return 0;
  }
  int cnt = 1;
  while (cnt <= n && a[cnt] + mini <= r) {
    mini += a[cnt], cnt++;
  }
  cout << cnt - 1;
  return 0;
}