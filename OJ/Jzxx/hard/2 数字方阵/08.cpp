#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x=i+j+1;
			if(x>n) x=2*n-x;
			printf("%3d",x);
		}
		printf("\n");
	}
	return 0;
}


