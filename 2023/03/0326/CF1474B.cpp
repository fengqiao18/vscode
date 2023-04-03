#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
bool vis[N];
inline void init(int n) {
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      for (int j = i + i; j <= n; j += i){
        vis[j] = true;
      }
    }
  }
  return;
}
int main() {
  init(3e5);
  int t;
  cin >> t;
  while (t--) {
    int a, i, j;
    cin >> a;
    for (i = 1 + a; vis[i]; i++) {
    }
    for (j = i + a; vis[j]; j++) {
    }
    cout << i * j << endl;
  }
  return 0;
}
