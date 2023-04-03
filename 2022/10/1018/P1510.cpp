#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int dp[N];
int w[N] , val[N];
int main(){
  int v , n , c;
  cin>>v>>n>>c;
  for(int i = 1 ; i <= n ; i++){
    cin>>val[i]>>w[i];
  }
  for(int i = 1 ; i <= n ; i++){
    for(int j = c ; j >= w[i] ; j--){
      dp[j] = max(dp[j] , dp[j-w[i]] + val[i]);
    }
  }
  for(int i = 0 ; i <= c ; i++){
    if(dp[i] >= v){
      cout<<c - i;
      return 0;
    }
  }
  cout<<"Impossible";
  return 0;
}