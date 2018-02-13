#include <stdio.h>
int sum=0;
int check(int n)
{
	sum++;
	for(int i=1;i<=n/2;i++)
		check(i);
}
int main()
{
	int n;
	scanf("%d",&n);
	check(n);
	printf("%d",sum);
	return 0;
}
