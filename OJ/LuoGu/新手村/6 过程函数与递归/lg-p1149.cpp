#include <stdio.h>
int a[10]={6,2,5,5,4,5,6,3,7,6};
int check(int n)
{
	int count=0;
	if(n==0) return 6;
	while(n!=0){
		count+=a[n%10];
		n/=10;
	}
	return count;
}
int main()
{
	int n,sum=0;
	scanf("%d",&n);
	n-=4;
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=1000;j++){
			if((check(i)+check(j)+check(i+j))==n){
//				printf("%d+%d=%d : %d+%d+%d=%d\n",i,j,i+j,check(i),check(j),check(i+j),n);
				sum++;
			} 
		}
	printf("%d",sum);		
	return 0;
}

//int main()
//{
//	for(int i=100;i<=1111;i++){
//		printf("%6d:%-6d\n",i,check(i));
//	}
//	return 0;
//}
