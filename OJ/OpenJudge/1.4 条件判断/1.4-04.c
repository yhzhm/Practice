/*
04:奇偶ASCII值判断
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
任意输入一个字符，判断其ASCII是否是奇数，若是，输出YES，否则，输出NO 
例如，字符A的ASCII值是65，则输出YES，若输入字符B(ASCII值是66)，则输出NO

输入
输入一个字符
输出
如果其ASCII值为奇数，则输出YES，否则，输出NO
样例输入
A
样例输出
YES
*/

#include <stdio.h>
int main()
{
	char c;
	int a;
	scanf("%c", &c);
	a=c;
	if (a%2==1) printf("YES");
	else printf("NO");		
	return 0;
}
