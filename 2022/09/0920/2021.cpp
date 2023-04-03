#include<bits/stdc++.h>
using namespace std;
int gcd(int n , int m){
  if(n % m == 0){
    return m;
  }
  return gcd(m , n % m);
}
int main(){
  int n , m;
  cin>>n>>m;
  cout<<gcd(max(n , m) , min(n , m));
  return 0;
}