#include<bits/stdc++.h>
using namespace std;
int a[200001];
int find(int l,int r,int x)
{
	int mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(a[mid]==x)return mid;
		else if (a[mid]>x)r=mid-1;
		else l=mid+1;
	}
	return -1;
}
int main()
{
  freopen("test.in", "r", stdin);
  freopen("2.out", "w", stdout);
	int n,x,ans;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		int pos=find(1,n,a[i]+x);
		if(pos!=-1)ans++;
	}
	cout<<ans;
	return 0;
}