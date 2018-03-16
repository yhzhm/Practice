#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	char a[11][11],b[11][11];
	int t1,t2,t3,t4;
	t1=t2=t3=t4=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
			if(b[i][j]==a[n-j+1][i]) t1++;
			if(b[i][j]==a[j][n-i+1]) t2++;
			if(b[i][j]==a[n-i+1][n-j+1]) t3++;
			if(b[i][j]==a[i][j]) t4++;
			
		}
	}
	if(t1==n*n) cout<<1;
	else if(t2==n*n) cout<<2;
	else if(t3==n*n) cout<<3;
	else if(t4==n*n) cout<<4;
	else cout<<5;
	return 0;
}




