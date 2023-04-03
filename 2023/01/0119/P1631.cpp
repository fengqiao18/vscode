#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N];
priority_queue<int, vector<int>, greater<int> > pq;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n && (i - 1) * (j - 1) <= n; j++) {
      pq.push(a[i] + b[j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << pq.top() << " ";
    pq.pop();
  }
  return 0;
}