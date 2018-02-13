#include<iostream>
using namespace std;
int main()
{
	int n,a[11];
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%3d",min(i,j));
		}
		printf("\n");
	}
	return 0;
}
