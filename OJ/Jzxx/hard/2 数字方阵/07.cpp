#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%3d",i+j+1);
		}
		printf("\n");
	}
	return 0;
}


