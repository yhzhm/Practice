#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>
#include <stack>
#include <limits.h>
using namespace std;
#define MAXN 510

int C, N, i, j, l, r, mid, ans, tx, ty, len;
int tmp[MAXN << 1], s[MAXN << 1][MAXN << 1], x[MAXN], y[MAXN];

inline int getsum(int xa, int ya, int xb, int yb)
{
	return s[xb][yb] - s[xa - 1][yb] - s[xb][ya - 1] + s[xa - 1][ya - 1];
}
inline bool check(int x)
{
	int i, j, tx, ty, pos;
	if (x > tmp[len])
	{
		if (s[len][len] >= C) return true;
		else return false;
	}
	pos = upper_bound(tmp + 1, tmp + len + 1, tmp[len] - x + 1) - tmp - 1;
	for (i = 1; i <= pos; i++)
	{
		for (j = 1; j <= pos; j++)
		{
			tx = upper_bound(tmp + 1, tmp + len + 1, tmp[i] + x - 1) - tmp - 1;
			ty = upper_bound(tmp + 1, tmp + len + 1, tmp[j] + x - 1) - tmp - 1;
			if (getsum(i, j, tx, ty) >= C) return true;
		}
	}
	return false;
}

int main()
{

	scanf("%d%d", &C, &N);
	for (i = 1; i <= N; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		tmp[++len] = x[i];
		tmp[++len] = y[i];
	}
	sort(tmp + 1, tmp + len + 1);
	len = unique(tmp + 1, tmp + len + 1) - tmp - 1;
	for (i = 1; i <= N; i++)
	{
		tx = lower_bound(tmp + 1, tmp + len + 1, x[i]) - tmp;
		ty = lower_bound(tmp + 1, tmp + len + 1, y[i]) - tmp;
		s[tx][ty]++;
	}
	tmp[++len] = 10001;
	for (i = 1; i <= len; i++)
	{
		for (j = 1; j <= len; j++)
		{
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
		}
	}
	l = 1; r = 10000;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (check(mid))
		{
			r = mid - 1;
			ans = mid;
		} else l = mid + 1;
	}
	printf("%d\n", ans);

	return 0;

}