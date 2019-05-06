// Created by Hz Yang on 2019.05
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef pair<int, int> PII;
int n;
queue<PII> waits;
set<PII> runs;
priority_queue<PII, vector<PII>, greater<PII>> endts;
int tm, cnt;

bool give(int t, int m, int p)
{
	for (auto it = runs.begin(); it != runs.end(); ++it) {
		auto jt = it; jt++;
		if (jt != runs.end()) {
			if (m <= jt->first - (it->first + it->second ) ) {
				int start = it->first + it->second;
				runs.insert({start, m});
				endts.push({t + p, start});
				return true;
			}
		}
	}
	return false;
}

void finish(int t)
{
	while (endts.size() && endts.top().first <= t) {
		int f = endts.top().first;
		while (endts.size() && endts.top().first == f) {
			auto top = endts.top();
			endts.pop();
			auto it = runs.lower_bound({top.second, 0});
			runs.erase(it);
		}

		tm = f;
		while (waits.size()) {
			auto front = waits.front();
			if (give(f, front.first, front.second)) waits.pop();
			else break;
		}
	}
}

int main()
{
	cin >> n;
	int t, m, p;

	runs.insert({ -1, 1}), runs.insert({n, 1});

	while (cin >> t >> m >> p, t || m || p)
	{
		finish(t);
		if (!give(t, m, p)) {
			waits.push({m, p});
			cnt++;
		}
	}

	finish(2e9);

	cout << tm << endl << cnt << endl;
	return 0;
}