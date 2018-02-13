/*
43:质因数分解
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
已知正整数 n 是两个不同的质数的乘积，试求出较大的那个质数。

输入
输入只有一行，包含一个正整数 n。

对于60%的数据，6 ≤ n ≤ 1000。
对于100%的数据，6 ≤ n ≤ 2*10^9。
输出
输出只有一行，包含一个正整数 p，即较大的那个质数。
样例输入
21
样例输出
7
=================
因为题目已经假设n是两个质数的积，
所以判断出一个指数后，第二个不用判断，不然超时 
*/


//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	long long n,i,j,k,a,b,max=0;
//	_Bool f;
//	scanf("%lld",&n);
//	a=(long long)sqrt(n);
////	printf("%lld\n",a);
//	for (i=2;i<=a;i++){
//		if(n%i==0){
//			f=1;
//			for(j=2;j<=i-1;j++){
//				if(i%j==0) {f=0;break;}
//			}
//			if(f){
//				b=n/i;
//				for(k=2;k<=b-1;k++){
//					if(b%k==0){f=0;break;}
//				}
//			}
//			if(f) {
//				i=(i>b)?i:b;
//				max=(max>i)?max:i;
//			}
//		}
//		
//	}
//	printf("%lld",max);
//	return 0;
//}


#include <stdio.h>
#include <math.h>
int main()
{
	long long n,i,j,a,max=0;
	_Bool f;
	scanf("%lld",&n);
	a=sqrt(n);
	for (i=2;i<=a;i++){
		if(n%i==0){
			f=1;
			for(j=2;j<=i-1;j++){
				if(i%j==0) {f=0;break;}
			}
			if(f) {	
				i=(i>n/i)?i:n/i;
				max=(max>i)?max:i;
			}
		}
		
	}
	printf("%lld",max);
	return 0;
}

