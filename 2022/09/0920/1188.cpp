#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
int main(){
  int n;
  cin>>n;
  a[1] = a[2] = 1;
  for(int i = 3 ; i <= 1e6 ; i++){
    a[i] = (a[i-1] + a[i-2]) % 1000;
  }
  while(n--){
    int _;
    cin>>_;
    cout<<a[_]<<endl;
  }
  return 0;
}