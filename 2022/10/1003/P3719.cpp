#include<bits/stdc++.h>
using namespace std;
int dfs(int j){
  char c;
  while(scanf("%c" , &c) != EOF){
    if(c == 'a'){
      j++;
    }
    if(c == '('){
      j += dfs(0);
    }
    if(c == '|'){
      return max(j , dfs(0));
    }
    if(c == ')'){
      return j;
    }
  }
  return j;
}
int main(){
  cout<<dfs(0);
  return 0;
}