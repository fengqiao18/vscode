#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  if(n & 1){
    cout<<-1;
    return 0;
  }
  for(int i = 30 ; i >= 1 ; i--){
    int tmp = pow(2 , i);
    if(n >= tmp){
      cout<<tmp<<" ";
      n -= tmp;
    }
    if(n == 0){
      return 0;
    }
  }
  return 0;
}