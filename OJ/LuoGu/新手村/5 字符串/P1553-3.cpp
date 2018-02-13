/*
==========================
其实这个题主要在于题意理解。
关于整数
后面的0不要
遇到“0”或“000000000000”只输出0

关于小数
小数点前的整数：后面的0不要
小数点后的整数：前面的0不要
遇到“0”或“000000000000”只输出0
小数点的正确输出

关于分数
分数前的整数：后面的0不要
分数后的整数：后面的0不要
遇到“0”或“000000000000”只输出0
分数的正确输出

关于百分数
百分数前的整数：后面的0不要
遇到“0”或“000000000000”只输出0
百分号的正确输出
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[20+5];
int len=0;
void reversef(int fro,int to)
{
	int i,pos=0;
	for(i=to;i>=fro;i--)
		if(a[i]!='0') {	pos=i;break;	}
	for(i=pos;i>=fro;i--)
		cout<<a[i];
}

void reverseb(int fro,int to)
{
	int i,pos=to;
	for(i=fro;i<=to;i++)
		if(a[i]!='0'){ pos=i; break; } 
	for(i=to;i>=pos;i--)
		cout<<a[i];
}
	
int main()
{
	cin>>a;
	len=strlen(a);
	for(int i=0;i<len;i++){
		if(a[i]=='.'){
			reversef(0,i-1);
			cout<<a[i];
			reverseb(i+1,len-1);
			return 0;
		} 
		if(a[i]=='/'){
			reversef(0,i-1);
			cout<<a[i];
			reversef(i+1,len-1);
			return 0;
		}
		if(a[i]=='%'){
			reversef(0,i-1);
			cout<<a[i];
			return 0;
		}
	}
	reversef(0,len-1);
	return 0;
}
