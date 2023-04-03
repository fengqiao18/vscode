#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int a[N], cnt[N];
int helper() {
  int n, mini = 1e9, pos = -1;
  cin >> n;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for (int i = 1; i <= n; i++)
    if (cnt[a[i]] == 1 && a[i] < mini) {
      mini = a[i];
      pos = i;
    }
  return pos;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << helper() << endl;
  }
  return 0;
}