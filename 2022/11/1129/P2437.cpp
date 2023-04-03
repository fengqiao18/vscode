#include<bits/stdc++.h>
using namespace std;
int lena , n , m , num1[50005] , num2[50005] , num3[50005];
void add(int num1[] , int num2[] , int num3[]){
  int x = 0;
  for (int i = 1; i <= lena; i++) {
    int tmp = num1[i] + num2[i] + x;
    num3[i] = tmp % 10;
    x = tmp / 10;
  }
  if (x > 0) {
    num3[++lena] = x;
  }
  return ;
}
void move(int a[] , int b[]){
  for(int i = 1 ; i <= lena ; i++){
    a[i] = b[i];
  }
  return ;
}
int main(){
  lena = 1;
  cin>>m>>n;
  num1[1] = 1;
  num2[1] = 1;
  for(int i = 3 ; i <= n - m + 1 ; i++){
    add(num1 , num2 , num3);
    move(num1 , num2);
    move(num2 , num3);
  }
  for(int i = lena ; i >= 1 ; i--){
    cout<<num3[i];
  }
  return 0;
}