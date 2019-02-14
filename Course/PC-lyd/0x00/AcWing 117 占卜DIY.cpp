// Created by Hz Yang on 2019.02
#include <bits/stdc++.h>
using namespace std;
deque<int> q[15];//为了上下取牌方便，用双端队列
int mp[13];//记录正面朝上的牌数
int b[128], cnt;//b[]用于hash输入字母
int main()
{
	char c;	int x;
	b['A'] = 1, b['J'] = 11, b['Q'] = 12, b['K'] = 13;
	for (int i = 1; i <= 13; ++i)
		for (int j = 1; j <= 4; ++j) {//注意每堆的输入顺序为从上到下
			cin >> c;
			if (isdigit(c)) {
				x = c - 48;
				x = x ? x : 10;
			}
			else x = b[(int)c];
			q[i].push_back(x);//front为上，back为下
		}
	//开始模拟
	while (!q[13].empty()) {
		int val = q[13].front();//从最后一堆的最上一张牌开始
		q[13].pop_front();
		while (val != 13 ) {
			q[val].push_front(val);//放在val堆的上面
			mp[val]++;//统计
			int temp = q[val].back();//从val堆的底下取牌
			q[val].pop_back();
			val = temp;
		}
	}

	for (int i = 1; i <= 12; ++i) cnt += (mp[i] == 4);
	cout << cnt << endl;
	return 0;
}
/*
坑：
1.调试输出时，将队列清空，导致后续无操作
2.未仔细读题，搞错每堆牌的存储顺序，程序写错最后一堆牌的取牌顺序
过度：
用pair<int,bool>存储牌信息，标记是否已翻其实并不需要。
用map<int,int>统计结果，可用数组代替。
 */