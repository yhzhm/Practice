#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x=i+j;
			x=x%n+65;
			printf("%3c",x);
		}
		printf("\n");
	}
	return 0;
}


