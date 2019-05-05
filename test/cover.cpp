#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
PII b[110];
int n, a[110];

int main()
{
	cin >> n;
	for (int i = 1; i < n; ++i) cin >> a[i];//输入n-1个数
	sort(a , a + n);

	for (int i = 1; i < n; ++i) b[i] = {a[i] - a[i - 1], i}; //first:存差值，second:存坐标
	sort(b + 1, b + n  , greater<PII>());//首尾两端不参与排序

	int max = a[n - 1] - b[1].first;//总长减最长的一段
	int i = 2;//找首尾不和最长相连的那段（符合题意的次长）
	while (b[i].second == b[1].second - 1 || b[1].second == b[i].second - 1) i++;
	max = max - b[i].first;//总长减次长

	cout << max << endl;
	return 0;
}