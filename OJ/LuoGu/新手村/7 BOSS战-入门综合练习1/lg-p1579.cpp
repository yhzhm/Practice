#include <stdio.h>
bool a[20000+10];
bool prime(int n)
{
	int divisor;
	if(n<=1) return false;
	for(divisor=2;divisor*divisor<=n;divisor++)
		if (n%divisor==0) return false;
	return true;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=2;i<20000;++i)
		a[i]=prime(i);
	for(int i=2;i<n;++i){
		for(int j=i;j<n-i;++j){
			int k=n-i-j;
			if (j<=k)
				if(a[i]&&a[j]&&a[k]) {
					printf("%d %d %d\n",i,j,k);
					return 0;
				}
				
		}
	}
	return 0;
}
