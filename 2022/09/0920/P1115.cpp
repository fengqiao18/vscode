#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int dp[N];
int main(){
  int n;
  cin>>n;
  for(int i = 1 ; i <= n ; i++){
    int x;
    cin>>x;
    dp[i] = max(dp[i-1]+x , x);
  }
  int maxi = -1e9;
  for(int i = 1 ; i <= n ; i++){
    maxi = max(maxi , dp[i]);
  }
  cout<<maxi;
  return 0;
}