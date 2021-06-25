#include <iostream>
using namespace std;

typedef long long LL;

int T, n;

int main()
{
	cin >> T;
	while (T --)
	{
		cin >> n;
		LL s = 0; int x;
		for (int i = 0; i < n; i ++ )
		{
			cin >> x;
			s = (s << 1) + x;
		}
		cout << (s & 1) << endl;
		while ((s & 1) == 0) s /= 2;
		cout << s << '\n';
		int cnt = 0;
		while (s)
		{
			if (s % 2 == 0) cnt++;
			s >>= 1;
			cout << s << '\n';
		}
		cout << cnt << endl;
	}
}