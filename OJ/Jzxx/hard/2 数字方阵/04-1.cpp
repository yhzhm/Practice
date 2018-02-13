#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,a[20][20],x=1;
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=x++;
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=n;i>=1;i--){
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}


