/*
10:大整数加法
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
求两个不超过200位的非负整数的和。

输入
有两行，每行是一个不超过200位的非负整数，可能有多余的前导0。
输出
一行，即相加后的结果。结果里不能有多余的前导0，即如果结果是342，那么就不能输出为0342。
样例输入
22222222222222222222
33333333333333333333
样例输出
55555555555555555555
*/

#include <cstdio>
#include <cstring> 
int main()
{
	const int MAX=200+5; 
	char a1[MAX],b1[MAX];
	int a[MAX],b[MAX],c[MAX],lena,lenb,lenc,i,x;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	gets(a1);
	gets(b1);
	lena=strlen(a1);
	lenb=strlen(b1);
	for(i=0;i<lena;i++) a[lena-i]=a1[i]-'0';
	for(i=0;i<lenb;i++) b[lenb-i]=b1[i]-'0';
	lenc=1;x=0;
	while(lenc<=lena || lenc<=lenb){
		c[lenc]=a[lenc]+b[lenc]+x;
		x=c[lenc]/10;
		c[lenc]%=10;
		lenc++;
	}
	c[lenc]=x;
	while(c[lenc]==0 && lenc>1) lenc--;
	for(i=lenc;i>=1;i--)
		printf("%d",c[i]);
	return 0;
}
