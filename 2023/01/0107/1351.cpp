#include <bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int> v[N];
queue<int> q;
int in[N];
int n;
inline void topu() {
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    cout << cur << " ";
    for (int i = 0; i < v[cur].size(); i++) {
      int t = v[cur][i];
      in[t]--;
      if (in[t] == 0) {
        q.push(t);
      }
    }
  }
  return;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    while (cin >> x) {
      if (x == 0) {
        break;
      }
      v[i].push_back(x);
      in[x]++;
    }
  }
  topu();
  return 0;
}