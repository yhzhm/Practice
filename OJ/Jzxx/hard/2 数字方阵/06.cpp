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
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}


