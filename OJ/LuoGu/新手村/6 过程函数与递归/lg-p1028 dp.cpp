/*
这道题可以归于 用DP求方案数类型。
思路：
递推到i个数的解，
就是枚举第i个数的二分之一到0
*/
#include <stdio.h>
const int maxn=1000+2;  
int a[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	a[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i/2;j++)
			a[i]+=a[j];
	printf("%d",a[n]);
	return 0;
}
