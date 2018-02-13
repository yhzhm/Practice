#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%3d",n*n+i-j*n);
		}
		printf("\n");
	}
	return 0;
}


