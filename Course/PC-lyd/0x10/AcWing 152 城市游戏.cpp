// Created by Hz Yang on 2019.04
#include <bits/stdc++.h>
using namespace std;
const int M = 1010;
int n, m, h[M][M], s[M], w[M], ans;//h:逐行统计列高度，s[]:单调栈，w[]:记录宽度
char ch[5];//读入字符
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%s", ch);//如果是F,累加高度，否则为高度0（默认值）
			if (ch[0] == 'F') h[i][j] = h[i - 1][j] + 1;
		}
	}

	for (int i = 1; i <= n; ++i) {
		int p = 0;//栈顶位置
		memset(s, 0, sizeof s);
		memset(w, 0, sizeof w);
		for (int j = 1; j <= m + 1; ++j) {//m+1高度为0，避免扫描结束后栈中有剩余高度
			if (h[i][j] > s[p]) s[++p] = h[i][j], w[p] = 1;//维护单调递增栈，若当前高度比栈顶大，直接入栈
			else {//否则，不断弹出栈顶，直至栈为为空或者栈顶的高度比当前高度小
				int width = 0;
				while (s[p] > h[i][j]) {
					width += w[p];//累计弹出矩形的宽度之和
					ans = max(ans, width * s[p]);//每弹出一个矩形，就用它的高度乘上累计的宽度去更新答案
					p--;
				}
				s[++p] = h[i][j], w[p] = width + 1;//整个出栈过程结束后，把高度为当前矩形高度、宽度为累计值的新矩形入栈
			}//整个扫描过程结束后，用h[i][m+1]把栈中剩余矩形依次弹出，同时更新答案
		}
	}
	printf("%d\n", ans * 3);
	return 0;
}