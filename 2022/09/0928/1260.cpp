#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N];
int main(){
  int n = 1;
  while(cin>>a[n]){
    n++;
  }
  n--;
  // cout<<n<<endl;
  int dp1[N] , dp2[N];
  for(int i = 1 ; i <= n ; i++){
    dp2[i] = 1;
    for(int j = 1 ; j <= i-1 ; j++){
      if(a[j] >= a[i]){
        dp2[i] = max(dp2[i] , dp2[j] + 1);
      }
    }
    // cout<<dp2[i]<<" ";
  }
  // cout<<endl;
  for(int i = 1 ; i <= n ; i++){
    dp1[i] = 1;
    for(int j = 1 ; j <= i-1 ; j++){
      if(a[j] < a[i]){
        dp1[i] = max(dp1[i] , dp1[j] + 1);
      }
    }
    // cout<<dp1[i]<<" ";
  }
  int ans1 = -1e9 , ans2 = -1e9;
  for(int i = 1 ; i <= n ; i++){
    ans1 = max(ans1 , dp1[i]);
    ans2 = max(ans2 , dp2[i]);
  }
  cout<<ans2<<endl<<ans1;
  return 0;
}