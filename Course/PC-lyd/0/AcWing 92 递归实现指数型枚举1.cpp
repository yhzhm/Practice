// Created by Hz Yang on 2019.01
#include <bits/stdc++.h>
using namespace std;
vector<int> chosen;
int n;
void calc(int x) {
	if (x == n + 1) {
		for (int i = 0; i < chosen.size(); ++i) printf("%d ", chosen[i]);
		printf("\n");
		return;
	}
	//"不选x"分枝
	calc(x + 1);
	//"选x"分枝
	chosen.push_back(x);
	calc(x + 1);
	chosen.pop_back();
}
int main()
{
	cin >> n;
	calc(1);
	return 0;
}