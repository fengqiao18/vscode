#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N] , sum[N];
int maxi;
deque<int> dq;
int main(){
  int n , m;
  cin>>n>>m;
  for(int i = 1 ; i <= n ; i++){
    cin>>a[i];
    sum[i] = sum[i-1] + a[i];
  }
  dq.push_back(0);
  for (int i = 1; i <= n; i++) {
    while (!dq.empty() && sum[i] <= sum[dq.back()]) {
      dq.pop_back();
    }
    dq.push_back(i);
    while (!dq.empty() && i - dq.front() + 1 > m + 1) {
      dq.pop_front();
    }
    maxi = max(maxi , sum[i] - sum[dq.front()]);
  }
  cout<<maxi;
  return 0;
}