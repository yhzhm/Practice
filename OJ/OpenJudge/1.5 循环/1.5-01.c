/*
01:求平均年龄
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
班上有学生若干名，给出每名学生的年龄（整数），求班上所有学生的平均年龄，保留到小数点后两位。

输入
第一行有一个整数n（1<= n <= 100），表示学生的人数。其后n行每行有1个整数，表示每个学生的年龄，取值为15到25。
输出
输出一行，该行包含一个浮点数，为要求的平均年龄，保留到小数点后两位。
样例输入
2
18
17
样例输出
17.50
提示
要输出浮点数、双精度数小数点后2位数字，可以用下面这种形式： 

printf("%.2f", num);
*/

//#include <stdio.h>
//int main()
//{
//	int n,a,b;
//	float c=0.0;
//	scanf("%d",&n);
//	b=n;
//	while(n>0){
//		scanf("%d",&a);
//		c=c+a;
//		n--;
//	}
//	printf("%.2f",c/b);
//	return 0;
//}

#include <stdio.h>
int main()
{
	int n,a,i;
	double sum=0.0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		sum+=a;
	}
	printf("%.2f",sum/n);
	return 0;
}
