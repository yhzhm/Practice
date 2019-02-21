// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
const int M = 5e2 + 10;
int tmp[M << 1], s[M << 1][M << 1], x[M], y[M];
int C, N, len, mid, ans;

int getsum(int xa, int ya, int xb, int yb)//xa,ya左上角坐标，xb,yb右下角坐标，求前缀和求矩形区间和
{
	return s[xb][yb] - s[xa - 1][yb] - s[xb][ya - 1] + s[xa - 1][ya - 1];
}

bool check(int x)//检测正方形边长为x时，和是否>=C
{
	if (x > tmp[len]) {//超过实际最长边，特判
		if (s[len][len] >= C) return true;
		else return false;
	}
	int pos = upper_bound(tmp + 1, tmp + len + 1, tmp[len] - x + 1) - tmp - 1;//边长为x时，无需枚举的位置
	for (int i = 1; i <= pos; ++i)//枚举所有加上x还在范围内的左上角坐标
		for (int j = 1; j <= pos; ++j) {//tx,ty：加上x后的右下角坐标
			int tx = upper_bound(tmp + 1, tmp + len + 1, tmp[i] + x - 1) - tmp - 1;
			int ty = upper_bound(tmp + 1, tmp + len + 1, tmp[j] + x - 1) - tmp - 1;
			if (getsum(i, j, tx, ty) >= C) return true;//判断矩形区间和是否>=C
		}
	return false;
}

int main()
{
	scanf("%d%d", &C, &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d%d", &x[i], &y[i]);//x[],y[]分别保存点的行、列坐标
		tmp[++len] = x[i];//将所有坐标放到一维数组tmp[]中
		tmp[++len] = y[i];
	}
	sort(tmp + 1, tmp + len + 1);//排序、去重、离散化
	len = unique(tmp + 1, tmp + len + 1) - tmp - 1;
	for (int i = 1; i <= N; ++i) {
		int tx = lower_bound(tmp + 1, tmp + len + 1, x[i]) - tmp;
		int ty = lower_bound(tmp + 1, tmp + len + 1, y[i]) - tmp;
		s[tx][ty]++;//统计点上草的数量
	}
	tmp[++len] = 10001;//为check函数中计算pos值服务，保证tmp[len]-x合理
	for (int i = 1; i <= len; ++i) {//计算前缀和
		for (int j = 1; j <= len; ++j) {
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
		}
	}
	int l = 1, r = 10000;//答案范围
	while (l <= r) {//二分，命中时ans=mid
		mid = (l + r) >> 1;
		if (check(mid)) {r = mid - 1; ans = mid;}
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}