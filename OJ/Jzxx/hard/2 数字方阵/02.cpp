#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for(int i=n-1;i>=0;i--){
		for(int j=1;j<=n;j++){
			printf("%3d",i*n+j);
		}
		printf("\n");
	}
	return 0;
}


