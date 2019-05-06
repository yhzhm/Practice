// Created by Hz Yang on 2019.05
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string dfs(string &seq, int &u)
{
    vector<string> seqs;
    u++;
    while (seq[u] == '0') seqs.push_back(dfs(seq, u));
    u++;

    sort(seqs.begin(), seqs.end());
    string res = "0";
    for (auto s : seqs) res += s;
    res += '1';
    return res;
}

int main()
{
    int T;
    cin >> T;
    while (T --) {
        string a, b;
        cin >> a >> b;
        a = '0' + a + '1';
        b = '0' + b + '1';
        int ua = 0, ub = 0;
        string sa = dfs(a, ua), sb = dfs(b, ub);
        cout << sa << endl;
        cout << sb << endl;
        if (sa == sb) puts("same");
        else puts("different");
    }
    return 0;
}