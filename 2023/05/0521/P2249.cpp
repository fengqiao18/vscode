#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
int n, m;
int erfen(int x) {
  int lt = 0, rt = n + 1;
  while(lt + 1 < rt){
    int mid = (lt + rt) >> 1;
    if(a[mid] >= x){
      rt = mid;
    }
    else{
      lt = mid;
    }
  }
  return (a[rt] == x ? rt : -1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    int q;
    cin >> q;
    cout << erfen(q) << " ";
  }
  return 0;
}