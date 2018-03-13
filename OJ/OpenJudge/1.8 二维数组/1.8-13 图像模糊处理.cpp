#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	double avg;
	cin>>n>>m;
	int a[110][110],b[110][110];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(i==1||j==1||i==n||j==m) b[i][j]=a[i][j];
			else {
				avg=(a[i][j]+a[i-1][j]+a[i][j+1]+a[i+1][j]+a[i][j-1])/5.0;
				b[i][j]=floor(avg+0.5);  //ËÄÉáÎåÈë
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cout<<b[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}

