#include<bits/stdc++.h>
using namespace std;
bool zhi(int n){
  if(n <= 1){
    return 0;
  }
  if(n % 2 == 0 && n != 2){
    return 0;
  }
  for(int i = 3 ; i * i <= n ; i += 2){
    if(n % i == 0){
      return 0;
    }
  }
  return 1;
}
int main(){
  int n;
  cin>>n;
  for(int i = 1 ; i * i <= n ; i += 2){
    if(n % i == 0 && zhi(i)){
      cout<<n / i;
      return 0;
    }
  }
  return 0;
}