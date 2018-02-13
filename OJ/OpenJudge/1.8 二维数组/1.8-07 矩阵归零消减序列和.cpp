#include <iostream>
using namespace std;
int main()
{
	int a[105][105];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int k=n;k>=1;k--){
		cout<<a[2][2]<<endl;
		for(int i=1;i<=k;i++){//行归零 
			int minn=10000000;
			for(int j=1;j<=k;j++){
				if(a[i][j]<minn) minn=a[i][j];
			}
			for(int j=1;j<=k;j++){
				a[i][j]-=minn;
			}
		}
		for(int j=1;j<=k;j++){//列归零 
			int minn=10000000;
			for(int i=1;i<=k;i++){
				if(a[i][j]<minn) minn=a[i][j];
			}
			for(int i=1;i<=k;i++){
				a[i][j]-=minn;
			}
		}
		for(int i=2;i<k;i++)//行消减 
			for(int j=1;j<=k;j++)
				a[i][j]=a[i+1][j];
		for(int j=2;j<k;j++)//列消减 
			for(int i=1;i<k;i++)
				a[i][j]=a[i][j+1];
	}
	return 0;
}
