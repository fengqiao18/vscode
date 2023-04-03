#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N][N] , dp[N][N];
int main(){
  int n;
  cin>>n;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= n ; j++){
      cin>>a[i][j];
    }
    dp[1][i] = dp[1][i-1] + a[1][i];
    dp[i][1] = dp[i-1][1] + a[i][1];
  }
  for(int i = 2 ; i <= n ; i++){
    for(int j = 2 ; j <= n ; j++){
      dp[i][j] = min(dp[i-1][j] , dp[i][j-1]) + a[i][j]; 
    }
  }
  cout<<dp[n][n];
  return 0;
}