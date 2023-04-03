#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
struct node{
  int id , num;
};
node col[N] , row[N];
int m , n , k , l , d;
bool cmp(node x , node y){
  return x.num > y.num;
}
bool cmp2(node x , node y){
  return x.id < y.id;
}
int main(){
  cin>>m>>n>>k>>l>>d;
  for(int i = 1 ; i <= d ; i++){
    int x , y , p , q;
    cin>>x>>y>>p>>q;
    int r = min(x , p) , c = min(y , q);
    if(x == p){
      col[c].id = c , col[c].num++;
    }
    else{
      row[r].id = r , row[r].num++;
    }
  }
  sort(row+1 , row+1+n , cmp);
  sort(col+1 , col+1+n , cmp);
  sort(row+1 , row+1+k , cmp2);
  sort(col+1 , col+1+l , cmp2);
  for(int i = 1 ; i <= k ; i++){
    cout<<row[i].id<<" ";
  }
  cout<<endl;
  for(int i = 1 ; i <= l ; i++){
    cout<<col[i].id<<" ";
  }
  return 0;
}