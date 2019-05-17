// Created by Hz Yang on 2019.05
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> ans;
int n, k;

void dfs(vector<int> &path, int start, int k)
{
	if (!k) {
		ans.push_back(path);
		return;
	}

	for (int i = start; i <= n; ++i) {
		path.push_back(i);
		dfs(path, i + 1, k - 1);
		path.pop_back();
	}
}

int main()
{
	cin >> n >> k;
	vector<int> path;
	dfs(path, 1, k);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}