#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
int n, in[N], dp[N], a[N];
vector<int> nbr[N];
queue<int> q;
void topo() {
  for (int i = 1; i <= n; i++) {
    dp[i] = a[i];
    if (in[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < nbr[cur].size(); i++) {
      int nxt = nbr[cur][i];
      dp[nxt] = max(dp[nxt], dp[cur] + a[nxt]);
      in[nxt]--;
      if (in[nxt] == 0) {
        q.push(nxt);
      }
    }
  }
  return;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, id;
    cin >> id >> a[i];
    while (cin >> x) {
      if (x == 0) {
        break;
      }
      in[i]++;
      nbr[x].push_back(i);
    }
  }
  topo();
  int maxi = -1e9;
  for (int i = 1; i <= n; i++) {
    maxi = max(maxi, dp[i]);
  }
  cout << maxi;
  return 0;
}