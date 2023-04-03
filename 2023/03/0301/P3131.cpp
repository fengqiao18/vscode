#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
int a[N], sum[N];
int lt[7], rt[7];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = (sum[i - 1] + a[i]) % 7;
    if (lt[sum[i]] == 0){
      lt[sum[i]] = i;
    }
    rt[sum[i]] = i;
  }
  lt[0] = 0;
  int maxi = 0;
  for (int i = 0; i < 7; i++){
    maxi = max(maxi, rt[i] - lt[i]);
  }
  cout << maxi;
  return 0;
}