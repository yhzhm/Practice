/*
14:求10000以内n的阶乘
描述
求10000以内n的阶乘。
输入
只有一行输入，整数n（0<=n<=10000）。
输出
一行，即n!的值。
样例输入
100
样例输出
933262154439441526816992388562667004907159682643816214685929638952175999932299156
*/

#include<cstdio>
#include<cstring>
int main()
{
	int n,i,j,a[100005],lena;
	scanf("%d",&n);
	memset(a,0,sizeof(a)) ;
	a[1]=1;lena=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=lena;j++)
			a[j]*=i;
		for(j=1;j<=lena;j++){
			a[j+1]+=a[j]/10;
			a[j]%=10;
		}
		while(a[lena+1]>0){
			lena++;
			a[lena+1]+=a[lena]/10;
			a[lena]%=10;
		}
	}
	for(i=lena;i>=1;i--)
		printf("%d",a[i]);
	return 0;	
} 
