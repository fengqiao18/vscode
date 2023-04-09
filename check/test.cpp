#include<bits/stdc++.h>
using namespace std;
int r(int p){return rand() % p;}
int main(){
  freopen("test.in" , "w" , stdout);
  srand(time(NULL));
  int n = r(1e5) , k = r(1e9);
  cout<<n<<" "<<k<<endl;
  for(int i = 1 ; i <= n ; i++){
    cout<<r(1e9)<<" ";
  }
  return 0;
}