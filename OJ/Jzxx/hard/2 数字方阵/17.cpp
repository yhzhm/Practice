#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,a[11][11];
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=n-i+1;k++){
				a[j][k]=n-i+1;
			}
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
