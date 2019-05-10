// Created by Hz Yang on 2019.05
#include <iostream>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PLI;
const int M = 100010;
int n, k, x;
int l[M], r[M];//双向链表
LL d[M], v[M], sum, cnt;

void delete_node(int p)//删除双向链表中的节点p
{
	r[l[p]] = r[p];
	l[r[p]] = l[p];
}

int main()
{
	cin >> n >> k;
	int pos = 0;
	for (int i = 0; i < n; ++i) {//读入时忽略0
		cin >> x;
		if (x) d[++pos] = x;
	}

	n = pos, pos = 1;
	v[1] = d[1];
	for (int i = 2; i <= n; ++i) {//将一段符号相同的数，压缩成一个数
		if (d[i] > 0 && d[i - 1] > 0 || d[i] < 0 && d[i - 1] < 0) v[pos] += d[i];
		else v[++pos] = d[i];
	}

	set<PLI> s;
	int left = 1, right = pos;//若左右端点为负数，则忽略
	if (v[left] < 0) left++;
	if (v[right] < 0) right--;
	v[left - 1] = v[right + 1] = 1e15;//设置哨兵，因为值很大，处理时只取较小值，保证当左右端点被选中后，不会被再次选中
	for (int i = left; i <= right; ++i) {
		l[i] = i - 1;
		r[i] = i + 1;
		if (v[i] > 0) sum += v[i], cnt++;//统计所有正数的和，以及合并后正数的个数
		v[i] = abs(v[i]);
		s.insert({v[i], i});
	}

	while (cnt > k) {//当正数个数大于k时，需要和负数合并（正 负 正）或舍去一个正数（负 正 负），端点时为（正 负 ，负 正）
		auto it = s.begin();
		LL u = it->first;
		int p = it->second;
		left = l[p], right = r[p];

		s.erase(it);//删除当前节点和左右节点
		s.erase({v[left], left}), s.erase({v[right], right});
		delete_node(left), delete_node(right);

		sum -= u;
		v[p] = v[left] + v[right] - v[p];//合并节点
		s.insert({v[p], p});//插入新节点
		cnt--;
	}

	cout << sum << endl;
	return 0;
}