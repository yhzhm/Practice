#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x=max(i,j);
			printf("%3d",x);
		}
		printf("\n");
	}
	return 0;
}
