#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N] , dp[N];
int dfs(int cur){
  if(cur == 1){
    return dp[1] = 1;
  }
  if(dp[cur] != -1){
    return dp[cur];
  }
  dp[cur] = 1;
  for(int i = 1 ; i < cur ; i++){
    if(a[i] < a[cur]){
      dp[cur] = max(dp[cur] , dfs(i) + 1);
    }
  }
  return dp[cur];
}
int main(){
  memset(dp , -1 , sizeof(dp));
  int n;
  cin>>n;
  for(int i = 1 ; i <= n ; i++){
    cin>>a[i];
  }
  int maxi = -1e9;
  for(int i = 1 ; i <= n ; i++){
    maxi = max(maxi , dfs(i));
  }
  cout<<maxi;
  return 0;
}