#include <bits/stdc++.h>
using namespace std;

char a[110][110],b[110][110];
int r,c,n;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void match()
{
	for(int i=1;i<=r;++i){
		for(int j=1;j<=c;++j){
			for(int k=0;k<=3;++k){
			 		if(a[i][j]=='R'&&a[i+dx[k]][j+dy[k]]=='S') b[i+dx[k]][j+dy[k]]='R';
			 		if(a[i][j]=='S'&&a[i+dx[k]][j+dy[k]]=='P') b[i+dx[k]][j+dy[k]]='S';
					if(a[i][j]=='P'&&a[i+dx[k]][j+dy[k]]=='R') b[i+dx[k]][j+dy[k]]='P';
			 }
		}
	}
}

void cp()
{
	for(int i=1;i<=r;++i){
		for(int j=1;j<=c;++j){
			a[i][j]=b[i][j];
		}
	}
}

void print()
{
	for(int i=1;i<=r;++i){
		for(int j=1;j<=c;++j){
			cout<<a[i][j];
		}
		cout<<endl;
	}
}

int main()
{
    
	cin>>r>>c>>n;
	for(int i=1;i<=r;++i){
		for(int j=1;j<=c;++j){
			cin>>a[i][j];
			b[i][j]=a[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		match();
	    cp();
	}
	print();
	return 0;
}