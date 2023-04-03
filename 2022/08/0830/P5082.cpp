#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e7 + 5;
ll ans[N] , ans1 , ans2 , ans3;
int main(){
  int n;
  cin>>n;
  for(int i = 1 ; i <= n ; i++){
    cin>>ans[i];
    ans1 += ans[i];
  }
  for(int i = 1 ; i <= n ; i++){
    ll x;
    cin>>x;
    ans2 += x;
    ans3 += ans[i] - x;
  }
  cout<<fixed<<setprecision(6)<<(ans1 * 3 - ans2 * 2) * 1.0 / ans3;
  return 0;
}