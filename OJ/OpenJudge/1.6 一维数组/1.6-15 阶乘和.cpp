/*
15:阶乘和
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
用高精度计算出S=1!+2!+3!+…+n!（n≤50）

其中“!”表示阶乘，例如：5!=5*4*3*2*1。

输入正整数N，输出计算结果S。

输入
一个正整数N。
输出
计算结果S。
样例输入
5
样例输出
153
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,a[10005],b[10005],lena,lenb,i,j;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	cin>>n;
	a[1]=1;lena=1;b[1]=0;lenb=1;
	for (i=1;i<=n;++i){
		for (j=1;j<=lena;++j){
			a[j]*=i;b[j]+=a[j];
		}
		for (j=1;j<=lena;++j){
			a[j+1]+=a[j]/10;
			a[j]%=10;
		}
		for (j=1;j<=lenb;++j){
			b[j+1]+=b[j]/10;
			b[j]%=10;
		}
		while (a[lena+1]>0) {
			++lena;
			a[lena+1]+=a[lena]/10;
			a[lena]%=10;
		}
		while (b[lenb+1]>0) {
			++lenb;
			b[lenb+1]+=b[lenb]/10;
			b[lenb]%=10;
		}		
	}
	for (i=lenb;i>=1;i--)
	  cout<<b[i];
	cout<<endl;
	return 0;
}
