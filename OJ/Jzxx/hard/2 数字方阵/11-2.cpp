#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,a[11][11];
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i;k<=n;k++){
				a[j][k]=i;
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
