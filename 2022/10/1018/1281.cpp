#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N] , dp[N];
int n , maxi = -1e9;
int dfs(int cur){
  if(cur == 1){
    dp[1] = 1;
    return dp[1];
  }
  if(dp[cur] != 1){
    return dp[cur];
  }
  // if(cur == 9){
  //   cout<<"ojoiqegieotgwe"<<endl;
  // }
  // dp[cur] = 1;
  for(int i = 1 ; i < cur ; i++){
    if(a[cur] > a[i]){
      dp[cur] = max(dfs(i) + 1 , dp[cur]);
    }
  }
  return dp[cur];
}
int main(){
  memset(dp , 1 , sizeof(dp));
  cin>>n;
  for(int i = 1 ; i <= n ; i++){
    cin>>a[i];
  }
  dfs(n);
  for (int i = 1; i <= n; i++){
    // cout<<dp[i]<<" ";
    maxi = max(maxi, dp[i]);
  }
  // cout<<endl;
  cout<<maxi;
  // cout<<4;
  return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N], dp[N], maxi = -1e9;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i] = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++)
      if (a[i] > a[j])
        dp[i] = max(dp[i], dp[j] + 1);
  for (int i = 1; i <= n; i++)
    maxi = max(maxi, dp[i]);
  cout << maxi;
  return 0;
}
*/