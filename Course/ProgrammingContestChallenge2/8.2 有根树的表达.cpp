// Created by Hz Yang on 2018.12
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
const int NIL = -1;
struct Node {int p, l, r;};
Node T[MAX];
int n, D[MAX];

void print(int u)
{
	int i, c;
	cout << "node " << u << ": ";
	cout << "parent = " << T[u].p << ", ";
	cout << "depth = " << D[u] << ", ";

	if (T[u].p == NIL) cout << "root, ";
	else if (T[u].l == NIL) cout << "leaf, ";
	else cout << "internal node, ";

	cout << "[";

	for (i = 0, c = T[u].l; c != NIL; ++i, c = T[c].r) {
		if (i) cout << ", ";
		cout << c;
	}
	cout << "]" << endl;
}
void rec(int u, int p)
{
	D[u] = p;
	if (T[u].r != NIL) rec(T[u].r, p);
	if (T[u].l != NIL) rec(T[u].l, p + 1);
}
int main()
{
	int i, j, d, v, c, l, r;
	cin >> n;
	for (i = 0; i < n; ++i) T[i].p = T[i].l = T[i].r = NIL;
	for (i = 0; i < n; ++i) {
		cin >> v >> d;
		for (j = 0; j < d; ++j) {
			cin >> c;
			if (j == 0) T[v].l = c;
			else T[l].r = c;
			l = c;
			T[c].p = v;
		}
	}
	for (i = 0; i < n; ++i) {
		if (T[i].p == NIL) r = i;
	}
	rec(r, 0);
	for (i = 0; i < n; ++i) print(i);
	return 0;
}

/*input:
13
0 3 1 4 10
1 2 2 3
2 0
3 0
4 3 5 6 7
5 0
6 0
7 2 8 9
8 0
9 0
10 2 11 12
11 0
12 0*/

/*output:
node 0: parent = -1, depth = 0, root, [1, 4, 10]
node 1: parent = 0, depth = 1, internal node, [2, 3]
node 2: parent = 1, depth = 2, leaf, []
node 3: parent = 1, depth = 2, leaf, []
node 4: parent = 0, depth = 1, internal node, [5, 6, 7]
node 5: parent = 4, depth = 2, leaf, []
node 6: parent = 4, depth = 2, leaf, []
node 7: parent = 4, depth = 2, internal node, [8, 9]
node 8: parent = 7, depth = 3, leaf, []
node 9: parent = 7, depth = 3, leaf, []
node 10: parent = 0, depth = 1, internal node, [11, 12]
node 11: parent = 10, depth = 2, leaf, []
node 12: parent = 10, depth = 2, leaf, []
*/