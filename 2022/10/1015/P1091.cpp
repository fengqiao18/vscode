#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N] , dp[N] , f[N];
int main(){
  int n;
  cin>>n;
  for(int i = 1 ; i <= n ; i++){
    cin>>a[i];
  }
  for(int i = 1 ; i <= n ; i++){
    dp[i] = 1;
    for(int j = 1 ; j < i ; j++){
      if(a[i] > a[j]){
        dp[i] = max(dp[i] , dp[j]+1);
      }
    }
  }
  for(int i = n ; i >= 1 ; i--){
    f[i] = 1;
    for(int j = n ; j > i ; j--){
      if(a[i] > a[j]){
        f[i] = max(f[i] , f[j]+1);
      }
    }
  }
  int ans = -1e9;
  for(int i = 1 ; i <= n ; i++){
    ans = max(ans , dp[i] + f[i] - 1);
  }
  cout<<n - ans;
  return 0;
}