// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 10;
int trie[M][26], ed[M], n, m, tot = 1;
char s[M];

void insert(char* s)//插入一个字符串
{
	int len = strlen(s), p = 1;//p指向根节点
	for (int k = 0; k < len; ++k) {
		int ch = s[k] - 'a';
		if (trie[p][ch] == 0) trie[p][ch] = ++tot;//若p的ch字符指针指向空，则新建一个节点Q,P指向Q
		p = trie[p][ch];//令P=Q
	}
	ed[p]++;//扫描完毕，在当前节点P上标记它是一个字符串的末尾
}

int search(char* s)//检索s在Trie中是否存在
{
	int len = strlen(s), p = 1, res = 0;
	for (int k = 0; k < len; ++k) {//依次扫描S中的每个字符
		p = trie[p][s[k] - 'a'];
		if (p == 0) return res;//若P指向空，则说明S没有被插入过，结束检索
		res += ed[p];//若是末尾节点，累加字符串个数(可能插入重复字符串，所以要记录个数，而不能只做末尾标记)
	}
	return res;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s);
		insert(s);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%s", s);
		printf("%d\n", search(s));
	}
	return 0;
}

/*
初始化
一棵空Trie仅包含一个根节点，该点的字符指针均指向空。
插入
当需要插入一个字符串s时，我们令一个指针p指向根节点。然后依次扫描s中的每个字符：
1.若p的c字符指针指向一个已经存在的节点q，则令p=q。
2.若p的c字符指针指向空，则新建一个节点q，令p的c字符指针指向q，然后令p=q。
当s中的字符扫描完毕时，在当前节点p上标记它是一个字符串的末尾。
检索
当需要检索一个字符串s在Trie中是否存在时，我们令一个指针p起初指向根节点，然后依次扫描s中的每个字符c：
1.若p的c字符指针指向空，则说明s没有被插入过Trie，结束检索。
2.若p的c字符指针指向一个已经存在的节点q，则令p=q。
当s中的字符扫描完毕时，若当前节点的p被标记为一个字符串的末尾，则说明s在Trie中存在，否则说明s没有被插入过Trie

Trie的每个节点具有26个字符指针，分别为a~z.


 */