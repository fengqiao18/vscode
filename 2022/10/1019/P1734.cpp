#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int w[N] , val[N] , dp[N];
/// @brief 因数和求和函数
/// @param n 一个数
/// @return n的因数和
int f(int n){
  long long sum = 0;
  for(int i = 1 ; i < n ; i++){
    if(n % i == 0){
      sum += i;
    }
  }
  return sum;
}
int main(){
  int s;
  cin>>s;
  for(int i = 1 ; i <= s ; i++){
    w[i] = i;
    val[i] = f(i);
  }
  for(int i = 1 ; i <= s ; i++){
    for(int j = s ; j >= w[i] ; j--){
      dp[j] = max(dp[j] , dp[j-w[i]] + val[i]); 
    }
  }
  cout<<dp[s];
  return 0;
}