// Created by Hz Yang on 2019.06
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int M = 100010;
int h[M], ph[M], hp[M], size, n, m;

void heap_swap(int a, int b)
{
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}

void down(int u)
{
	int t = u;
	if (u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
	if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
	if (u != t) heap_swap(u, t), down(t);
}

void up(int u)
{
	while (u / 2 && h[u] < h[u / 2]) {
		heap_swap(u, u / 2);
		u /= 2;
	}
}

int main()
{
	scanf("%d", &n);
	while (n --) {
		char op[5]; int k, x;
		scanf("%s", op);
		if (!strcmp(op, "I")) {
			scanf("%d", &x);
			size++, m++;
			ph[m] = size, hp[size] = m;
			h[size] = x;
			up(size);
		}
		else if (!strcmp(op, "PM")) printf("%d\n", h[1]);
		else if (!strcmp(op, "DM")) {
			heap_swap(1, size);
			size --;
			down(1);
		}
		else if (!strcmp(op, "D")) {
			scanf("%d", &k);
			k = ph[k];
			heap_swap(k, size);
			size--;
			up(k), down(k);
		}
		else {
			scanf("%d%d", &k, &x);
			k = ph[k];
			h[k] = x;
			up(k), down(k);
		}
	}
	return 0;
}