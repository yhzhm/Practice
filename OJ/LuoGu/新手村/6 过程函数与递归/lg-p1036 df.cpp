#include <stdio.h>
int a[21],n,k,s=0,sum=0;
void dfs(int i,int j);
bool prime(int n);
void dfs(int i,int j)
{
	int x;
	if(i>k){
		if(prime(sum)) s++;
		return;
	}
	for(x=j;x<=n;x++){
		sum+=a[x];
		dfs(i+1,x+1);
		sum-=a[x];
	}
}
bool prime(int n)
{
	if(n<2) return false;
	else if(n==2) return true;
	else if(n%2==0) return false;
	int div=2;
	for(;div*div<n;div++)
		if(n%div==0) return false;
	return true;
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1,1);
	printf("%d",s);
	return 0;
}
