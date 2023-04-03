#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N] , sum[N];
int main(){
	int n;
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		cin>>a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 0;
	for(int i = 1 ; i < n ; i++){
		if(sum[i] == sum[n] - sum[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

