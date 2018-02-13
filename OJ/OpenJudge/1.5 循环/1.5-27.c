/*
27:级数求和
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
已知：Sn= 1＋1／2＋1／3＋…＋1／n。显然对于任意一个整数K，当n足够大的时候，Sn大于K。

现给出一个整数K（1<=k<=15），要求计算出一个最小的n；使得Sn＞K。

输入
一个整数K。
输出
一个整数n。
样例输入
1
样例输出
2
*/

#include <stdio.h>
int main()
{
	int i=0,k,n;
	double sn=0;
	scanf("%d",&k);
	while(sn<=k){
		sn+=1.0/++i;
	}
	printf("%d",i);
	return 0;
}

#include <stdio.h>
int main()
{
	int i,k,n;
	double sn=0;
	scanf("%d",&k);
	for (i=1;;i++){
		sn+=1.0/i;
		if (sn>k) {
		printf("%d",i);
		break;
		}
	}
	return 0;
}
