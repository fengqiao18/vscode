#include<bits/stdc++.h>
#define Alice cout<<"Alice"
#define Bob cout<<"Bob"
using namespace std;
int main(){
  long long a , b , c;
  cin>>a>>b>>c;
  if(1LL * a * a > 1LL * b * c){
    Alice;
  }
  else{
    Bob;
  }
  return 0;
}