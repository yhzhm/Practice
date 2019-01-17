#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int n,k;
	cin>>n>>k;
	a[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k&&(i-j)>=0;++j){
			a[i]+=a[i-j];
			a[i]%=100003;
		}
	}
	cout<<a[n];
	return 0;
}

