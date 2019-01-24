一般写二分的思考顺序是这样的：
首先通过题目背景和check(mid)函数的逻辑，判断答案落在左半区间还是右半区间。
左右半区间的划分方式一共有两种：

中点mid属于左半区间，则左半区间是[l, mid]，右半区间是[mid + 1, r]，
更新方式是r = mid; 或者 l = mid + 1; ，此时用第一个模板；

中点mid属于右半区间，则左半区间是[l, mid - 1]，右半区间是[mid, r]，
更新方式是r = mid - 1; 或者 l = mid; ，此时用第二个模板；

二分模板一共有两个，分别适用于不同情况。
算法思路：假设目标值在闭区间[l, r]中， 每次将区间长度缩小一半，当l = r时，我们就找到了目标值。

        版本1
        当区间[l, r]的更新操作是r = mid; l = mid + 1; 时，计算mid时不需要加1。

C++ 代码模板：
int bsearch_1(int l, int r)
{
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}
版本2
当区间[l, r]的更新操作是r = mid - 1; l = mid; 时，计算mid时需要加1。

C++ 代码模板：
int bsearch_2(int l, int r)
{
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	return l;
}

