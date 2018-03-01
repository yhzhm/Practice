#include<iostream>
using namespace std;
int main()
{
	int a[1001]={0},x,n,count=0; //将数组a初始化为0，也可以声明为全局数组 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[x]++;
		if(a[x]==1) count++;
	}
	cout<<count<<endl;
	for(int i=1;i<=1000;i++){
		if(a[i]!=0) cout<<i<<' ';
	}
	return 0;
}