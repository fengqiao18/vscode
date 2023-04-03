#include <bits/stdc++.h>
#define ll long long
#define gc() getchar()
using namespace std;
inline ll read() {
  ll x = 0, f = 1;
  char ch = gc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = gc();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - 48;
    ch = gc();
  }
  return x * f;
}
const int inf = 1e9;
const int N = 1e6 + 5;
bool vis[N];
int main() {
  int n = read(), maxi = -inf, mini = inf;
  for (int i = 1; i <= n; i++) {
    int l = read(), r = read();
    maxi = max(maxi, r);
    mini = min(mini, l);
    for (int i = l; i < r; i++) {
      vis[i] = 1;
    }
  }
  int mx = -inf, len = 0;
  for (int i = mini; i <= maxi; i++) {
    if (vis[i] == 1) {
      len++;
    } else {
      mx = max(mx, len);
      len = 0;
    }
  }
  mx = max(mx, len);
  cout << mx << " ";
  mx = -inf, len = 0;
  for (int i = mini; i <= maxi; i++) {
    if (vis[i] == 0) {
      len++;
    } else {
      mx = max(mx, len);
      len = 0;
    }
  }
  mx = max(mx, len);
  cout << mx;
  return 0;
}