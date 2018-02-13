#include <stdio.h>
int check(int n)
{
	int sum=1;
	for(int i=1;i<=n/2;i++)
		sum+=check(i);
	return sum;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",check(n));
	return 0;
}
