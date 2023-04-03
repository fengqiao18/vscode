#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], v[N];
int dfs(int i) {
  if (v[i] > 0) {
    return v[i];
  }
  return v[i] = dfs(a[i]) + 1;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int s;
  for (s = 1; v[s] == 0; s = a[s]) {
    v[s] = 1;
    // cout<<s<<endl;
  }
  // cout<<"dfagwteh";
  for (int i = 1; i != s; i = a[i]) {
    v[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    v[i] = dfs(i);
    cout << v[i] - 1 << " ";
  }
  return 0;
}