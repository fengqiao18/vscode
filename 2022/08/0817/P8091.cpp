#include<bits/stdc++.h>
using namespace std;
bool helper(){
  int a[5] , b[5];
  for(int i = 1 ; i <= 4 ; i++)
    cin>>a[i];
  sort(a+1 , a+1+4);
  for(int i = 1 ; i <= 4 ; i++)
    cin>>b[i];
  sort(b+1 , b+1+4);
  int wa = 0 , wb = 0;
  for(int i = 1 ; i <= 4 ; i++){
    for(int j = 1 ; j <= 4 ; j++){
      if(a[i] > b[j])
        wa++;
      else if(a[i] < b[j])
        wb++;
    }
  }
  if(wa == wb)
    return 0;
  if(wa > wb){
    for(int i = 1 ; i <= 4 ; i++)
      swap(a[i] , b[i]);
  }
  int c[5];
  for(c[1] = 1 ; c[1] <= 10 ; c[1]++){
    for(c[2] = c[1] ; c[2] <= 10 ; c[2]++){
      for(c[3] = c[2] ; c[3] <= 10 ; c[3]++){
        for(c[4] = c[3] ; c[4] <= 10 ; c[4]++){
          int wa = 0 , la = 0 , wb = 0 , lb = 0;
          for(int i = 1 ; i <= 4 ; i++){
            for(int j = 1 ; j <= 4 ; j++){
              if(a[i] > c[j])
                la++;
              if(a[i] < c[j])
                wa++;
              if(b[i] > c[j])
                lb++;
              if(b[i] < c[j])
                wb++;
            }
          }
          if(la > wa && wb > lb)
            return 1;
        }
      }
    }
  }
  return 0;
}
int main(){
  int T;
  cin>>T;
  while(T--){
    cout<<(helper() == true ? "yes\n" : "no\n");
  }
  return 0;
}