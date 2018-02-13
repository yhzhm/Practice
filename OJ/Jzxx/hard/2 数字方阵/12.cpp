#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x=n-max(i,j);
			printf("%3d",x);
		}
		printf("\n");
	}
	return 0;
}
