/*
44:第n小的质数
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
输入一个正整数n，求第n小的质数。

输入
一个不超过10000的正整数n。
输出
第n小的质数。
样例输入
10
样例输出
29
*/


#include <stdio.h>
#include <math.h>
int main()
{
	long long i,j,a;
	int n,f,c,sum=0; 
	scanf("%d",&n);
	for(i=2;;i++){
		f=1;
		for(j=2;j<=(long long)sqrt(i);j++){
			if(i%j==0) {f=0;break;}	
		}
		if(f) {
		c=i;
		sum++;
		}
		if(sum==n) break;
	}
	printf("%d",c);		
	return 0;
}

