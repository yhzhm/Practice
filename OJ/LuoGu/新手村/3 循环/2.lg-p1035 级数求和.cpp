/*
题目描述
已知：Sn= 1＋1／2＋1／3＋…＋1／n。
显然对于任意一个整数K，当n足够大的时候，Sn大于K。
现给出一个整数K（1<=k<=15），要求计算出一个最小的n；使得Sn＞K。
输入格式：
一个正整数K。
输出格式：
一个正整数N。
输入样例#1：
1
输出样例#1：
2
*/


#include <cstdio>
int main()
{
	int k,n=0;
	double s=0;
	scanf("%d",&k);
	while(s<=k)
	{
		s+=1.0/++n;//n是int类型，所以用1.0/++n 
	}
	printf("%d",n);
	return 0;
}
