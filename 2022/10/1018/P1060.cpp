#include<bits/stdc++.h>
using namespace std;
const int N = 25 , M = 50005;
int w[N] , val[N];
int dp[M];
int main(){
  int n , m;
  cin>>n>>m;
  for(int i = 1 ; i <= m ; i++){
    int tmp;
    cin>>w[i]>>tmp;
    val[i] = w[i] * tmp;
  }
  for(int i = 1 ; i <= m ; i++){
    for(int j = n ; j >= w[i] ; j--){
      dp[j] = max(dp[j] , dp[j-w[i]] + val[i]);
    }
  }
  cout<<dp[n];
  return 0;
}