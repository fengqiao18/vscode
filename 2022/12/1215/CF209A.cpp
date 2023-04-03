#include <bits/stdc++.h>
using namespace std;
const int p = 1e9 + 7;
const int N = 1e6 + 5;
int dp[N], f[N];
int main() {
  int n;
  cin>>n;
  dp[1] = 1;
  for (int i = 2; i <= n; i++){
    if (i & 1){
      dp[i] = (dp[i - 2] + f[i - 1] + 1) % p;
    }
    else{
      f[i] = (f[i - 2] + dp[i - 1] + 1) % p;
    }
  }
  cout << (dp[n] + f[n] + dp[n - 1] + f[n - 1]) % p;
  return 0;
}