/*
13:将字符串中的小写字母转换成大写字母
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给定一个字符串，将其中所有的小写字母转换成大写字母。

输入
输入一行，包含一个字符串（长度不超过100，可能包含空格）。
输出
输出转换后的字符串。
样例输入
helloworld123Ha
样例输出
HELLOWORLD123HA
*/

#include <stdio.h>
#include <ctype.h> 
#include <string.h>
int main()
{
	int i=0;
	char a[100+10];
	gets(a);
	for(i=0;i<strlen(a);i++){
		if(islower(a[i])) a[i]=toupper(a[i]);
	}
	printf("%s",a);
	return 0;
}
