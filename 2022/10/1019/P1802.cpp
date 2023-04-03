#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int lose[N] , win[N];
long long dp[N] , w[N];
int main(){
  int n , x;
  cin>>n>>x;
  for(int i = 1 ; i <= n ; i++){
    cin>>lose[i]>>win[i]>>w[i];
  }
  for(int i = 1 ; i <= n ; i++){
    for(int j = x ; j >= 0 ; j--){
      if(j >= w[i]){
        dp[j] = max(dp[j] + lose[i] , dp[j-w[i]] + win[i]);
      }
      else{
        dp[j] = dp[j] + lose[i];
      }
    }
  }
  cout<<dp[x] * 5;
  return 0;
}