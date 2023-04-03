#include<bits/stdc++.h>
using namespace std;
char c , x;
int f = 1 , lt = 1 , k = 0 , b = 0 , num;
bool hasNum = 0;
void update(){
  b += lt * f * num;
  return ;
} 
int main(){
  while(cin>>c){
    if(c == '-'){
      update();
      hasNum = 0;
      num = 0 , f = -1;
    }
    else if(c == '+'){
      update();
      hasNum = 0;
      f = 1 , num = 0;
    }
    else if(c == '='){
      update();
      num = 0 , f = 1 , lt = -1;
      hasNum = 0;
    }
    else if(c >= '0' && c <= '9'){
      num = num * 10 + (c - '0');
      hasNum = 1;
    }
    else if(c >= 'a' && c <= 'z'){
      if(hasNum){
        k += lt * f * num;
        num = 0;
      }
      else{
        k += lt * f;
      }
      x = c;
      hasNum = 0;
    }
  }
  update();
  double ans = -b * 1.0 / k;
  if(ans == -0.0){
    ans = 0;
  }
  cout<<x<<"="<<fixed<<setprecision(3)<<ans;
  return 0;
}