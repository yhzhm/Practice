#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,x=0,a[15][15];
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=++x;
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}


