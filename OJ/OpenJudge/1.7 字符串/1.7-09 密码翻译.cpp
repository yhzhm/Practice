/*
09:密码翻译
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
在情报传递过程中，为了防止情报被截获，往往需要对情报用一定的方式加密，简单的加密算法虽然不足以完全避免情报被破译，但仍然能防止情报被轻易的识别。我们给出一种最简的的加密方法，对给定的一个字符串，把其中从a-y，A-Y的字母用其后继字母替代，把z和Z用a和A替代，其他非字母字符不变，则可得到一个简单的加密字符串。

输入
输入一行，包含一个字符串，长度小于80个字符。
输出
输出每行字符串的加密字符串。
样例输入
Hello! How are you!
样例输出
Ifmmp! Ipx bsf zpv!
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	char a[80 + 10];
	int i = 1;
	gets(a);
	for (i = 0; i < strlen(a); i++) {
		if (islower(a[i]) || isupper(a[i])) {
			a[i]++;
			if (a[i] == 91 || a[i] == 123) {
				a[i] -= 26;
			}
		}
	}
	printf("%s", a);
	return 0;
}


// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char a[80 + 10];
// 	int i = 0;
// 	gets(a);
// 	for (i = 0; i < strlen(a); i++) {
// 		if ((a[i] >= 65 && a[i] <= 90) || (a[i] >= 97 && a[i] <= 122)) {
// 			a[i]++;
// 		}
// 		if (a[i] == 91 || a[i] == 123) a[i] = a[i] - 26;
// 	}
// 	puts(a);
// 	return 0;
// }
