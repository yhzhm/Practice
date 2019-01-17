// Created by Hz Yang on 2018.07
#include <bits/stdc++.h>
using namespace std;
int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}
int cntday(int y, int m, int d)
{
	int sum = 0;
	if (check(y)) mon[2] = 29;
	else mon[2] = 28;
	for (int i = 1; i < m; ++i) {
		sum += mon[i];
	}
	sum += d;
	return sum;
}
int main()
{

	int y1, m1, d1, y2, m2, d2, sum = 0;
	cin >> y1 >> m1 >> d1;
	cin >> y2 >> m2 >> d2;
	for (int i = y1; i < y2; ++i) {
		if (check(i)) sum += 366;
		else sum += 365;
	}
	sum += cntday(y2, m2, d2);
	sum -= cntday(y1, m1, d1);
	cout << sum << endl;
	return 0;
}