#include<bits/stdc++.h>
using namespace std;
inline void read(int *p){scanf("%d" , p);}
const int N = 3e4 + 5;
int a[N] , dp[N][4];
int main(){
  int n;
  cin>>n;
  for(int i = 1 ; i <= n ; i++){
    read(&a[i]);
  }
  for(int i = 1 ; i <= n ; i++){
    if(a[i] == 1){
      dp[i][1] = dp[i-1][1];
      dp[i][2] = min(dp[i-1][1] , dp[i-1][2])+1;
      dp[i][3] = min(dp[i-1][1] , min(dp[i-1][2] , dp[i-1][3]))+1;
    }
    if(a[i] == 2){
      dp[i][1] = dp[i-1][1]+1;
      dp[i][2] = min(dp[i-1][1] , dp[i-1][2]);
      dp[i][3] = min(dp[i-1][1] , min(dp[i-1][2] , dp[i-1][3]))+1;
    }
    if(a[i] == 3){
      dp[i][1] = dp[i-1][1]+1;
      dp[i][2] = min(dp[i-1][1] , dp[i-1][2])+1;
      dp[i][3] = min(dp[i-1][1] , min(dp[i-1][2] , dp[i-1][3]));
    }
  }
  int ans = min(dp[n][1] , min(dp[n][2] , dp[n][3]));
  memset(dp , 0 , sizeof(dp));
  for(int i = n ; i >= 1 ; i--){
    if(a[i] == 1){
      dp[i][1] = dp[i+1][1];
      dp[i][2] = min(dp[i+1][1] , dp[i+1][2])+1;
      dp[i][3] = min(dp[i+1][1] , min(dp[i+1][2] , dp[i+1][3]))+1;
    }
    if(a[i] == 2){
      dp[i][1] = dp[i+1][1]+1;
      dp[i][2] = min(dp[i+1][1] , dp[i+1][2]);
      dp[i][3] = min(dp[i+1][1] , min(dp[i+1][2] , dp[i+1][3]))+1;
    }
    if(a[i] == 3){
      dp[i][1] = dp[i+1][1]+1;
      dp[i][2] = min(dp[i+1][1] , dp[i+1][2])+1;
      dp[i][3] = min(dp[i+1][1] , min(dp[i+1][2] , dp[i+1][3]));
    }
  }
  ans = min(ans , min(dp[1][1] , min(dp[1][2] , dp[1][3])));
  printf("%d" , ans);
  return 0;
}