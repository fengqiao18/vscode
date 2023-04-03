#include<bits/stdc++.h>
using namespace std;
const int N = 105;
struct node{
  int h , w;
};
node a[N];
int n , k;
bool cmp(node x , node y){
  return x.h < y.h;
}
int dp[N][N] , ans = 1e9;
int dfs(int i , int j){
  if(dp[i][j] != 0x3f3f3f3f){
    return dp[i][j];
  }
  for(int p = j - 1 ; p <= i - 1 ; p++){
    dp[i][j] = min(dp[i][j] , dfs(p , j-1) + abs(a[p].w - a[i].w));
  }
  return dp[i][j];
}
int main(){
  cin>>n>>k;
  for(int i = 1 ; i <= n ; i++){
    cin>>a[i].h>>a[i].w;
  }
  sort(a+1 , a+1+n , cmp);
  int mini = 1e9;
  for(int i = n - k ; i <= n ; i++){
    memset(dp , 0x3f , sizeof(dp));
    for(int i = 1 ; i <= n ; i++){
      dp[i][0] = dp[i][1] = 0;
    }
    mini = min(mini , dfs(i , n - k));
    // if(mini == 5){
    //   cout<<i;
    // }
  }
  cout<<mini;
  return 0;
}