#include <cstdio>
bool n[10];
int a[3+1];
bool check(int x)
{
	n[0]=1;
	for(int i=1;i<10;i++) n[i]=false;
	for(int i=1;i<=3;i++){
		int num=x*a[i]/a[1];
		while(num!=0){
			int s=num%10;
			if(!n[s]) n[s]=true;
			else return false;
			num/=10;
		}
	}
	return true;
}
int main()
{
	
	int i,flag=0;
	for(i=1;i<=3;i++)
		scanf("%d",&a[i]);
	for(i=123;i<=1000/a[1]*a[3];i++)
	{
		if (check(i)) {
			printf("%d %d %d\n",i,i*a[2]/a[1],i*a[3]/a[1]);
			flag=1;
		}
	}
	if(!flag) printf("No!!!");
	return 0;
}
