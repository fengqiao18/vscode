#include<bits/stdc++.h>
using namespace std;
int main(){
  int n , x;
  int ans = 0;
  cin>>n>>x;
  for(int i = 1 ; i <= n ; i++){
    int tmp = i;
    while(tmp != 0){
      if(tmp % 10 == x){
        ans++;
      }
      tmp /= 10;
    }
  }
  cout<<ans;
  return 0;
}