/*
==========================
��ʵ�������Ҫ����������⡣
��������
�����0��Ҫ
������0����000000000000��ֻ���0

����С��
С����ǰ�������������0��Ҫ
С������������ǰ���0��Ҫ
������0����000000000000��ֻ���0
С�������ȷ���

���ڷ���
����ǰ�������������0��Ҫ
������������������0��Ҫ
������0����000000000000��ֻ���0
��������ȷ���

���ڰٷ���
�ٷ���ǰ�������������0��Ҫ
������0����000000000000��ֻ���0
�ٷֺŵ���ȷ���
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
