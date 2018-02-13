/*
题目描述
试计算在区间 1 到 n 的所有整数中，数字 x（0 ≤ x ≤ 9）共出现了多少次？例如，在 1
到 11 中，即在 1、2、3、4、5、6、7、8、9、10、11 中，数字 1 出现了 4 次。
输入格式：
输入共 1 行，包含 2 个整数 n、x，之间用一个空格隔开。
输出格式：
输出共 1 行，包含一个整数，表示 x 出现的次数。
输入样例#1：
11 1
输出样例#1：
4
说明
对于 100%的数据，1≤ n ≤ 1,000,000，0 ≤ x ≤ 9。
*/

//#include <cstdio>
//int main()
//{
//	int n,x,count=0;
//	scanf("%d%d",&n,&x);
//	for(int i=1;i<=n;i++){
//		int s=i;//将i赋值给s，再拆解s，因为i要用来控制循环，如果因为拆解改变了值，会影响循环。 
//		while(s!=0){
//			if(s%10==x) count++;
//			s/=10;
//		}
//	}
//	printf("%d",count);
//	return 0;
//}

#include <cstdio>
int check(int i,int x)//检查每个数i，返回i中x的个数 
{
	int count=0;//计数变量 
	while(i!=0){
		if(i%10==x) count++;
		i/=10;
	}
	return count;
}
int main()
{
	int n,x,sum=0;
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++){
		sum+=check(i,x);//累加x出现的次数 
	}
	printf("%d",sum);
	return 0;
}
