#include <bits/stdc++.h>
using namespace std;
char a[110][110],b[110][110];
int main()
{
	int n,m,sum;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(a[i][j]=='*') b[i][j]='*';
			else{
				sum=0;
				for(int k=-1;k<=1;++k)
					for(int h=-1;h<=1;++h)
						if(a[i+k][j+h]=='*') sum++;
				b[i][j]=sum+'0';		
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cout<<b[i][j];
		}
		cout<<endl;
	}
	return 0;
}
