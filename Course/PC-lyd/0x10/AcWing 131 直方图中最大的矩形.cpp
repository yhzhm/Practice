// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
int n, p, a[M], s[M], w[M];//a[]输入数据，s[]单调栈,w[]记录矩形宽度
long long ans;
int main()
{
	while (cin >> n && n) {
		ans = p = 0;
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		a[n + 1] = 0;//增加一个高度为0的矩形，避免扫描结束后，栈中有剩余矩形
		for (int i = 1; i <= n + 1; ++i) {
			if (a[i] > s[p]) s[++p] = a[i], w[p] = 1;//如果当前矩形比栈顶矩形高，直接进栈
			else {
				int width = 0;
				while (s[p] > a[i]) {//不断取出栈顶，直至栈为为空或者栈顶矩形的高度比当前矩形小
					width += w[p];//累计弹出矩形的宽度之和
					ans = max(ans, 1ll * width * s[p]);//每弹出一个矩形，就用它的高度乘上累计的宽度去更新答案
					p--;
				}
				s[++p] = a[i], w[p] = width + 1;//整个出栈过程结束后，把高度为当前矩形高度、宽度为累计值的新矩形入栈
			}//整个扫描过程结束后，用a[n+1]把栈中剩余矩形依次弹出，同时更新答案
		}
		printf("%lld\n", ans);
	}
	return 0;
}