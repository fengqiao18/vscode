#include<bits/stdc++.h>
using namespace std;
void bu(string &s , int len){
  while(s.size() != len){
    s = '0' + s;
  }
  return ;
}
string jia(string s1 , string s2){
  string ans;
  int len = max(s1.size() , s2.size());
  if(s1.size() > s2.size()){
    bu(s2 , s1.size());
  }
  else{
    bu(s1 , s2.size());
  }
  int jin = 0;
  for(int i = len-1 ; i >= 0 ; i--){
    int tmp = s1[i] - '0' + s2[i] - '0' + jin;
    jin = tmp / 10;
    tmp = tmp % 10;
    ans += (char)(tmp + '0');
  }
  if(jin != 0){
    ans += (char)(jin + '0');
  }
  string f;
  for(int i = 0 ; i < ans.size() ; i++){
    f = ans[i] + f;
  }
  return f;
}
string cheng(string s1 , string s2){
  string ans = "";
  for(int i = s2.size() - 1 ; i >= 0 ; i--){
    string tmp;
    for(int j = s2[i] - '0' ; j >= 1 ; j--){
      tmp = jia(tmp , s1);
    }
    for(int j = 1 ; j <= s2.size() - i - 1 ; j++){
      tmp = tmp + '0';
    }
    ans = jia(ans , tmp);
  }
  return ans;
}
string zhuan(int n){
  string ans;
  while(n != 0){
    char ch = n % 10 + '0';
    ans = ch + ans;
    n /= 10;
  }
  return ans;
}
int main(){
  string ans;
  int n;
  cin>>n;
  for(int i = 1 ; i <= n ; i++){
    string tmp = "1";
    for(int j = 1 ; j <= i ; j++){
      string s = zhuan(j);
      // if(j == 10){
      //   cout<<"kkk : "<<s<<endl;
      // }
      tmp = cheng(tmp , s);
    }
    ans = jia(ans , tmp);
    // cout<<ans<<endl;
  }
  cout<<ans;
  return 0;
}