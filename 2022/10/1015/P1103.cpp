#include<bits/stdc++.h>
using namespace std;
const int N = 105;
struct node{
  int h , w;
};
node a[N];
bool cmp(node x , node y){
  return x.h < y.h;
}
int dp[N][N];
int main(){
  int n , k;
  cin>>n>>k;
  for(int i = 1 ; i <= n ; i++){
    cin>>a[i].h>>a[i].w;
  }
  sort(a+1 , a+1+n , cmp);
  memset(dp , 0x3f , sizeof(dp));
  for(int i = 1 ; i <= n ; i++){
    dp[i][0] = dp[i][1] = 0;
  }
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= min(i , n - k) ; j++){
      for(int p = j - 1 ; p <= i - 1 ; p++){
        dp[i][j] = min(dp[i][j] , dp[p][j-1] + abs(a[p].w - a[i].w));
      }
    }
  }
  int mini = 1e9;
  for(int i = n - k ; i <= n ; i++){
    mini = min(mini , dp[i][n-k]);
  }
  cout<<mini;
  return 0;
}