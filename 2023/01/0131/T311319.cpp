#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N];
priority_queue<int> pq;
signed main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    pq.push(x);
  }
  for(int i = 1 ; i < n ; i++){
    int x = pq.top();
    pq.pop();
    int y = pq.top();
    pq.pop();
    int tmp = (x + y) / k;
    pq.push(tmp);
  }
  cout<<pq.top();
  return 0;
}