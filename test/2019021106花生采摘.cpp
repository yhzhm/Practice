#include<bits/stdc++.h>
using namespace std;
int main() {
	int m,n,k,maxi,maxj,max=0,ans=0;
	cin>>m>>n>>k;
	int a[n+5][m+5];
	for(int i=1; i<=m; ++i)
		for(int j=1; j<=n; ++j)
			cin>>a[i][j];
	int nowt=0,nowi=0,nowj=0;
	
	while(1) {
		max=0;
		for(int i=1; i<=m; ++i) {
			for(int j=1; j<=n; ++j) {
				if(a[i][j]>max){
					max=a[i][j];
					maxi=i;
					maxj=j;
				}	
			}
		}
		if(nowt==0) nowj=maxj;
		if(nowt+maxi+1+abs(maxi-nowi)+abs(maxj-nowj)<=k) {
			ans+=a[maxi][maxj];
			nowt+=abs(maxi-nowi)+abs(maxj-nowj)+1;
			nowi=maxi;
			nowj=maxj;
			a[maxi][maxj]=0;
		}
		else break;
	}
	cout<<ans;
	return 0;
}
