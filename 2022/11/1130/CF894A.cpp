#include<bits/stdc++.h>
using namespace std;
string s = "QAQ" , t;
int k = s.size() , ans;
void dfs(int i , int j){//i 表示检索序列将要操作第几位，j 表示目标序列处理完了哪里
  if(i == k){
    ans++;
    return ;
  }
  if(j == t.size() - 1){
    return ;
  }
  // cout<<i<<" "<<j<<endl;
  for(int n = j+1 ; n < t.size() ; n++){
    if(t[n] == s[i]){
      dfs(i+1 , n);
    }
  }
  return ;
}
int main(){
  cin>>t;
  dfs(0 , -1);
  cout<<ans;
  return 0;
}