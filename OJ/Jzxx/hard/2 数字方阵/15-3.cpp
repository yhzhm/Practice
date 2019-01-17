#include<iostream>
using namespace std;
int main()
{
	int n,a[11][11];
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][n-j+1]=min(i,j);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}	
	return 0;
}
