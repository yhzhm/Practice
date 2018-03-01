#include <stdio.h>
int main()
{
	int a[1001],i,j,t,n,sum=0;
	for(i=0;i<=1000;i++){
		a[i]=0;
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&t);
		a[t]++;
		if(a[t]==1) sum++;
	}
	printf("%d\n",sum);
	for(i=1;i<=1000;i++){
		if(a[i]!=0) printf("%d ",i);
	}
	return 0;
}