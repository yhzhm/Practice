/*
11:大整数减法
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
求两个大的正整数相减的差。

输入
共2行，第1行是被减数a，第2行是减数b(a > b)。每个大整数不超过200位，不会有多余的前导零。
输出
一行，即所求的差。
样例输入
9999999999999999999999999999999999999
9999999999999
样例输出
9999999999999999999999990000000000000

*/


#include <cstdio>
#include <cstring>
int main()
{
	char a1[205],b1[205],t[205];
	int a[205],b[205],c[205],lena,lenb,lenc,i,x;
	memset(a,0,sizeof(a));	
	memset(b,0,sizeof(b));	
	memset(c,0,sizeof(c));	
	gets(a1);
	gets(b1);
	lena=strlen(a1);
	lenb=strlen(b1);
	if( lena<lenb || lena==lenb&&strcmp(a1,b1)<0){
		strcpy(t,a1);
		strcpy(a1,b1);
		strcpy(b1,t);
		lena=strlen(a1);
		lenb=strlen(b1);
		printf("-");
//		x=lena;lena=lenb;lenb=x;
	}
	for(i=0;i<lena;i++) a[lena-i]=a1[i]-'0';
	for(i=0;i<lenb;i++) b[lenb-i]=b1[i]-'0';
	i=1;
	while(i<=lena||i<=lenb){
		if(a[i]<b[i]){
			a[i]+=10;
			a[i+1]--;
		}
		c[i]=a[i]-b[i];
		i++;
	}
	lenc=i;
	while(c[lenc]==0&&lenc>1) lenc--;
	for(i=lenc;i>=1;i--)
		printf("%d",c[i]);
		
	return 0;
} 
