/*
12:计算2的N次方
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
任意给定一个正整数N(N<=100)，计算2的n次方的值。
输入
输入一个正整数N。
输出
输出2的N次方的值。
样例输入
5
样例输出
32
提示
高精度计算
*/

#include<cstdio>
#include<cstring>
int main()
{
	int a[205],len,i,j,n;
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	a[1]=1;len=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=len;j++)
			a[j]*=2;
		for(j=1;j<=len;j++){
			a[j+1]+=a[j]/10;
			a[j]%=10;
		}
		if(a[len+1]>0) len++;
	}
	for(i=len;i>=1;i--)
		printf("%d",a[i]);
	return 0;	
}

