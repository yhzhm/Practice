/*
13:大整数的因子
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
已知正整数k满足2<=k<=9，现给出长度最大为30位的十进制非负整数c，求所有能整除c的k。

输入
一个非负整数c，c的位数<=30。
输出
若存在满足 c%k == 0 的k，从小到大输出所有这样的k，相邻两个数之间用单个空格隔开；若没有这样的k，则输出"none"。
样例输入
30
样例输出
2 3 5 6
*/

#include<cstdio>
#include<cstring>
int main()
{
	int a[35],lenc,i,j,x,flag=0;
	char c[35];
	gets(c);
	lenc=strlen(c);
	for(i=0;i<lenc;i++) a[lenc-i]=c[i]-'0';
	for(i=2;i<=9;i++){
		x=0;
		for(j=lenc;j>=1;j--)
			x=(x*10+a[j])%i;
		if(x==0){
			flag=1;
			printf("%d ",i);
		}
	}
	if(flag==0) printf("none");
	return 0;	
}
