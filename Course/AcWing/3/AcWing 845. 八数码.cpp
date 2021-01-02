#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
#include <queue>
using namespace std;
const string ed = "12345678x";

unordered_map<string, int> h;
queue<string> q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
	string s = "", x;
	for (int i = 0 ; i < 9 ; i++ ) cin >> x, s += x;

	q.push(s);
	h[s] = 0;

	while (q.size()) {
		auto t = q.front(); q.pop();
		int pos = t.find('x'); //找到x位置，并计算对应x,y坐标
		int x = pos / 3;
		int y = pos % 3;
		for (int i = 0 ; i < 4 ; i++) {
			int a = x + dx[i];  //下一步坐标
			int b = y + dy[i];
			if (a >= 0 && a < 3 && b >= 0 && b < 3) {
				string st = t;
				swap(st[a * 3 + b], st[x * 3 + y]); //移动x
				if (!h.count(st)) {
					q.push(st);
					h[st] = h[t] + 1;
					if (st == ed) {
						cout << h[st] << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
