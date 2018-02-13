/*
14:计算邮资
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
根据邮件的重量和用户是否选择加急计算邮费。计算规则：重量在1000克以内(包括1000克), 基本费8元。超过1000克的部分，每500克加收超重费4元，不足500克部分按500克计算；如果用户选择加急，多收5元。

输入
输入一行，包含整数和一个字符，以一个空格分开，分别表示重量（单位为克）和是否加急。如果字符是y，说明选择加急；如果字符是n，说明不加急。
输出
输出一行，包含一个整数，表示邮费。
样例输入
1200 y
样例输出
17
*/


#include <stdio.h>
int main()
{
	int w,m;
	char c;
	scanf("%d %c",&w,&c);
	if (w>0 && w<=1000) m=8;  
	if (w>1000) { if (w%500==0) m=8+(w/500-2)*4; else m=8+(w/500-1)*4;}
	
	if (c=='y') m+=5;
	printf("%d",m);
	return 0;
}
