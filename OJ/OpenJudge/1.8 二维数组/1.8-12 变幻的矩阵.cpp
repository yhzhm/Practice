#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
	cin>>n;
	char a[15][15],b[15][15];
	int b1,b2,b3,b4;
	b1=b2=b3=b4=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>b[i][j];
			if(b[i][j]==a[n-j-1][i]) b1++;
			if(b[i][j]==a[j][n-i-1]) b2++;
			if(b[i][j]==a[n-i-1][n-j-1]) b3++;
			if(b[i][j]==a[i][j]) b4++;
		}	
	if(b1==n*n) cout<<1;
	else if (b2==n*n) cout<<2;
	else if (b3==n*n) cout<<3;
	else if (b4==n*n) cout<<4;
	else cout<<5;
	cout<<endl;
	return 0;
}
