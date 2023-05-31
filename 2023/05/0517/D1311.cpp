#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char a[N];
int dp[N][N];
int getsum(int start , int end){
  int ans = 0;
  for(int i = start ; i <= end ; i++){
    ans = ans * 10 + (a[i] - '0');
  }
  return ans;
}
int main(){
  int n , m;
  cin>>n>>m;
  for(int i = 1 ; i <= n ; i++){
    cin>>a[i];
  }
  for(int i = 1 ; i <= n ; i++){
    dp[i][0] = getsum(1 , i);
  }
  for(int i = 2 ; i <= n ; i++){
    for(int j = 1 ; j <= (min(i - 1 , m)) ; j++){
      for(int k = j ; k <= i - 1 ; k++){
        int tmp = dp[k][j - 1] * getsum(k + 1 , i);
        dp[i][j] = max(dp[i][j] , tmp);
      }
    }
  }
  cout<<dp[n][m];
  return 0;
}