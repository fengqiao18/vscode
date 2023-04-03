#include<bits/stdc++.h>
using namespace std;
int main(){
  int n , l , r;
  cin>>n>>l>>r;
  if(r - l >= n){
    cout<<n-1;
  }
  else{
    int tmp = l / n * n + n;
    if(tmp <= r){
      cout<<n-1;
    }
    else{
      cout<<r % n;
    }
  }
  return 0;
}