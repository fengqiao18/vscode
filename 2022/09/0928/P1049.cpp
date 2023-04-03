#include<bits/stdc++.h>
using namespace std;
const int N = 20005;
int a[N];
int dp[N];
int main(){
  int m , n;
  cin>>m>>n;
  for(int i = 1 ; i <= n ; i++){
    cin>>a[i];
  }
  for(int i = 1 ; i <= n ; i++){
    for(int j = m ; j >= a[i] ; j--){
      dp[j] = max(dp[j] , dp[j - a[i]] + a[i]);
    }
  }
  cout<<m - dp[m];
  return 0;
}