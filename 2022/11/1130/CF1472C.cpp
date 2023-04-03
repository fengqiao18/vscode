#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll helper(int n){
  ll a[N] , f[N] , maxi = -1e18;
  for(int i = 1 ; i <= n ; i++){
    cin>>a[i];
  }
  for(int i = n ; i >= 1 ; i--){
    int tmp = i + a[i];
    if(tmp > n){
      f[i] = a[i];
    }
    else{
      f[i] = f[tmp] + a[i];
    }
    maxi = max(maxi , f[i]);
  }
  return maxi;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    cout<<helper(n)/*<<":ans"*/<<endl;
  }
  return 0;
}