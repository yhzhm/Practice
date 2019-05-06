// Created by Hz Yang on 2019.05
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef pair<int, int> PII;
int n;
queue<PII> waits;    //等待队列，first: 内存长度，second: 占用时间
set<PII> runs;      //当前进程，first: 起始下标，sercond：长度
priority_queue<PII, vector<PII>, greater<PII>> endts; //小根堆，维护释放顺序，first: 释放时间，second: 起始下标
int tm, cnt;//tm:全部进程都运行完毕的时刻,cnt:被放入过等待队列的进程总数

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

/*
数据结构：
1. 等待队列：(内存长度, 占用时间)：queue
2. 内存使用情况：(起始下标，长度)
   线性扫描、删除、插入：set
3. 小根堆：（释放时间key，起始下标），priority_queue

算法流程：
（T,M,P)
1. 释放掉所有 释放时间 <= T 的内存，每次释放之后，都要判断等待队列的队头是否可以满足
2. 判断（T，M，P)是否可以满足，如果不可以，则插入等待队列
*/