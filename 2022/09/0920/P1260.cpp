#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int dp[N][N];
int main(){
  int n;
  cin>>n;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= i ; j++){
      int x;
      cin>>x;
      dp[i][j] = max(dp[i-1][j] , dp[i-1][j-1]) + x;
    }
  }
  int maxi = -1e9;  
  for(int i = 1 ; i <= n ; i++){
    maxi = max(maxi , dp[n][i]);
  }
  cout<<maxi;
  return 0;
}