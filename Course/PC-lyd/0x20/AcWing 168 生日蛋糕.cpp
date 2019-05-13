#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
int N, M, ans;
int minv[25], mins[25];

void dfs(int r, int h, int layer, int v, int s) {
	if (layer == 0) {
		if (v == N && ans > s) ans = s;	return;
	}
	if (N - v < minv[layer]) return; //剪枝1
	if (ans - s < mins[layer]) return; //剪枝2
	if (s + 2 * (N - v) / r > ans) return; //剪枝3
	int i, j;
	for (i = r; i >= layer; i--) {
		if (layer == M) s = i * i; //第一次要加上底面的面积
		int maxh = min(h, (N - v - minv[layer - 1]) / i / i); //本层高度最高的情况，不能高过最高高度h
		for (j = maxh; j >= layer; j--) {
			dfs(i - 1, j - 1, layer - 1, v + i * i * j, s + 2 * i * j);
		}
	}
}
int main() {
	int i;
	minv[0] = mins[0] = 0;
	for (i = 1; i <= 20; i++) {
		minv[i] = minv[i - 1] + i * i * i;
		mins[i] = mins[i - 1] + 2 * i * i;
	}
	while (~scanf("%d %d", &N, &M)) {
		ans = INT_MAX;
		dfs((int)sqrt(N), N, M, 0, 0);
		if (ans == INT_MAX) printf("0\n");
		else printf("%d\n", ans);
	}
	return 0;
}

/*
剪枝1：总体积减去蛋糕当前层以下的层的总体积，小于上面的层所能构成的最小体积
剪枝2：当前得到的最优解减去蛋糕当前层以下的层的总面积，小于上面的层所能构成的最小面积
剪枝3：2 * （N - v) / r 表示剩下的体积能组成最小面积的极限情况，
可以证明，同样的体积组成一个大圆柱体和组成多个比一个大圆柱体小的小圆柱体相比，
前者的表面积比后者要小，所以这种表面积最小的情况再加上本层以下的确定的表面积s
如果是大于已知最优解s，那么最终结果一定不会比ans小，返回 。（难理解）
 */