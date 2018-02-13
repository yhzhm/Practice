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
	bool flag=false;
	for(int i=to;i>=fro;i--){
		if(!flag&&a[i]=='0') continue;
		else flag=true;
		if(flag) cout<<a[i];
	}
	if(!flag) cout<<"0";
}
void reverseb(int fro,int to)
{
	bool is_ok=false;
	for(int i=fro;i<=to;i++){
		if(a[i]!='0'){
			fro=i;
			is_ok=true;
			break;
		} 
	}
	if(is_ok==false){
		cout<<"0";
		return;
	} 
	else {
		for(int i=to;i>=fro;i--)
			cout<<a[i];
	}
	
}
int main()
{
	cin>>a;
	len=strlen(a);
//	printf("%d",n);
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
			cout<<"%";
			return 0;
		}
	}
	reversef(0,len-1);
	return 0;
}
