#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], L[N];
stack<int> stk;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    while (!stk.empty() && a[stk.top()] < a[i]) {
      L[stk.top()] = i;
      stk.pop();
    }
    stk.push(i);
  }
  for (int i = 1; i <= n; i++) {
    cout << L[i] << endl;
  }
  return 0;
}