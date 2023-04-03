#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int V, G, mini = 1e9;
int v[N], g[N][N], w[N];
int food = 1e9, ans[N], tmp[N];
bool check(int cur) {
  if (cur > mini) {
    return 0;
  }
  int sum = 0;
  for (int i = 1; i <= V; i++) {
    if (w[i] < v[i]) {
      return 0;
    }
    sum += w[i];
  }
  if (cur == mini && sum > food) {
    return 0;
  }
  mini = cur, food = sum;
  return 1;
}
void update() {
  for (int i = 1; i <= mini; i++) {
    ans[i] = tmp[i];
  }
  return;
}
void add(int flag, int t) {
  for (int i = 1; i <= V; i++) {
    w[i] += g[t][i] * flag;
  }
  return;
}
void dfs(int cur) {
  if (check(cur - 1)) {
    update();
    return;
  }
  if (cur == G + 1) {
    return;
  }
  for (int i = tmp[cur - 1] + 1; i <= G; i++) {
    tmp[cur] = i;
    add(1, i);
    dfs(cur + 1);
    add(-1, i);
  }
  return;
}
int main() {
  cin >> V;
  for (int i = 1; i <= V; i++) {
    cin >> v[i];
  }
  cin >> G;
  for (int i = 1; i <= G; i++) {
    for (int j = 1; j <= V; j++) {
      cin >> g[i][j];
    }
  }
  dfs(1);
  cout << mini << " ";
  for (int i = 1; i <= mini; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}