/*
10:简单密码
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Julius Caesar曾经使用过一种很简单的密码。对于明文中的每个字符，将它用它字母表中后5位对应的字符来代替，这样就得到了密文。比如字符A用F来代替。如下是密文和明文中字符的对应关系。

密文
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

明文
V W X Y Z A B C D E F G H I J K L M N O P Q R S T U

你的任务是对给定的密文进行解密得到明文。

你需要注意的是，密文中出现的字母都是大写字母。密文中也包括非字母的字符，对这些字符不用进行解码。

输入
一行，给出密文，密文不为空，而且其中的字符数不超过200。
输出
输出一行，即密文对应的明文。
样例输入
NS BFW, JAJSYX TK NRUTWYFSHJ FWJ YMJ WJXZQY TK YWNANFQ HFZXJX
样例输出
IN WAR, EVENTS OF IMPORTANCE ARE THE RESULT OF TRIVIAL CAUSES
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char change(char x)
{
	if (islower(x)) return (x - 'a' - 5 + 26) % 26 + 'a'; // 前移要加26，负数取模会出错
	if (isupper(x)) return (x - 'A' - 5 + 26) % 26 + 'A';
	return x;
}
int main()
{
	int n, i;
	char a[300];
	gets(a);
	for (i = 0; i < strlen(a); ++i)
		cout << change(a[i]);
	return 0;
}

