/* 
14:大小写字母互换
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
把一个字符串中所有出现的大写字母都替换成小写字母，同时把小写字母替换成大写字母。

输入
输入一行：待互换的字符串。
输出
输出一行：完成互换的字符串（字符串长度小于80）。
样例输入
If so, you already have a Google Account. You can sign in on the right. 
样例输出
iF SO, YOU ALREADY HAVE A gOOGLE aCCOUNT. yOU CAN SIGN IN ON THE RIGHT.
*/

#include <stdio.h>
#include <ctype.h> 
#include <string.h>
int main()
{
	int i=0;
	char a[80+10];
	gets(a);
	for(i=0;i<strlen(a);i++){
		if(islower(a[i])) a[i]=toupper(a[i]);
		else if(isupper(a[i])) a[i]=tolower(a[i]);
	}
	printf("%s",a);
	return 0;
}
