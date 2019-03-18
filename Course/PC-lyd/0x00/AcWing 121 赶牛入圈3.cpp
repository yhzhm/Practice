// Created by Hz Yang on 2019.03
#include <bits/stdc++.h>
using namespace std;
const int M = 1010;
typedef pair<int, int> PII;
int n, C, sum[M][M];//sum[][]用于求离散化后的二维前缀和
PII points[M];//用于保存点坐标
vector<int> numbers;//用于离散化点坐标

int get(int x)//二分求当前点在numbers中的下标
{
	/*int l = 0, r = numbers.size() - 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (numbers[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r;*/
	return lower_bound(numbers.begin(), numbers.end(), x) - numbers.begin();
}

bool check(int len)
{
	for (int x1 = 0, x2 = 1; x2 < numbers.size(); x2++) {//将x2，x1的草都包含的话，长度是numbers[x2]-numbers[x1]+1
		while (numbers[x2] - numbers[x1 + 1] + 1 > len) x1++;//如果下一个位置不能包含进来的话（不在len范围内），则需要考x1++
		for (int y1 = 0, y2 = 1; y2 < numbers.size(); y2++) {
			while (numbers[y2] - numbers[y1 + 1] + 1 > len) y1++;
			if (sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1] >= C)
				return true;
		}
	}
	return false;
}

int main()
{
	cin >> C >> n;
	numbers.push_back(0);//先放1个零，方便后面做前缀和（sum[x][y],x,y的值（坐标在numbers中的下标）最小从1开始）
	for (int i = 0; i < n; ++i) {//读入点坐标
		int x, y;
		cin >> x >> y;
		points[i] = {x, y};
		numbers.push_back(x);//将横坐标和纵坐标都存储到vector<int> numbers中
		numbers.push_back(y);
	}

	sort(numbers.begin(), numbers.end());//排序
	numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());//去重，unique第一个重复数据的指针

	for (int i = 0; i < n; ++i) {//依次处理n个点
		int x = get(points[i].first), y = get(points[i].second);//得到当前点在numbers中的下标
		sum[x][y]++;//统计草的数量，x，y为离散化后的numbers中的下标
	}

	for (int i = 1; i < numbers.size(); ++i)
		for (int j = 1; j < numbers.size(); ++j)
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];//求二维前缀和

	int l = 1, r = 10000;//二分正方形边长len
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}

	cout << r << endl;
	return 0;
}