/*
16:计算线段长度
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
已知线段的两个端点的坐标A（Xa,Ya），B（Xb，Yb），求线段AB的长度。

输入
共两行。
第一行是两个实数Xa，Ya，即A的坐标。
第二行是两个实数Xb，Yb，即B的坐标。
输入中所有实数的绝对值均不超过10000。
输出
一个实数，即线段AB的长度，保留到小数点后3位。
样例输入
1 1
2 2
样例输出
1.414
*/

#include <stdio.h>
#include <math.h>
int main ()
{
	float x,y,z,xa,xb,ya,yb;
	scanf("%f%f",&xa,&xb);
	scanf("%f%f",&ya,&yb);
	x=xa-ya;
	y=xb-yb;
	if(x<0) x=-x;
	if(y<0) y=-y;
	z=sqrt(x*x+y*y);
	printf("%.3f",z);
	return 0;
}
