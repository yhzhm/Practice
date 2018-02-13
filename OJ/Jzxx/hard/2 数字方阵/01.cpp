#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,x=0;
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
			printf("%3d",i*n+j);
		}
		printf("\n");
	}
	return 0;
}


