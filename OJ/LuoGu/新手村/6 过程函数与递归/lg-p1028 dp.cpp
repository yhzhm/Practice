/*
�������Թ��� ��DP�󷽰������͡�
˼·��
���Ƶ�i�����Ľ⣬
����ö�ٵ�i�����Ķ���֮һ��0
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
