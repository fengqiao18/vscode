#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5;
int a[N], b[N];
struct node {
  int num, vis;
};
stack<node> stk;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = n; i >= 1; i--) {
    while (!stk.empty() && stk.top().num <= a[i]) {
      stk.pop();
    }
    if (stk.empty()) {
      b[i] = 0;
    } else {
      b[i] = stk.top().vis;
    }
    stk.push((node){a[i], i});
  }
  for (int i = 1; i <= n; i++) {
    cout << b[i] << " ";
  }
  return 0;
}