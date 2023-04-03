#include<bits/stdc++.h>
#define inf 1e9
using namespace std;
const int N = 1e3 + 5;
int n , k , maxi = -inf;
int a[N];
int main(){
  cin>>n>>k;
  for(int i = 1 ; i <= n ; i++){
    cin>>a[i];
    maxi = max(maxi , a[i]);
  }
  int ans = -inf;
  int lower = 1;
  int upper = lower + k , cnt = 0;
  for(int j = 1 ; j <= n ; j++){
    if(a[j] >= lower && a[j] <= upper){
      cnt++;
    }
  }
  ans = max(ans , cnt);
  for(int lower = 2 ; lower + k <= maxi ; lower++){
    int upper = lower + k , cnt = 0;
    for(int j = 1 ; j <= n ; j++){
      if(a[j] >= lower && a[j] <= upper){
        cnt++;
      }
    }
    ans = max(ans , cnt);
  }
  cout<<ans;
  return 0;
}