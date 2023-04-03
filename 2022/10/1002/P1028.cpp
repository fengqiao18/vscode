#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
long long dp[N];
int main(){
  int n;
  cin>>n;
  // long t = clock();
  dp[0] = dp[1] = 1;
  for(int i = 2 ; i <= n ; i++){
    dp[i] = dp[i-1];
    if(i % 2 == 0){
      dp[i] += dp[i/2];
    }
  }
  cout<<dp[n]<<endl;
  // cout<<clock() - t;
  return 0;
}