#include <stdio.h>
int main()
{
	int n,i=0,sum=0,a,b;
	scanf("%d",&n);
	while(sum<=n){
		sum+=++i;
	}
	if(n-(sum-i)==0){ --i; a=b=i;	}
	else{ a=i; b=n+i-sum; }
	if(i%2==1) printf("%d/%d",a+1-b,b);
	else printf("%d/%d",b,a+1-b);
	return 0;
}
