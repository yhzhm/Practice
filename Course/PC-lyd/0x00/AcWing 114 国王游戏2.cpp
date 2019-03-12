// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1e3 + 10;
typedef pair<int, int> PII;
PII p[M];//存储每个人的左手值和右手值
int n;

vector<int> mul(vector<int> a, int b)//高精度乘以一个整数
{
	vector<int> c;//保存结果
	int t = 0;
	for (int i = 0; i < a.size(); ++i) {
		t += a[i] * b;//加上进位
		c.push_back(t % 10);
		t /= 10;
	}
	while (t) c.push_back(t % 10), t /= 10;
	return c;
}

vector<int> div(vector<int> a, int b)//高精度除以一个整数
{
	vector<int> c;
	bool is_first = false;//用以区分前导零和中间零
	for (int i = a.size() - 1, t = 0; i >= 0; --i) {//高位开始除
		t = t * 10 + a[i];
		int x = t / b;
		if (x || is_first) {
			is_first = true;
			c.push_back(x);
		}
		t %= b;
	}
	return vector<int>(c.rbegin(), c.rend());//逆序输出
}

vector<int> max_vec(vector<int> a, vector<int> b)//vector默认是字典序比较，因为逆序，所以需要自定义max
{
	if (a.size() > b.size()) return a;
	if (a.size() < b.size()) return b;
	if (vector<int>(a.rbegin(), a.rend()) > vector<int>(b.rbegin(), b.rend())) return a;
	return b;
}

void output(vector<int> a)//逆序输出结果
{
	for (int i = a.size() - 1; i >= 0; --i) cout << a[i];
	cout << endl;
}

int main()
{
	cin >> n;
	for (int i = 0; i <= n; ++i) {
		int a, b;
		cin >> a >> b;
		p[i] = {a * b, a};//以左右手乘积排序
	}
	sort(p + 1, p + n + 1);

	vector<int> product(1, 1);//乘积
	vector<int> res(1, 0);//结果
	for (int i = 0; i <= n; ++i) {
		if (i) res = max_vec(res, div(product, p[i].first / p[i].second));//计算、比较每个人的奖励
		product = mul(product, p[i].second);//累乘
	}

	output(res);
	return 0;
}