#include<bits/stdc++.h>
using namespace std;
bool zhi(int n){
  for(int i = 2 ; i * i <= n ; i++){
    if(n % i == 0)
      return 0;
  }
  return 1;
}
int main(){
  int n , m;
  bool flag = 0;
  cin>>m>>n;
  for(int i = m ; i <= n ; i++){
    if(i == 1)
      continue;
    for(int j = i ; j >= 2 ; j--){
      if(i % j == 0 && zhi(j)){
        if(!flag){
          cout<<j;
          flag = 1;
        }
        else  
          cout<<","<<j;
        break;
      }
    }
  }
  return 0;
}