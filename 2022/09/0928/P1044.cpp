#include<bits/stdc++.h>
using namespace std;
const int N = 25;
long long f[N];
int main(){
  f[1] = f[0] = 1;
  int n;
  cin>>n;
  for(int i = 2 ; i <= n ; i++){
    for(int j = 0 ; j < n ; j++){
      f[i] += f[j] * f[i-j-1];
    }
  }
  cout<<f[n];
  return 0;
}