#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int dp[N][N];
int a[N][N];
int n;
int dfs(int x , int y){
  if(x < 1 || y < 1){
    return 0;
  }
  if(dp[x][y] != -1){
    return dp[x][y];
  }
  return dp[x][y] = max(dfs(x-1 , y) , dfs(x-1 , y-1)) + a[x][y];
}
int main(){
  memset(dp , 0xff , sizeof(dp));
  cin>>n;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= i ; j++){
      cin>>a[i][j];
    }
  }
  int maxi = -1e9;
  for(int i = 1 ; i <= n ; i++){
    maxi = max(maxi , dfs(n , i));
  }
  cout<<maxi;
  return 0;
}
//cd "e:\liyangtao\1017\P1216.cpp" && g++ -Wl,--stack=0x10000000 -std=c++14 "" -o "P1216".exe && "e:\liyangtao\1017\P1216.cpp""P1216".exe